/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomWASMDefinitions.cpp
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#include "AtomCAPI.h"

#if ATOM_SYSTEM_OS_WASM

ATOM_JS_ASYNC(void, atom_sleep, (Auint32 ms), {
 	await new Promise(resolve => setTimeout(resolve, ms));
});

ATOM_JS(ATOM_TICK, atom_get_now, (), {
	return Atom.atom_get_now();
});

ATOM_JS(void, atom_clear_console, (), {
	console.clear();
});

ATOM_JS(void, atom_application_init, (), {
	Module["dynCall_iii"];Module["dynCall_ii"];Module["dynCall_v"];
	Module["dynCall_vi"];Module["dynCall_vii"];Module["dynCall_iiii"];
	Module["dynCall_viijii"];Module["dynCall_viiii"];Module["dynCall_jiji"];
	Module["dynCall_iidiiii"];Module["dynCall_iiiii"];Module["dynCall_iiiiii"];
	Module["dynCall_iiiiiiiii"];Module["dynCall_iiiiiii"];Module["dynCall_iiiiij"];
	Module["dynCall_iiiiid"];Module["dynCall_iiiiijj"];Module["dynCall_iiiiiiii"];
	Module["dynCall_iiiiiijj"];Module["dynCall_viiiiii"];Module["dynCall_viiiii"];

	self.Atom = Module;

	Atom.ATOM_MAIN_SCRIPT_PATH = Atom.ATOM_MAIN_SCRIPT_PATH || null;
	Atom.ATOM_WORKER_SCRIPT_PATH = Atom.ATOM_WORKER_SCRIPT_PATH || null;
	Atom.ATOM_MULTI_THREAD_ENABLED = Atom.ATOM_MULTI_THREAD_ENABLED || false;
	Atom.ATOM_PROCESS_NAME = Atom.ATOM_PROCESS_NAME || "main";
	Atom.ATOM_FUNCTION_POINTER_SIZE = Atom.ATOM_FUNCTION_POINTER_SIZE || Module.getNativeTypeSize("*") || 8;
	
	Atom.AtomApplicationInitialized = true;

	const IsInsideWorker = ENVIRONMENT_IS_WORKER;

	const MAX_INT = 1410065406;

	Atom.AtomElements = {};
	Atom.ChildProcesses = {};
	Atom.ThreadPromises = {};
	Atom.SharedFunctions = {};
	Atom.SharedMemories = {};
	Atom.YieldPromise = null;
	Atom.Animations = {};

	Atom.AnimationsOffset = 1;

	if (!IsInsideWorker && self.document) {
		const script = document.querySelector('script[atom_main]');

		var terminate = false;

		if (script) {
			Atom.ATOM_MAIN_SCRIPT_PATH = script.src;

			if (!Atom.ATOM_MAIN_SCRIPT_PATH) {
				terminate = true;
			}

			Atom.ATOM_WORKER_SCRIPT_PATH = script.getAttribute("atom_worker");
			if (Atom.ATOM_WORKER_SCRIPT_PATH && Atom.ATOM_WORKER_SCRIPT_PATH.length > 0) {
				Atom.ATOM_MULTI_THREAD_ENABLED = true;
			}
		}else{
			terminate = true;
		}

		if (terminate) {
			throw Error("Couldn't find Atom Main script. You have to add `atom_main` attribute to your script element. (example:\n<script src=\"script.js\" atom_main />\n)");
		}

		Atom.AtomElements[1] = document.head;
		Atom.AtomElements[2] = document.body;
	}

	Atom.AtomElementsOffset = 3;
	
	Atom.AtomFunctions = {};

	Atom.TempValue = 0;

	self.NULL = 0;
	Atom.NULL = 0;

	Atom.AtomSelectedRenderTarget = NULL;
	Atom.MotherCanvasContext = self.document ? document.createElement("canvas").getContext("2d") : NULL;

	Atom.AtomCustomRatio = 0;

	function atom_get_now() {
		return performance.now();
	}

	function atom_get_main_script_path() {
		return Atom.ATOM_MAIN_SCRIPT_PATH;
	}

	function atom_get_worker_script_path() {
		return Atom.ATOM_WORKER_SCRIPT_PATH;
	}

	function atom_is_multi_thread_enabled() {
		return Atom.ATOM_MULTI_THREAD_ENABLED;
	}

	function atom_is_inside_worker() {
		return IsInsideWorker;
	}

	function atom_dynamic_call(pointer, ...args) {
		const caller = wasmTable.get(pointer);

		if (!caller) {
			return;
		}

		return caller(...args);
	}

	function atom_find_signature_caller(signature) {
		const caller = Module[`dynCall_${signature}`];
		
		return caller;
	}

	function atom_signature_call(signature, pointer, ...args) {
		const caller = Atom.atom_find_signature_caller(signature);

		if (caller) {
			return caller(pointer, ...args);
		}
	}

	function atom_create_element_reference(element) {
		if (!Atom.atom_is_main_process()) {
			return;
		}

		var offset = Atom.AtomElementsOffset;

		if (offset > MAX_INT) {
			offset = 3;
		}

		while (Atom.AtomElements[offset]) offset++;

		const ref = offset++;

		Atom.AtomElements[ref] = element;

		Atom.AtomElementsOffset = offset;

		return ref;
	}

	function atom_get_element_by_reference(reference) {
		return Atom.AtomElements[reference];
	}

	function atom_create_element(type, namespace) {
		if (typeof type != "string" || type.length < 1) {
			return;
		}

		var element;

		if (typeof namespace == "string" && namespace.length > 0) {
			element = document.createElementNS(namespace, type);
		}else{
			element = document.createElement(type);
		}

		return Atom.atom_create_element_reference(element);
	}

	function atom_element_exists(element) {
		return Atom.AtomElements[element] ? true : false;
	}

	function atom_remove_element_reference(element) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		delete Atom.AtomElements[element];
	}

	function atom_destroy_element(element) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		const elm = Atom.AtomElements[element];
		if (elm) {
			elm.remove();
		}

		Atom.atom_remove_element_reference(element);
	}

	function atom_is_same_element(element, target) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		if (!Atom.atom_element_exists(target)) {
			return;
		}

		element = Atom.AtomElements[element];
		target = Atom.AtomElements[target];

		return element == target;
	}

	function atom_set_element_attribute(element, attribute, value) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			element.setAttribute(attribute, value);
		}
	}

	function atom_get_element_attribute(element, attribute) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			return element.getAttribute(element, attribute);
		}
	}

	function atom_has_element_attribute(element, attribute) {
		if (!Atom.atom_element_exists(element)) {
			return false;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			return element.hasAttribute(attribute);
		}

		return false;
	}

	function atom_remove_element_attribute(element, attribute) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			element.removeAttribute(attribute);
		}
	}

	function atom_toggle_element_attribute(element, attribute) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			element.toggleAttribute(attribute);
		}
	}

	function atom_set_element_property(element, property, value) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			element[property] = value;
		}
	}

	function atom_get_element_property(element, property) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			var prop = element[property];
			
			if (typeof prop == "string") {
				return prop;
			}

			return prop.toString();
		}
	}

	function atom_element_append_child(element, child) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}
		if (!Atom.atom_element_exists(child)) {
			return;
		}

		element = Atom.AtomElements[element];
		child = Atom.AtomElements[child];

		if (element && child) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			if (child.IS_RENDER_TARGET) {
				child = child.canvas;
			}

			element.appendChild(child);
		}
	}

	function atom_set_element_style(element, property, value) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			element.style.setProperty(property, value);
		}
	}

	function atom_get_element_style(element, property) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			return element.style.getPropertyValue(property);
		}
	}
	
	function atom_get_element_bounding_box_bytes(element) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			const box = element.getBoundingClientRect();
			
			const data = new Float64Array([
				box.x,
				box.y,
				box.width,
				box.height,
				box.left,
				box.top,
				box.right,
				box.bottom
			]);

			return data.buffer;
		}
	}

	function atom_query_selector(element, query) {
		if (element == NULL) {
			element = document;
		}else{
			if (!Atom.atom_element_exists(element)) {
				return;
			}

			element = Module.AtomElements[element];
			
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}
		}

		if (element) {
			const selected = element.querySelector(query);
			if (selected) {
				return Atom.atom_create_element_reference(selected);
			}
		}
	}

	function atom_query_selector_all(element, query) {
		if (!element || element == NULL) {
			element = document;
		}else{
			if (!Atom.atom_element_exists(element)) {
				return;
			}

			element = Module.AtomElements[element];
			
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}
		}

		if (element) {
			const list = element.querySelectorAll(query);
			if (list && list.length > 0) {
				const elements = [];
				
				for (const selected of list) {
					elements.push(Atom.atom_create_element_reference(selected));
				}

				return elements;
			}
		}
	}

	function atom_add_element_class(element, className) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			if (element.classList.contains(className)) {
				return;
			}

			element.classList.add(className);
		}
	}

	function atom_element_class_exists(element, className) {
		if (!Atom.atom_element_exists(element)) {
			return false;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			return element.classList.contains(className);
		}
	}

	function atom_remove_element_class(element, className) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			if (!element.classList.contains(className)) {
				return;
			}

			element.classList.remove(className);
		}
	}

	function atom_get_element_node_name(element) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			return element.nodeName;
		}
	}

	function atom_get_element_parent(element) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (element) {
			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}

			const parent = element.parentElement;

			return Atom.atom_create_element_reference(parent);
		}
	}

	function atom_get_element_child_count(element) {
		if (!Atom.atom_element_exists(element)) {
			return 0;
		}

		element = Atom.AtomElements[element];
		if (!element) {
			return 0;
		}

		if (element.IS_RENDER_TARGET) {
			element = element.canvas;
		}

		return element.childElementCount;
	}

	function atom_scroll_to_element(element, viewType) {
		if (!Atom.atom_element_exists(element)) {
			return;
		}

		element = Atom.AtomElements[element];
		if (!element) {
			return;
		}

		if (element.IS_RENDER_TARGET) {
			element = element.canvas;
		}

		element.scrollIntoView(viewType);
	}

	function atom_add_event_listener(element, eventName, handler) {
		if (typeof element == "string") {
			handler = eventName;
			eventName = element;
			element = self;
		}else{
			if (!Atom.atom_element_exists(element)) {
				return;
			}

			element = Atom.AtomElements[element];

			if (element.IS_RENDER_TARGET) {
				element = element.canvas;
			}
		}

		if (typeof eventName != "string" || typeof handler != "function") {
			return;
		}

		element.addEventListener(eventName, handler);
	}

	function atom_set_temp_value(value) {
		Atom.TempValue = value;
	}

	function atom_register_function(name, handler) {
		name = typeof name == "number" ? UTF8ToString(name) : name;

		if (name && name.length > 0) {
			if (!Atom.AtomFunctions[name]) {
				Atom.AtomFunctions[name] = { pointer : handler, caller : wasmTable.get(handler) };
			}
		}
	}

	function atom_is_function_registered(name) {
		if (name && name.length > 0) {
			return Atom.AtomFunctions[name] ? true : false;
		}

		return false;
	}

	function atom_unregister_function(name) {
		if (!Atom.atom_is_function_registered(name)) {
			return;
		}

		Atom.AtomFunctions[name] = undefined;
		delete Atom.AtomFunctions[name];
	}

	function atom_get_function_pointer(name) {
		if (!Atom.atom_is_function_registered(name)) {
			return NULL;
		}

		return Atom.AtomFunctions[name].pointer;
	}

	function atom_get_function(name, signature) {
		if (!Atom.atom_is_function_registered(name)) {
			return;
		}

		if (signature == "asm") {
			return Atom.AtomFunctions[name].caller;
		}

		const functionPointer = Atom.atom_get_function_pointer(name);

		var caller;

		if (typeof signature == "string" && signature.length > 0) {
			caller = Atom.atom_find_signature_caller(signature);
		}else{
			caller = Atom.atom_dynamic_call;
		}

		if (!caller) {
			return;
		}

		return function(...args) {
			return caller(functionPointer, ...args);
		}
	}

	function atom_to_pointer(value) {
		if (typeof value == "string") {
			var size = lengthBytesUTF8(value);

			const textBuffer = (new TextEncoder).encode(value);

			const buffer = new Uint8Array(size + 1);
			buffer.set(textBuffer);
			buffer[size] = 0;

			var pointer = _malloc(size + 1);

			var heap = new Uint8Array(HEAPU8.buffer, pointer, size + 1);
			heap.set(buffer);

			return pointer;
		}else if (
			value instanceof Int8Array ||
			value instanceof Uint8Array ||
			value instanceof Int16Array ||
			value instanceof Uint16Array ||
			value instanceof Int32Array ||
			value instanceof Uint32Array ||
			value instanceof BigInt64Array ||
			value instanceof BigUint64Array ||
			value instanceof Float32Array ||
			value instanceof Float64Array
		) {
			var size = value.byteLength;

			var pointer = _malloc(size);

			var heap = new Uint8Array(HEAPU8.buffer, pointer, size);
			heap.set(new Uint8Array(value.buffer));

			return pointer;
		}else if (typeof value == "function") {
			var pointer = _malloc(Atom.ATOM_FUNCTION_POINTER_SIZE);

			wasmTable.set(pointer, value);

			return pointer;
		}

		return NULL;
	}

	function atom_generage_random_key(count = 15) {
		const characters = "abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()_+{}[];',.";
		const charLength = characters.length;

		var key = "";

		for (var i = 0; i < count; i++) {
			const index = Math.floor(Math.random() * 10);
			key += characters[index];
		}
		
		return key;
	}

	function atom_get_process_name() {
		return Atom.ATOM_PROCESS_NAME;
	}

	function atom_is_main_process() {
		return !Atom.atom_is_inside_worker();
	}

 	async function _atom_handle_process_message(e) {
		const data = e.data;
		const cmd = data.command;
		const processName = data.processName;
		const fromProcess = data.fromProcess;
		const key = data.key;
		const functionName = data.functionName;
		const functionArgs = data.functionArgs;
		const message = data.message;

		if (cmd == "terminate") {
			Atom.atom_terminate_child_process(processName);
		}else if (cmd == "ready") {
			Atom.ChildProcesses[processName].ready = true;
		}else if (cmd == "alert") {
			alert(message);
		}else if (cmd == "post") {
			Atom.atom_post_child_process(processName, message);
		}else if (cmd == "resume") {
			if (processName == Atom.atom_get_process_name()) {
				const resolver = Atom.YieldPromise;
				if (resolver) {
					resolver(data.result);
				}
			}else{
				Atom.atom_post_child_process(processName, {
					command : cmd,
					processName,
					fromProcess,
					result : data.result
				});
			}
		}else if (cmd == "calln" || cmd == "callm") {
			if (processName == Atom.atom_get_process_name()) {
				var result = undefined;

				const func = (cmd == "callm" ? Module : Atom)[functionName];
				if (typeof func == "function") {
					const promise = func.apply(null, functionArgs);
					
					if (!data.dontWait) {
						result = await promise;
					}else{
						result = promise;
					}
				}
				
				if (data.dontWait) {
					return;
				}
				
				if (fromProcess == processName) await Atom.atom_sleep(0);

				Atom.atom_post_child_process(fromProcess, {
					command : "result",
					processName : fromProcess,
					fromProcess : processName,
					key,
					result
				});
			}else{
				Atom.atom_post_child_process(processName, {
					command : cmd,
					processName,
					fromProcess,
					key,
					functionName,
					functionArgs
				});
			}
		}else if (cmd == "result") {
			if (processName == Atom.atom_get_process_name()) {
				const resolvers = fromProcess == processName ? Atom.ThreadPromises : Atom.ChildProcesses[fromProcess].resolvers;

				const resolver = resolvers[key];
				if (resolver) {
					resolver(data.result);
				}

				delete resolvers[key];
			}else{
				Atom.atom_post_child_process(processName, {
					command : cmd,
					processName,
					fromProcess,
					key,
					result
				});
			}
		}
	}

	function atom_fork(name) {
		if (!name || name == NULL) {
			name = Atom.atom_generage_random_key();
		}

		if (name == "main") {
			throw Error("You can't create a child process with name `main`");
		}

		if (!Atom.atom_is_multi_thread_enabled()) {
			throw Error("Atom multi thread is not enabled!");
		}

		if (Atom.atom_child_process_exists(name)) {
			return;
		}

		const process = new Worker(Atom.atom_get_worker_script_path());
		if (!process) {
			throw Error("Couldn't create child process `" + name + "` !");
		}

		Atom.ChildProcesses[name] = { thread : process, ready : false, resolvers : {} };

		process.onmessage = _atom_handle_process_message;

		process.postMessage({
			command: "load",
			atomMainScriptPath : Atom.atom_get_main_script_path(),
			workerScriptPath : Atom.atom_get_worker_script_path(),
			processName : name,
			fromProcess : Atom.atom_get_process_name()
		});
	}

	function atom_post_child_process(name, message) {
		const currentProcessName = Atom.atom_get_process_name();

		if (!Atom.atom_is_main_process()) {
			if (name == currentProcessName) {
				onmessage({
					data : message
				});

				return;
			}

			postMessage({
				command: "post",
				processName : name,
				fromProcess : currentProcessName,
				message
			});

			return;
		}

		if (name == currentProcessName) {
			_atom_handle_process_message({
				data : message
			});

			return;
		}

		if (!Atom.atom_child_process_exists(name)) {
			return;
		}

		message.tempValue = Module.TempValue;

		Atom.ChildProcesses[name].thread.postMessage(message);
	}

	function atom_child_process_exists(name) {
		if (!name || name == NULL) {
			return false;
		}

		if (name == "main") {
			return true;
		}

		return Atom.ChildProcesses[name] ? true : false;
	}

	function atom_child_process_is_ready(name) {
		if (!Atom.atom_child_process_exists(name)) {
			return false;
		}

		return Atom.ChildProcesses[name].ready;
	}

	function atom_terminate_child_process(name) {
		if (!Atom.atom_child_process_exists(name)) {
			return;
		}

		Atom.ChildProcesses[name].thread.terminate();

		Atom.ChildProcesses[name] = undefined;
		delete Atom.ChildProcesses[name];
	}

	function atom_call_child_process_native(name, functionName, ...args) {
		var promiseHandler = () => {};

		const key = Atom.atom_generage_random_key();
		const currentProcess = Atom.atom_get_process_name();

		if (Atom.atom_is_main_process()) {
			if (name == currentProcess) {
				promiseHandler = resolver => Atom.ThreadPromises[key] = resolver;
			}else{
				if (!Atom.atom_child_process_exists(name)) {
					return;
				}

				promiseHandler = resolver => Atom.ChildProcesses[name].resolvers[key] = resolver;
			}
		}else{
			promiseHandler = resolver => Atom.ThreadPromises[key] = resolver;
		}

		Atom.atom_post_child_process(name, {
			command: "calln",
			processName : name,
			fromProcess : currentProcess,
			key,
			functionName,
			functionArgs : args
		});

		return new Promise(promiseHandler);
	}

	function atom_call_child_process_native_no_wait(name, functionName, ...args) {
		const key = Atom.atom_generage_random_key();
		const currentProcess = Atom.atom_get_process_name();

		if (
			Atom.atom_is_main_process() &&
			name != currentProcess &&
			!Atom.atom_child_process_exists(name)
		) {
			return;
		}

		Atom.atom_post_child_process(name, {
			command: "calln",
			processName : name,
			fromProcess : currentProcess,
			key,
			functionName,
			functionArgs : args,
			dontWait : true
		});
	}

	function atom_call_child_process_module(name, functionName, ...args) {
		var promiseHandler = () => {};

		const key = Atom.atom_generage_random_key();
		const currentProcess = Atom.atom_get_process_name();

		if (Atom.atom_is_main_process()) {
			if (name == currentProcess) {
				promiseHandler = resolver => Atom.ThreadPromises[key] = resolver;
			}else{
				if (!Atom.atom_child_process_exists(name)) {
					return;
				}

				promiseHandler = resolver => Atom.ChildProcesses[name].resolvers[key] = resolver;
			}
		}else{
			promiseHandler = resolver => Atom.ThreadPromises[key] = resolver;
		}

		Atom.atom_post_child_process(name, {
			command: "callm",
			processName : name,
			fromProcess : currentProcess,
			key,
			functionName,
			functionArgs : args
		});

		return new Promise(promiseHandler);
	}
	
	function atom_call_child_process_module_no_wait(name, functionName, ...args) {
		const key = Atom.atom_generage_random_key();
		const currentProcess = Atom.atom_get_process_name();

		if (
			Atom.atom_is_main_process() &&
			name != currentProcess &&
			!Atom.atom_child_process_exists(name)
		) {
			return;
		}

		Atom.atom_post_child_process(name, {
			command: "callm",
			processName : name,
			fromProcess : currentProcess,
			key,
			functionName,
			functionArgs : args,
			dontWait : true
		});
	}

	async function atom_loadstring_child_process(process, code) {
		const currentProcess = Atom.atom_get_process_name();

		if (process == currentProcess) {
			var caller = () => {};

			eval(`caller = async function() { ${code} };`);

			return caller;
		}

		if (!await Atom.atom_child_process_exists(process)) {
			return;
		}

		return async function(...args) {
			return await Atom.atom_call_child_process_native(process, "_atom_eval", code, ...args);
		}
	}

	async function _atom_eval(code, ...args) {
		var caller = () => {};

		eval(`caller = async function() { ${code} };`);

		return await caller(...args);
	}

	async function atom_eval_child_process(process, code, ...args) {
		const currentProcess = Atom.atom_get_process_name();

		if (process == currentProcess) {
			var caller = () => {};

			eval(`caller = async function() { ${code} };`);

			return await caller(...args);
		}

		return await Atom.atom_call_child_process_native(process, "_atom_eval", code, ...args);
	}

	function atom_yield() {
		return new Promise(resolver => {
			Atom.YieldPromise = resolver;
		});
	}

	function atom_resume(name, result) {
		const currentProcess = Atom.atom_get_process_name();

		if (Atom.atom_is_main_process()) {
			if (name == currentProcess) {
				const resolver = Atom.YieldPromise;

				if (resolver) {
					resolver(result);
				}

				return;
			}

			if (!Atom.atom_child_process_exists(name)) {
				return;
			}
		}

		Atom.atom_post_child_process(name, {
			command : "resume",
			processName : name,
			fromProcess : currentProcess,
			result
		});
	}

	function atom_sleep(ms) {
		return new Promise(resolve => setTimeout(resolve, ms));
	}

	function atom_function_pointer_exists(pointer) {
		return typeof wasmTable[pointer] == "function";
	}

	function atom_delete_function_pointer(pointer) {
		if (!Atom.atom_function_pointer_exists(pointer)) {
			return;
		}

		delete wasmTable[pointer];
		_free(pointer);
	}
	
	function atom_register_shared_function(name, handler, clearMemory, process) {
		if (Atom.atom_shared_function_exists(name)) {
			return;
		}

		if (handler == NULL) {
			return;
		}

		const currentProcess = Atom.atom_get_process_name();

		const func = { pointer : handler, process : currentProcess, caller : wasmTable[handler] };
		if (clearMemory) {
			func.clearMemory = true;
		}

		if (typeof process == "string" && process != currentProcess) {
			func.process = process;

			func.caller = function(...args) {
				Atom.atom_post_child_process(process, {
					command : "sfcall",
					processName : process,
					fromProcess : currentProcess,
					pointer : handler,
					functionArgs : args
				});
			};
		}

		Atom.SharedFunctions[name] = func;
	}

	function atom_shared_function_exists(name) {
		return Atom.SharedFunctions[name] ? true : false;
	}

	function atom_remove_shared_function(name) {
		if (!Atom.atom_shared_function_exists(name)) {
			return;
		}

		const func = Atom.SharedFunctions[name];

		const currentProcess = Atom.atom_get_process_name();
		const process = func.process;

		if (process != currentProcess) {
			if (func.clearMemory) {
				Atom.atom_post_child_process(process, {
					command : "sfremove",
					processName : process,
					fromProcess : currentProcess,
					pointer : func.pointer
				});
			}
		}

		delete Atom.SharedFunctions[name];
	}

	function atom_get_shared_function_pointer(name) {
		if (!Atom.atom_shared_function_exists(name)) {
			return NULL;
		}

		return Atom.SharedFunctions[name].pointer || NULL;
	}

	function atom_get_shared_function_process(name) {
		if (!Atom.atom_shared_function_exists(name)) {
			return NULL;
		}

		return Atom.SharedFunctions[name].process || NULL;
	}

	function atom_invoke_shared_function(name, ...args) {
		if (!Atom.atom_shared_function_exists(name)) {
			return;
		}

		Atom.SharedFunctions[name].caller(...args);
	}

	async function atom_get_shared_function(name) {
		if (!await Atom.atom_shared_function_exists(name)) {
			return NULL;
		}

		if (Atom.atom_is_main_process()) {
			const func = Atom.SharedFunctions[name];

			return func.caller;
		}

		return function(...args) {
			Atom.atom_invoke_shared_function(name, ...args);
		}
	}

	function atom_allocate_shared_memory(name, size) {
		if (Atom.atom_shared_memory_exists(name)) {
			return;
		}

		if (size < 1) {
			return;
		}

		const pointer = _malloc(size);
		if (!pointer || pointer == NULL) {
			return;
		}

		Atom.SharedMemories[name] = { pointer, size };
	}

	function atom_shared_memory_exists(name) {
		return Atom.SharedMemories[name] ? true : false;
	}

	async function atom_get_shared_memory_pointer(name) {
		if (!Atom.atom_is_main_process()) {
			const memory = Atom.SharedMemories[name];
			if (memory) {
				return memory.pointer;
			}

			return await Atom.atom_call_child_process_native("main", "atom_get_shared_memory_pointer", name);
		}

		if (!Atom.atom_shared_memory_exists(name)) {
			return NULL;
		}

		return Atom.SharedMemories[name].pointer;
	}

	async function atom_get_shared_memory_size(name) {
		if (!Atom.atom_is_main_process()) {
			const memory = Atom.SharedMemories[name];
			if (memory) {
				return memory.size;
			}

			return await Atom.atom_call_child_process_native("main", "atom_get_shared_memory_size", name);
		}

		if (!Atom.atom_shared_memory_exists(name)) {
			return NULL;
		}

		return Atom.SharedMemories[name].size;
	}

	async function atom_free_shared_memory(name) {
		if (!Atom.atom_is_main_process()) {
			const memory = Atom.SharedMemories[name];
			if (memory) {
				_free(memory.pointer);

				delete Atom.SharedMemories[name];
			}

			await Atom.atom_call_child_process_native("main", "atom_free_shared_memory", name);
			return;
		}

		if (!Atom.atom_shared_memory_exists(name)) {
			return;
		}

		const memory = Atom.SharedMemories[name];

		if (!memory || memory == NULL) {
			return NULL;
		}

		_free(memory.pointer);

		delete Atom.SharedMemories[name];
	}

	async function atom_get_shared_memory(name) {
		if (!Atom.atom_is_main_process()) {
			const memory = Atom.SharedMemories[name];
			if (memory) {
				return memory.pointer;
			}
		}

		if (!await Atom.atom_shared_memory_exists(name)) {
			return NULL;
		}

		if (Atom.atom_is_main_process()) {
			const memory = Atom.SharedMemories[name];
			
			return memory.pointer;
		}

		const size = await Atom.atom_get_shared_memory_size(name);

		if (!size || size == NULL) {
			return NULL;
		}

		const pointer = _malloc(size);

		Atom.SharedMemories[name] = { pointer, size };

		await Atom.atom_update_shared_memory(name);

		return pointer;
	}

	function _atom_on_shared_memory_update(name, buffer) {
		const memory = Atom.SharedMemories[name];

		if (!memory || memory == NULL) {
			return;
		}

		const pointer = memory.pointer;
		const size = memory.size;

		const mem = new Uint8Array(HEAPU8.buffer, pointer, size);
		mem.set(new Uint8Array(buffer));
	}

	async function atom_update_shared_memory(name, process) {
		if (!Atom.atom_shared_memory_exists(name)) {
			return;
		}

		const currentProcess = Atom.atom_get_process_name();

		const memory = Atom.SharedMemories[name];
		const pointer = memory.pointer;
		const size = memory.size;

		const buffer = new ArrayBuffer(size);
		(new Uint8Array(buffer)).set(new Uint8Array(HEAPU8.buffer, pointer, size));

		if (typeof process == "string" && process.length > 0) {
			if (!Atom.atom_child_process_exists(process)) {
				return;
			}

			await Atom.atom_call_child_process_native(process, "_atom_on_shared_memory_update", name, buffer);
		}else{
			for (const child_process in Atom.ChildProcesses) {
				await Atom.atom_call_child_process_native(child_process, "_atom_on_shared_memory_update", name, buffer);
			}
		}
	}

	async function atom_update_main_shared_memory(name) {
		if (Atom.atom_is_main_process()) {
			return;
		}

		const memory = Atom.SharedMemories[name];
		if (!memory || memory == NULL) {
			return;
		}

		const pointer = memory.pointer;
		const size = memory.size;

		const buffer = new ArrayBuffer(size);
		(new Uint8Array(buffer)).set(new Uint8Array(HEAPU8.buffer, pointer, size));

		await Atom.atom_call_child_process_native("main", "_atom_on_shared_memory_update", name, buffer);
	}

	function atom_request_animation_frame(handler, value) {
		if (!handler || handler == NULL) {
			return;
		}

		const cfunction = typeof handler == "function" ? handler : wasmTable.get(handler);
		if (!cfunction) {
			return;
		}

		var offset = Atom.AnimationsOffset;

		if (offset > MAX_INT) {
			offset = 1;
		}

		while (Atom.Animations[offset]) offset++;

		const ref = offset++;

		const caller = function(tick) {
			const animation = Atom.Animations[ref];

			if (animation) {
				cfunction(tick, value);

				requestAnimationFrame(caller);
			}
		};

		Atom.Animations[ref] = { pointer : handler, caller };

		Atom.AnimationsOffset = offset;

		requestAnimationFrame(caller);

		return ref;
	}

	function atom_exists_animation_frame(id) {
		return Atom.Animations[id] ? true : false;
	}

	function atom_cancel_animation_frame(id) {
		if (!Atom.atom_exists_animation_frame(id)) {
			return;
		}

		delete Atom.Animations[id];
	}

	function atom_get_animation_frame_handler(id) {
		if (!Atom.atom_exists_animation_frame(id)) {
			return;
		}

		return Atom.Animations[id].pointer;
	}

	function atom_get_pixel_ratio() {
		const ctx = Atom.MotherCanvasContext;
		const dpr = window.devicePixelRatio || 1;
		const bsr = (
			ctx.webkitBackingStorePixelRatio ||
			ctx.mozBackingStorePixelRatio ||
			ctx.msBackingStorePixelRatio ||
			ctx.oBackingStorePixelRatio ||
			ctx.backingStorePixelRatio ||
			1
		);

		return dpr / bsr;
	}

	function atom_create_render_target(width, height, ratio = NULL, alpha = NULL, colorSpace = NULL, desynchronized = NULL, willReadFrequently = NULL) {
		const element = Atom.atom_create_element("canvas");
		const elementObject = Atom.atom_get_element_by_reference(element);

		if (!elementObject) {
			return NULL;
		}

		if (!ratio) {
			ratio = Atom.atom_get_pixel_ratio();
		}

		width = width || 1;
		height = height || 1;

		elementObject.width = width * ratio;
		elementObject.height = height * ratio;

		elementObject.style.width = width + "px";
		elementObject.style.height = height + "px";

		var attributes = {};
		
		if (alpha) {
			attributes.alpha = Boolean(alpha);
		}

		if (colorSpace) {
			attributes.colorSpace = colorSpace;
		}

		if (desynchronized) {
			attributes.desynchronized = Boolean(desynchronized);
		}

		if (willReadFrequently) {
			attributes.willReadFrequently = Boolean(willReadFrequently);
		}

		const length = Object.keys(attributes).length;

		const renderTarget = { canvas : elementObject, context : elementObject.getContext("2d", length > 0 ? attributes : undefined), IS_RENDER_TARGET : true, ratio };
		const ref = Atom.atom_create_element_reference(renderTarget);
		
		renderTarget.remove = function() {
			elementObject.remove();
		};

		renderTarget.context.textAlign = "left";
		renderTarget.context.textBaseline = "top";

		Atom.atom_remove_element_reference(element);

		return ref;
	}

	function atom_create_path2D() {
		const path = new Path2D();

		const pathElement = { canvas : {}, context : path, IS_RENDER_TARGET : true, ratio : NULL };
		const ref = Atom.atom_create_element_reference(pathElement);

		pathElement.remove = function() {};

		return ref;
	}

	function atom_is_element_render_target(element) {
		const elementObject = Atom.atom_get_element_by_reference(element);

		if (!elementObject) {
			return false;
		}

		return elementObject.IS_RENDER_TARGET ? true : false;
	}

	function atom_get_render_target_canvas(element) {
		const elementObject = Atom.atom_get_element_by_reference(element);
		
		if (!elementObject) {
			return NULL;
		}

		if (!elementObject.IS_RENDER_TARGET) {
			return NULL;
		}

		return Atom.atom_create_element_reference(elementObject.canvas);
	}

	function atom_get_render_target_context(element) {
		const elementObject = Atom.atom_get_element_by_reference(element);

		if (!elementObject) {
			return NULL;
		}

		if (!elementObject.IS_RENDER_TARGET) {
			return NULL;
		}

		return elementObject.context;
	}

	function atom_get_render_target_ratio(element) {
		const elementObject = Atom.atom_get_element_by_reference(element);

		if (!elementObject) {
			return 0;
		}

		if (!elementObject.IS_RENDER_TARGET) {
			return 0;
		}

		return elementObject.ratio;
	}

	function atom_resize_render_target(element, width, height, ratio) {
		const elementObject = Atom.atom_get_element_by_reference(element);

		if (!elementObject) {
			return NULL;
		}

		if (!elementObject.IS_RENDER_TARGET) {
			return NULL;
		}

		if (!ratio) {
			ratio = Atom.atom_get_pixel_ratio();
		}

		const canvas = elementObject.canvas;

		width = width || canvas.width;
		height = height || canvas.height;

		canvas.width = width * ratio;
		canvas.height = height * ratio;

		canvas.style.width = width + "px";
		canvas.style.height = height + "px";

		elementObject.ratio = ratio;
	}

	function atom_get_render_target_attributes(element) {
		element = Atom.atom_get_element_by_reference(element);

		if (!element) {
			return NULL;
		}

		return element.context.getContextAttributes();
	}

	function atom_get_render_target_width(element) {
		const elementObject = Atom.atom_get_element_by_reference(element);

		if (!elementObject) {
			return 0;
		}

		if (!elementObject.IS_RENDER_TARGET) {
			return 0;
		}

		return elementObject.canvas.width;
	}

	function atom_get_render_target_height(element) {
		const elementObject = Atom.atom_get_element_by_reference(element);

		if (!elementObject) {
			return 0;
		}

		if (!elementObject.IS_RENDER_TARGET) {
			return 0;
		}

		return elementObject.canvas.height;
	}

	function atom_get_render_target_real_width(element) {
		const elementObject = Atom.atom_get_element_by_reference(element);

		if (!elementObject) {
			return 0;
		}

		if (!elementObject.IS_RENDER_TARGET) {
			return 0;
		}

		return elementObject.canvas.width / elementObject.ratio;
	}
	
	function atom_get_render_target_real_height(element) {
		const elementObject = Atom.atom_get_element_by_reference(element);

		if (!elementObject) {
			return 0;
		}

		if (!elementObject.IS_RENDER_TARGET) {
			return 0;
		}

		return elementObject.canvas.height / elementObject.ratio;
	}

	function atom_set_custom_ratio(ratio) {
		Atom.AtomCustomRatio = ratio;
	}

	function atom_get_custom_ratio() {
		return Atom.AtomCustomRatio;
	}

	function _atom_rt_filter_coord_by_ratio(coord, element) {
		if (Atom.AtomCustomRatio) {
			return coord * Atom.AtomCustomRatio;
		}

		return coord * element.ratio;
	}

	function atom_rt_filter_coord_by_ratio(coord, element) {
		if (Atom.AtomCustomRatio) {
			return coord * Atom.AtomCustomRatio;
		}

		element = atom_get_element_by_reference(element);

		if (!element) {
			return 0;
		}

		return coord * element.ratio;
	}

	function atom_get_render_target_pixels(element, x, y, width, height) {
		element = Atom.atom_get_element_by_reference(element);

		if (!element) {
			return;
		}

		const canvas = element.canvas;

		const cWidth = canvas.width;
		const cHeight = canvas.height;

		return element.context.getImageData(
			Math.max(0, Math.min(_atom_rt_filter_coord_by_ratio(x, element), cWidth)),
			Math.max(0, Math.min(_atom_rt_filter_coord_by_ratio(y, element), cHeight)),
			Math.max(0, Math.min(_atom_rt_filter_coord_by_ratio(width, element), cWidth)),
			Math.max(0, Math.min(_atom_rt_filter_coord_by_ratio(height, element), cHeight))
		);
	}

	function atom_set_render_target_pixels(element, imageData, x, y, dirtyX = -1, dirtyY = -1, dirtyWidth = -1, dirtyHeight = -1) {
		element = Atom.atom_get_element_by_reference(element);

		if (!element) {
			return;
		}

		dirtyX = dirtyX == -1 ? 0 : dirtyX;
		dirtyY = dirtyY == -1 ? 0 : dirtyY;
		dirtyWidth = dirtyWidth == -1 ? imageData.width : dirtyWidth;
		dirtyHeight = dirtyHeight == -1 ? imageData.height : dirtyHeight;

		x = _atom_rt_filter_coord_by_ratio(x, element);
		y = _atom_rt_filter_coord_by_ratio(y, element);
		
		element.context.putImageData(imageData, x, y, dirtyX, dirtyY, dirtyWidth, dirtyHeight);
	}

	function atom_set_render_target(element) {
		if (!element) {
			Atom.AtomSelectedRenderTarget = NULL;
			return;
		}

		const elementObject = Atom.atom_get_element_by_reference(element);

		if (!elementObject) {
			return;
		}

		if (!elementObject.IS_RENDER_TARGET) {
			return;
		}

		Atom.AtomSelectedRenderTarget = element;
	}

	function atom_get_selected_render_target() {
		return Atom.AtomSelectedRenderTarget;
	}

	function atom_set_render_target_property(element, propertyName, value) {
		const elementObject = Atom.atom_get_element_by_reference(element);

		if (!elementObject) {
			return;
		}

		if (!elementObject.IS_RENDER_TARGET) {
			return;
		}

		const ctx = elementObject.context;
		ctx[propertyName] = value;
	}

	function atom_get_render_target_property(element, propertyName) {
		const elementObject = Atom.atom_get_element_by_reference(element);

		if (!elementObject) {
			return;
		}

		if (!elementObject.IS_RENDER_TARGET) {
			return;
		}

		const ctx = elementObject.context;
		return ctx[propertyName];
	}

	function atom_rt_set_direction(dir) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.direction = dir;
	}

	function atom_rt_get_direction() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.direction;
	}

	function atom_rt_set_fill_style(style) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.fillStyle = style;
	}

	function atom_rt_get_fill_style() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.fillStyle;
	}

	function atom_rt_set_filter(style) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.filter = style;
	}

	function atom_rt_get_filter() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.filter;
	}

	function atom_rt_set_font(style) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.font = style;
	}

	function atom_rt_get_font() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.font;
	}

	function atom_rt_set_font_kerning(style) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.fontKerning = style;
	}

	function atom_rt_get_font_kerning() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.fontKerning;
	}

	function atom_rt_set_global_alpha(alpha) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.globalAlpha = alpha;
	}

	function atom_rt_get_global_alpha() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return 0;
		}

		return rt.context.globalAlpha;
	}

	function atom_rt_set_global_composite_operation(op) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.globalCompositeOperation = op;
	}

	function atom_rt_get_global_composite_operation() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.globalCompositeOperation;
	}

	function atom_rt_set_image_smoothing_enabled(state) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.imageSmoothingEnabled = state;
	}

	function atom_rt_is_image_smoothing_enabled() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return false;
		}

		return rt.context.imageSmoothingEnabled;
	}

	function atom_rt_set_image_smoothing_quality(quality) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.imageSmoothingQuality = quality;
	}

	function atom_rt_get_image_smoothing_quality() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.imageSmoothingQuality;
	}

	function atom_rt_set_letter_spacing(style) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.letterSpacing = style;
	}

	function atom_rt_get_letter_spacing() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.letterSpacing;
	}

	function atom_rt_set_line_cap(style) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.lineCap = style;
	}

	function atom_rt_get_line_cap() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.lineCap;
	}

	function atom_rt_set_line_dash_offset(offset) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.lineDashOffset = offset;
	}

	function atom_rt_get_line_dash_offset() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.lineDashOffset;
	}

	function atom_rt_set_line_join(style) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.lineJoin = style;
	}

	function atom_rt_get_line_join() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.lineJoin;
	}

	function atom_rt_set_line_width(width) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.lineWidth = width;
	}

	function atom_rt_get_line_width() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.lineWidth;
	}

	function atom_rt_set_miter_limit(limit) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.miterLimit = limit;
	}

	function atom_rt_get_miter_limit() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.miterLimit;
	}

	function atom_rt_set_shadow_blur(level) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.shadowBlur = level;
	}

	function atom_rt_get_shadow_blur() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.shadowBlur;
	}

	function atom_rt_set_shadow_color(style) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.shadowColor = style;
	}

	function atom_rt_get_shadow_color() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.shadowColor;
	}

	function atom_rt_set_shadow_offset(x, y) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.shadowOffsetX = x;
		rt.context.shadowOffsetY = y;
	}

	function atom_rt_get_shadow_offset_x() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.shadowOffsetX;
	}

	function atom_rt_get_shadow_offset_y() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.shadowOffsetY;
	}

	function atom_rt_set_stroke_style(style) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.strokeStyle = style;
	}

	function atom_rt_get_stroke_style() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.strokeStyle;
	}

	function atom_rt_set_text_align(style) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.textAlign = style;
	}

	function atom_rt_get_text_align() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.textAlign;
	}

	function atom_rt_set_text_baseline(style) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.textBaseline = style;
	}

	function atom_rt_get_text_baseline() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.textBaseline;
	}

	function atom_rt_set_text_rendering(style) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.textRendering = style;
	}

	function atom_rt_get_text_rendering() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.textRendering;
	}

	function atom_rt_set_word_spacing(style) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.wordSpacing = style;
	}

	function atom_rt_get_word_spacing() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return NULL;
		}

		return rt.context.wordSpacing;
	}

	function atom_rt_arc(x, y, radius, startAngle, endAngle, counterclockwise = false) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);
		radius = _atom_rt_filter_coord_by_ratio(radius, rt);

		rt.context.arc(x, y, radius, startAngle, endAngle, counterclockwise);
	}

	function atom_rt_arc_to(x1, y1, x2, y2, radius) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x1 = _atom_rt_filter_coord_by_ratio(x1, rt);
		y1 = _atom_rt_filter_coord_by_ratio(y1, rt);
		x2 = _atom_rt_filter_coord_by_ratio(x2, rt);
		y2 = _atom_rt_filter_coord_by_ratio(y2, rt);

		rt.context.arcTo(x1, y1, x2, y2, radius);
	}

	function atom_rt_begin_path() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.beginPath();
	}

	function atom_rt_bezier_curve_to(cp1x, cp1y, cp2x, cp2y, x, y) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		cp1x = _atom_rt_filter_coord_by_ratio(cp1x, rt);
		cp1y = _atom_rt_filter_coord_by_ratio(cp1y, rt);
		cp2x = _atom_rt_filter_coord_by_ratio(cp2x, rt);
		cp2y = _atom_rt_filter_coord_by_ratio(cp2y, rt);
		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);

		rt.context.bezierCurveTo(cp1x, cp1y, cp2x, cp2y, x, y);
	}

	function atom_rt_clear_rect(x, y, width, height) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);
		width = _atom_rt_filter_coord_by_ratio(width, rt);
		height = _atom_rt_filter_coord_by_ratio(height, rt);

		rt.context.clearRect(x, y, width, height);
	}

	function atom_rt_clip(path, fillRule) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		path = Atom.atom_get_element_by_reference(path);

		if (path) {
			if (typeof fillRule == "string") {
				rt.context.clip(path.context, fillRule);
				return;
			}

			rt.context.clip(path.context);
			return;
		}

		if (typeof fillRule == "string") {
			rt.context.clip(fillRule);
			return;
		}

		rt.context.clip();
	}

	function atom_rt_close_path() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.closePath();
	}

	function atom_rt_draw_focus_if_needed(element, path) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		element = Atom.atom_get_element_by_reference(element);

		if (!element) {
			return;
		}

		path = Atom.atom_get_element_by_reference(path);

		if (path) {
			rt.context.drawFocusIfNeeded(path.context, element);
			return;
		}

		rt.context.drawFocusIfNeeded(element);
	}

	function atom_rt_draw_image(x, y, width, height, image) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		image = Atom.atom_get_element_by_reference(image);

		if (!image) {
			return;
		}

		if (image.IS_RENDER_TARGET && !(image.context instanceof Path2D)) {
			image = image.canvas;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);
		width = _atom_rt_filter_coord_by_ratio(width, rt);
		height = _atom_rt_filter_coord_by_ratio(height, rt);

		rt.context.drawImage(image, x, y, width, height);
	}

	function atom_rt_draw_image_section(x, y, width, height, dx, dy, dWidth, dHeight, image) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);
		width = _atom_rt_filter_coord_by_ratio(width, rt);
		height = _atom_rt_filter_coord_by_ratio(height, rt);
		
		image = Atom.atom_get_element_by_reference(image);

		if (!image) {
			return;
		}

		if (!image.IS_RENDER_TARGET && !(image.context instanceof Path2D)) {
			image = image.canvas;

			dx = _atom_rt_filter_coord_by_ratio(dx, image);
			dy = _atom_rt_filter_coord_by_ratio(dy, image);
			dWidth = _atom_rt_filter_coord_by_ratio(dWidth, image);
			dHeight = _atom_rt_filter_coord_by_ratio(dHeight, image);
		}

		rt.context.drawImage(image, x, y, width, height, dx, dy, dWidth, dHeight);
	}

	function atom_rt_ellipse(x, y, radiusX, radiusY, rotation, startAngle, endAngle, clockwise = false) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);
		radiusX = _atom_rt_filter_coord_by_ratio(radiusX, rt);
		radiusY = _atom_rt_filter_coord_by_ratio(radiusY, rt);

		rt.context.ellipse(x, y, radiusX, radiusY, rotation, startAngle, endAngle, clockwise);
	}

	function atom_rt_fill(path, fillRule) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		path = Atom.atom_get_element_by_reference(path);

		if (path) {
			if (typeof fillRule == "string") {
				rt.context.fill(path.context, fillRule);
				return;
			}

			rt.context.fill(path.context);
			return;
		}

		if (typeof fillRule == "string") {
			rt.context.fill(fillRule);
			return;
		}

		rt.context.fill();
	}

	function atom_rt_fill_rect(x, y, width, height) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);
		width = _atom_rt_filter_coord_by_ratio(width, rt);
		height = _atom_rt_filter_coord_by_ratio(height, rt);

		rt.context.fillRect(x, y, width, height);
	}

	function atom_rt_fill_text(text, x, y, maxWidth) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);
		
		rt.context.fillText(text, x, y, maxWidth == -1 ? undefined : _atom_rt_filter_coord_by_ratio(maxWidth, rt));
	}

	function atom_rt_get_line_dash() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}
		
		return rt.context.getLineDash();
	}

	function atom_rt_get_transform() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		return rt.context.getTransform();
	}

	function atom_rt_is_context_lost() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return false;
		}

		return rt.context.isContextLost();
	}

	function atom_rt_is_point_in_path(x, y, path, fillRule) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return false;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);

		path = Atom.atom_get_element_by_reference(path);

		if (path) {
			if (typeof fillRule == "string") {
				return rt.context.isPointInPath(path.context, x, y, fillRule);
			}

			return rt.context.isPointInPath(path.context, x, y);
		}

		if (typeof fillRule == "string") {
			return rt.context.isPointInPath(x, y, fillRule);
		}

		return rt.context.isPointInPath(x, y);
	}

	function atom_rt_is_point_in_stroke(x, y, path) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return false;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);

		path = Atom.atom_get_element_by_reference(path);

		if (path) {
			return rt.context.isPointInStroke(path.context, x, y);
		}

		return rt.context.isPointInStroke(x, y);
	}

	function atom_rt_line_to(x, y) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}
		
		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);

		rt.context.lineTo(x, y);
	}
	
	function atom_rt_measure_text(text) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		return rt.context.measureText(text);
	}

	function atom_rt_move_to(x, y) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);

		rt.context.moveTo(x, y);
	}

	function atom_rt_quadratic_curve_to(cpx, cpy, x, y) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		cpx = _atom_rt_filter_coord_by_ratio(cpx, rt);
		cpy = _atom_rt_filter_coord_by_ratio(cpx, rt);
		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);

		rt.context.quadraticCurveTo(cpx, cpy, x, y);
	}

	function atom_rt_rect(x, y, width, height) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);
		width = _atom_rt_filter_coord_by_ratio(width, rt);
		height = _atom_rt_filter_coord_by_ratio(height, rt);

		rt.context.rect(x, y, width, height);
	}

	function atom_rt_reset() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.reset();
	}

	function atom_rt_reset_transform() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.resetTransform();
	}

	function atom_rt_restore() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.restore();
	}

	function atom_rt_rotate(angle) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.rotate(angle);
	}

	function atom_rt_round_rect(x, y, width, height, radii) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);
		width = _atom_rt_filter_coord_by_ratio(width, rt);
		height = _atom_rt_filter_coord_by_ratio(height, rt);

		if (radii instanceof Array) {
			for (var i = 0; i < radii.length; i++) radii[i] = _atom_rt_filter_coord_by_ratio(radii[i], rt);
		}else{
			radii = _atom_rt_filter_coord_by_ratio(radii, rt);
		}

		rt.context.roundRect(x, y, width, height, radii);
	}

	function atom_rt_save() {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.save();
	}

	function atom_rt_scale(x, y) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);

		rt.context.scale(x, y);
	}

	function atom_rt_scroll_path_into_view(path) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		path = Atom.atom_get_element_by_reference(path);

		if (path) {
			rt.context.scrollPathIntoView(path);
			return;
		}

		rt.context.scrollPathIntoView();
	}

	function atom_rt_set_line_dash(dash) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.setLineDash(dash);
	}

	function atom_rt_set_transform(a, b, c, d, e, f) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		rt.context.setTransform(a, b, c, d, e, f);
	}

	function atom_rt_stroke(path) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		path = Atom.atom_get_element_by_reference(path);

		if (path) {
			rt.context.stroke(path.context);
			return;
		}

		rt.context.stroke();
	}

	function atom_rt_stroke_rect(x, y, width, height) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);
		width = _atom_rt_filter_coord_by_ratio(width, rt);
		height = _atom_rt_filter_coord_by_ratio(height, rt);

		rt.context.strokeRect(x, y, width, height);
	}

	function atom_rt_stroke_text(text, x, y, maxWidth = -1) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);

		rt.context.strokeText(text, x, y, maxWidth == -1 ? undefined : _atom_rt_filter_coord_by_ratio(maxWidth, rt));
	}

	function atom_rt_translate(x, y) {
		const rt = Atom.atom_get_element_by_reference(Atom.AtomSelectedRenderTarget);

		if (!rt) {
			return;
		}

		x = _atom_rt_filter_coord_by_ratio(x, rt);
		y = _atom_rt_filter_coord_by_ratio(y, rt);

		rt.context.translate(x, y);
	}

	function CreateInternalSharedFunction(func, ifNotMain, dontWait) {
		if (Atom.atom_is_main_process()) {
			return func;
		}

		if (ifNotMain) {
			return ifNotMain;
		}

		const name = func.name;

		const caller = dontWait ? Atom.atom_call_child_process_native_no_wait : Atom.atom_call_child_process_native;
		
		return function() {
			return caller("main", name, ...arguments);
		}
	}

	Atom.atom_get_now = atom_get_now;
	Atom.atom_call_child_process_native = atom_call_child_process_native;
	Atom.atom_call_child_process_native_no_wait = atom_call_child_process_native_no_wait;
	Atom.atom_call_child_process_module = atom_call_child_process_module;
	Atom.atom_call_child_process_module_no_wait = atom_call_child_process_module_no_wait;
	Atom.atom_is_main_process = atom_is_main_process;
	Atom.atom_get_main_script_path = atom_get_main_script_path;
	Atom.atom_get_worker_script_path = atom_get_worker_script_path;
	Atom.atom_is_multi_thread_enabled = atom_is_multi_thread_enabled;
	Atom.atom_is_inside_worker = atom_is_inside_worker;
	Atom.atom_dynamic_call = atom_dynamic_call;
	Atom.atom_find_signature_caller = atom_find_signature_caller;
	Atom.atom_signature_call = atom_signature_call;
	Atom.atom_create_element_reference = CreateInternalSharedFunction(atom_create_element_reference);
	Atom.atom_get_element_by_reference = atom_get_element_by_reference;
	Atom.atom_create_element = CreateInternalSharedFunction(atom_create_element);
	Atom.atom_element_exists = CreateInternalSharedFunction(atom_element_exists);
	Atom.atom_remove_element_reference = CreateInternalSharedFunction(atom_remove_element_reference);
	Atom.atom_destroy_element = CreateInternalSharedFunction(atom_destroy_element);
	Atom.atom_is_same_element = CreateInternalSharedFunction(atom_is_same_element);
	Atom.atom_set_element_attribute = CreateInternalSharedFunction(atom_set_element_attribute);
	Atom.atom_get_element_attribute = CreateInternalSharedFunction(atom_get_element_attribute);
	Atom.atom_has_element_attribute = CreateInternalSharedFunction(atom_has_element_attribute);
	Atom.atom_remove_element_attribute = CreateInternalSharedFunction(atom_remove_element_attribute);
	Atom.atom_toggle_element_attribute = CreateInternalSharedFunction(atom_toggle_element_attribute);
	Atom.atom_set_element_property = CreateInternalSharedFunction(atom_set_element_property);
	Atom.atom_get_element_property = CreateInternalSharedFunction(atom_get_element_property);
	Atom.atom_element_append_child = CreateInternalSharedFunction(atom_element_append_child);
	Atom.atom_set_element_style = CreateInternalSharedFunction(atom_set_element_style);
	Atom.atom_get_element_style = CreateInternalSharedFunction(atom_get_element_style);
	Atom.atom_get_element_bounding_box_bytes = CreateInternalSharedFunction(atom_get_element_bounding_box_bytes);
	Atom.atom_query_selector = CreateInternalSharedFunction(atom_query_selector);
	Atom.atom_query_selector_all = CreateInternalSharedFunction(atom_query_selector_all);
	Atom.atom_add_element_class = CreateInternalSharedFunction(atom_add_element_class);
	Atom.atom_element_class_exists = CreateInternalSharedFunction(atom_element_class_exists);
	Atom.atom_remove_element_class = CreateInternalSharedFunction(atom_remove_element_class);
	Atom.atom_get_element_node_name = CreateInternalSharedFunction(atom_get_element_node_name);
	Atom.atom_get_element_parent = CreateInternalSharedFunction(atom_get_element_parent);
	Atom.atom_get_element_child_count = CreateInternalSharedFunction(atom_get_element_child_count);
	Atom.atom_scroll_to_element = CreateInternalSharedFunction(atom_scroll_to_element);
	Atom.atom_add_event_listener = atom_add_event_listener;
	Atom.atom_set_temp_value = atom_set_temp_value;
	Atom.atom_register_function = atom_register_function;
	Atom.atom_is_function_registered = atom_is_function_registered;
	Atom.atom_unregister_function = atom_unregister_function;
	Atom.atom_get_function_pointer = atom_get_function_pointer;
	Atom.atom_get_function = atom_get_function;
	Atom.atom_to_pointer = atom_to_pointer;
	Atom.atom_generage_random_key = atom_generage_random_key;
	Atom.atom_get_process_name = atom_get_process_name;
	Atom.atom_fork = CreateInternalSharedFunction(atom_fork);
	Atom.atom_post_child_process = atom_post_child_process;
	Atom.atom_child_process_exists = CreateInternalSharedFunction(atom_child_process_exists);
	Atom.atom_terminate_child_process = CreateInternalSharedFunction(atom_terminate_child_process);
	Atom.atom_child_process_is_ready = CreateInternalSharedFunction(atom_child_process_is_ready);
	Atom.atom_loadstring_child_process = atom_loadstring_child_process;
	Atom._atom_eval = _atom_eval;
	Atom.atom_eval_child_process = atom_eval_child_process;
	Atom.atom_yield = atom_yield;
	Atom.atom_resume = atom_resume;
	Atom.atom_sleep = atom_sleep;
	Atom.atom_function_pointer_exists = atom_function_pointer_exists;
	Atom.atom_delete_function_pointer = atom_delete_function_pointer;
	Atom.atom_register_shared_function = CreateInternalSharedFunction(atom_register_shared_function);
	Atom.atom_shared_function_exists = CreateInternalSharedFunction(atom_shared_function_exists);
	Atom.atom_remove_shared_function = CreateInternalSharedFunction(atom_remove_shared_function);
	Atom.atom_get_shared_function_pointer = CreateInternalSharedFunction(atom_get_shared_function_pointer);
	Atom.atom_get_shared_function_process = CreateInternalSharedFunction(atom_get_shared_function_process);
	Atom.atom_invoke_shared_function = CreateInternalSharedFunction(atom_invoke_shared_function, null, true);
	Atom.atom_get_shared_function = atom_get_shared_function;
	Atom.atom_allocate_shared_memory = CreateInternalSharedFunction(atom_allocate_shared_memory);
	Atom.atom_shared_memory_exists = CreateInternalSharedFunction(atom_shared_memory_exists);
	Atom.atom_get_shared_memory_pointer = atom_get_shared_memory_pointer;
	Atom.atom_get_shared_memory_size = atom_get_shared_memory_size;
	Atom.atom_free_shared_memory = atom_free_shared_memory;
	Atom.atom_get_shared_memory = atom_get_shared_memory;
	Atom._atom_on_shared_memory_update = _atom_on_shared_memory_update;
	Atom.atom_update_shared_memory = CreateInternalSharedFunction(atom_update_shared_memory);
	Atom.atom_update_main_shared_memory = atom_update_main_shared_memory;
	Atom.atom_request_animation_frame = atom_request_animation_frame;
	Atom.atom_exists_animation_frame = atom_exists_animation_frame;
	Atom.atom_cancel_animation_frame = atom_cancel_animation_frame;
	Atom.atom_get_animation_frame_handler = atom_get_animation_frame_handler;
	Atom.atom_get_pixel_ratio = atom_get_pixel_ratio;
	Atom.atom_create_render_target = atom_create_render_target;
	Atom.atom_create_path2D = atom_create_path2D;
	Atom.atom_is_element_render_target = atom_is_element_render_target;
	Atom.atom_get_render_target_canvas = atom_get_render_target_canvas;
	Atom.atom_get_render_target_ratio = atom_get_render_target_ratio;
	Atom.atom_resize_render_target = atom_resize_render_target;
	Atom.atom_get_render_target_width = atom_get_render_target_width;
	Atom.atom_get_render_target_height = atom_get_render_target_height;
	Atom.atom_get_render_target_real_width = atom_get_render_target_real_width;
	Atom.atom_get_render_target_real_height = atom_get_render_target_real_height;
	Atom.atom_set_custom_ratio = atom_set_custom_ratio;
	Atom.atom_get_custom_ratio = atom_get_custom_ratio;
	Atom.atom_rt_filter_coord_by_ratio = atom_rt_filter_coord_by_ratio;
	Atom.atom_get_render_target_pixels = atom_get_render_target_pixels;
	Atom.atom_set_render_target_pixels = atom_set_render_target_pixels;
	Atom.atom_set_render_target = atom_set_render_target;
	Atom.atom_get_selected_render_target = atom_get_selected_render_target;
	Atom.atom_set_render_target_property = atom_set_render_target_property;
	Atom.atom_get_render_target_property = atom_get_render_target_property;
	Atom.atom_rt_set_direction = atom_rt_set_direction;
	Atom.atom_rt_get_direction = atom_rt_get_direction;
	Atom.atom_rt_set_fill_style = atom_rt_set_fill_style;
	Atom.atom_rt_get_fill_style = atom_rt_get_fill_style;
	Atom.atom_rt_set_filter = atom_rt_set_filter;
	Atom.atom_rt_get_filter = atom_rt_get_filter;
	Atom.atom_rt_set_font = atom_rt_set_font;
	Atom.atom_rt_get_font = atom_rt_get_font;
	Atom.atom_rt_set_font_kerning = atom_rt_set_font_kerning;
	Atom.atom_rt_get_font_kerning = atom_rt_get_font_kerning;
	Atom.atom_rt_set_global_alpha = atom_rt_set_global_alpha;
	Atom.atom_rt_get_global_alpha = atom_rt_get_global_alpha;
	Atom.atom_rt_set_global_composite_operation = atom_rt_set_global_composite_operation;
	Atom.atom_rt_get_global_composite_operation = atom_rt_get_global_composite_operation;
	Atom.atom_rt_set_image_smoothing_enabled = atom_rt_set_image_smoothing_enabled;
	Atom.atom_rt_is_image_smoothing_enabled = atom_rt_is_image_smoothing_enabled;
	Atom.atom_rt_set_image_smoothing_quality = atom_rt_set_image_smoothing_quality;
	Atom.atom_rt_get_image_smoothing_quality = atom_rt_get_image_smoothing_quality;
	Atom.atom_rt_set_letter_spacing = atom_rt_set_letter_spacing;
	Atom.atom_rt_get_letter_spacing = atom_rt_get_letter_spacing;
	Atom.atom_rt_set_line_cap = atom_rt_set_line_cap;
	Atom.atom_rt_get_line_cap = atom_rt_get_line_cap;
	Atom.atom_rt_set_line_dash_offset = atom_rt_set_line_dash_offset;
	Atom.atom_rt_get_line_dash_offset = atom_rt_get_line_dash_offset;
	Atom.atom_rt_set_line_join = atom_rt_set_line_join;
	Atom.atom_rt_get_line_join = atom_rt_get_line_join;
	Atom.atom_rt_set_line_width = atom_rt_set_line_width;
	Atom.atom_rt_get_line_width = atom_rt_get_line_width;
	Atom.atom_rt_set_miter_limit = atom_rt_set_miter_limit;
	Atom.atom_rt_get_miter_limit = atom_rt_get_miter_limit;
	Atom.atom_rt_set_shadow_blur = atom_rt_set_shadow_blur;
	Atom.atom_rt_get_shadow_blur = atom_rt_get_shadow_blur;
	Atom.atom_rt_set_shadow_color = atom_rt_set_shadow_color;
	Atom.atom_rt_get_shadow_color = atom_rt_get_shadow_color;
	Atom.atom_rt_set_shadow_offset = atom_rt_set_shadow_offset;
	Atom.atom_rt_get_shadow_offset_x = atom_rt_get_shadow_offset_x;
	Atom.atom_rt_get_shadow_offset_y = atom_rt_get_shadow_offset_y;
	Atom.atom_rt_set_stroke_style = atom_rt_set_stroke_style;
	Atom.atom_rt_get_stroke_style = atom_rt_get_stroke_style;
	Atom.atom_rt_set_text_align = atom_rt_set_text_align;
	Atom.atom_rt_get_text_align = atom_rt_get_text_align;
	Atom.atom_rt_set_text_baseline = atom_rt_set_text_baseline;
	Atom.atom_rt_get_text_baseline = atom_rt_get_text_baseline;
	Atom.atom_rt_set_text_rendering = atom_rt_set_text_rendering;
	Atom.atom_rt_get_text_rendering = atom_rt_get_text_rendering;
	Atom.atom_rt_set_word_spacing = atom_rt_set_word_spacing;
	Atom.atom_rt_get_word_spacing = atom_rt_get_word_spacing;
	Atom.atom_rt_arc = atom_rt_arc;
	Atom.atom_rt_arc_to = atom_rt_arc_to;
	Atom.atom_rt_begin_path = atom_rt_begin_path;
	Atom.atom_rt_bezier_curve_to = atom_rt_bezier_curve_to;
	Atom.atom_rt_clear_rect = atom_rt_clear_rect;
	Atom.atom_rt_clip = atom_rt_clip;
	Atom.atom_rt_close_path = atom_rt_close_path;
	Atom.atom_rt_draw_focus_if_needed = atom_rt_draw_focus_if_needed;
	Atom.atom_rt_draw_image = atom_rt_draw_image;
	Atom.atom_rt_draw_image_section = atom_rt_draw_image_section;
	Atom.atom_rt_ellipse = atom_rt_ellipse;
	Atom.atom_rt_fill = atom_rt_fill;
	Atom.atom_rt_fill_rect = atom_rt_fill_rect;
	Atom.atom_rt_fill_text = atom_rt_fill_text;
	Atom.atom_rt_is_context_lost = atom_rt_is_context_lost;
	Atom.atom_rt_is_point_in_path = atom_rt_is_point_in_path;
	Atom.atom_rt_is_point_in_stroke = atom_rt_is_point_in_stroke;
	Atom.atom_rt_line_to = atom_rt_line_to;
	Atom.atom_rt_move_to = atom_rt_move_to;
	Atom.atom_rt_quadratic_curve_to = atom_rt_quadratic_curve_to;
	Atom.atom_rt_rect = atom_rt_rect;
	Atom.atom_rt_reset = atom_rt_reset;
	Atom.atom_rt_reset_transform = atom_rt_reset_transform;
	Atom.atom_rt_restore = atom_rt_restore;
	Atom.atom_rt_rotate = atom_rt_rotate;
	Atom.atom_rt_round_rect = atom_rt_round_rect;
	Atom.atom_rt_save = atom_rt_save;
	Atom.atom_rt_scale = atom_rt_scale;
	Atom.atom_rt_scroll_path_into_view = atom_rt_scroll_path_into_view;
	Atom.atom_rt_set_line_dash = atom_rt_set_line_dash;
	Atom.atom_rt_stroke = atom_rt_stroke;
	Atom.atom_rt_stroke_rect = atom_rt_stroke_rect;
	Atom.atom_rt_stroke_text = atom_rt_stroke_text;
	Atom.atom_rt_translate = atom_rt_translate;
	Atom.atom_get_render_target_attributes = atom_get_render_target_attributes;
	Atom.atom_rt_get_line_dash = atom_rt_get_line_dash;
	Atom.atom_rt_measure_text = atom_rt_measure_text;
	Atom.atom_rt_get_transform = atom_rt_get_transform;
	Atom.atom_rt_set_transform = atom_rt_set_transform;

	if (IsInsideWorker) {
		postMessage({
			command: "ready",
			processName : Atom.atom_get_process_name()
		});
	}
});

ATOM_JS(char*, atom_get_main_script_path, (), {
	return Atom.atom_to_pointer(Atom.atom_get_main_script_path());
});

ATOM_JS(char*, atom_get_worker_script_path, (), {
	return Atom.atom_to_pointer(Atom.atom_get_worker_script_path());
});

ATOM_JS(bool, atom_is_inside_worker, (), {
	return Atom.atom_is_inside_worker();
});

ATOM_JS(Auint32, _atom_get_temp_value, (), {
	return Atom.TempValue;
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, atom_get_document_head, (), {
	return 1;
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, atom_get_document_body, (), {
	return 2;
});

#ifdef ATOM_WASM_USE_MULTI_THREAD_DEFINITION

ATOM_JS_ASYNC(ATOM_ELEMENT_REFERENCE, atom_create_element, (const char* type, const char* Namespace), {
	if (type == NULL) {
		return NULL;
	}

	type = UTF8ToString(type);
	
	if (Namespace != NULL) {
		Namespace = UTF8ToString(Namespace);
	}

	return await Atom.atom_create_element(type, Namespace);
});

ATOM_JS_ASYNC(bool, atom_element_exists, (ATOM_ELEMENT_REFERENCE element), {
	return await Atom.atom_element_exists(element);
});

ATOM_JS_ASYNC(void, atom_destroy_element, (ATOM_ELEMENT_REFERENCE element), {
	await Atom.atom_destroy_element(element);
});

ATOM_JS_ASYNC(void, atom_free_element, (ATOM_ELEMENT_REFERENCE element), {
	await Atom.atom_remove_element_reference(element);
});

ATOM_JS_ASYNC(bool, atom_is_same_element, (ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE target), {
	return await Atom.atom_is_same_element(element, target);
});

ATOM_JS_ASYNC(void, atom_set_element_attribute, (ATOM_ELEMENT_REFERENCE element, const char* attribute, const char* value), {
	if (attribute == NULL) {
		return;
	}
	if (value == NULL) {
		return;
	}

	attribute = UTF8ToString(attribute);
	value = UTF8ToString(value);

	await Atom.atom_set_element_attribute(element, attribute, value);
});

ATOM_JS_ASYNC(char*, atom_get_element_attribute, (ATOM_ELEMENT_REFERENCE element, const char* attribute), {
	if (attribute == NULL) {
		return NULL;
	}

	attribute = UTF8ToString(attribute);

	const value = await Atom.atom_get_element_attribute(element, attribute);
	if (typeof value == "string") {
		return Atom.atom_to_pointer(value);
	}

	return value;
});

ATOM_JS_ASYNC(bool, atom_has_element_attribute, (ATOM_ELEMENT_REFERENCE element, const char* attribute), {
	if (attribute == NULL) {
		return false;
	}

	attribute = UTF8ToString(attribute);

	return await Atom.atom_has_element_attribute(element, attribute);
});

ATOM_JS_ASYNC(void, atom_remove_element_attribute, (ATOM_ELEMENT_REFERENCE element, const char* attribute), {
	if (attribute == NULL) {
		return;
	}

	attribute = UTF8ToString(attribute);

	await Atom.atom_remove_element_attribute(element, attribute);
});

ATOM_JS_ASYNC(void, atom_toggle_element_attribute, (ATOM_ELEMENT_REFERENCE element, const char* attribute), {
	if (attribute == NULL) {
		return;
	}

	attribute = UTF8ToString(attribute);

	await Atom.atom_toggle_element_attribute(element, attribute);
});

ATOM_JS_ASYNC(void, atom_set_element_property, (ATOM_ELEMENT_REFERENCE element, const char* property, const char* value), {
	if (property == NULL) {
		return;
	}
	if (value == NULL) {
		return;
	}

	property = UTF8ToString(property);
	value = UTF8ToString(value);

	await Atom.atom_set_element_property(element, property, value);
});

ATOM_JS_ASYNC(char*, atom_get_element_property, (ATOM_ELEMENT_REFERENCE element, const char* property), {
	if (property == NULL) {
		return NULL;
	}

	property = UTF8ToString(property);

	const value = await Atom.atom_get_element_property(element, property);

	if (typeof value == "string") {
		return Atom.atom_to_pointer(value);
	}

	return value;
});

ATOM_JS_ASYNC(void, atom_element_append_child, (ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE target), {
	await Atom.atom_element_append_child(element, target);
});

ATOM_JS_ASYNC(void, atom_set_element_style, (ATOM_ELEMENT_REFERENCE element, const char* property, const char* value), {
	if (property == NULL) {
		return;
	}
	if (value == NULL) {
		return;
	}

	property = UTF8ToString(property);
	value = UTF8ToString(value);

	await Atom.atom_set_element_style(element, property, value);
});

ATOM_JS_ASYNC(char*, atom_get_element_style, (ATOM_ELEMENT_REFERENCE element, const char* property), {
	if (property == NULL) {
		return NULL;
	}

	property = UTF8ToString(property);

	const value = await Atom.atom_get_element_style(element, property);

	if (typeof value == "string") {
		return self.atom_to_pointer(value);
	}

	return value;
});

ATOM_JS_ASYNC(ATOM_POINTER, _atom_get_element_bounding_box, (ATOM_ELEMENT_REFERENCE element), {
	const buffer = await Atom.atom_get_element_bounding_box_bytes(element);

	if (buffer) {
		const size = buffer.byteLength;
		if (!size || size < 1) {
			return NULL;
		}

		const pointer = _malloc(size);

		const heap = new Uint8Array(HEAPU8.buffer, pointer, size);
		heap.set(new Uint8Array(buffer));

		return pointer;
	}

	return NULL;
});

ATOM_JS_ASYNC(ATOM_ELEMENT_REFERENCE, _atom_document_query_selector, (const char* query), {
	if (query == NULL) {
		return NULL;
	}

	query = UTF8ToString(query);

	return await Atom.atom_query_selector(NULL, query);
});

ATOM_JS_ASYNC(ATOM_ELEMENT_REFERENCE, _atom_query_selector, (ATOM_ELEMENT_REFERENCE element, const char* query), {
	if (query == NULL) {
		return NULL;
	}

	query = UTF8ToString(query);

	return await Atom.atom_query_selector(element, query);
});

ATOM_JS_ASYNC(ATOM_POINTER, _atom_document_query_selector_all_pointer, (const char* query), {
	if (query == NULL) {
		return NULL;
	}

	query = UTF8ToString(query);

	const elements = await Atom.atom_query_selector_all(NULL, query);

	if (elements) {
		Atom.atom_set_temp_value(elements.length);

		return Atom.atom_to_pointer(new Uint32Array(elements));
	}

	return NULL;
});

ATOM_JS_ASYNC(ATOM_POINTER, _atom_query_selector_all_pointer, (ATOM_ELEMENT_REFERENCE element, const char* query), {
	if (query == NULL) {
		return NULL;
	}

	query = UTF8ToString(query);

	const elements = await Atom.atom_query_selector_all(element, query);

	if (elements) {
		Atom.atom_set_temp_value(elements.length);

		return Atom.atom_to_pointer(new Uint32Array(elements));
	}

	return NULL;
});

ATOM_JS_ASYNC(void, atom_add_element_class, (ATOM_ELEMENT_REFERENCE element, const char* className), {
	if (className == NULL) {
		return;
	}

	className = UTF8ToString(className);

	await Atom.atom_add_element_class(element, className);
});

ATOM_JS_ASYNC(bool, atom_element_class_exists, (ATOM_ELEMENT_REFERENCE element, const char* className), {
	if (className == NULL) {
		return;
	}

	className = UTF8ToString(className);

	return await Atom.atom_element_class_exists(element, className);
});

ATOM_JS_ASYNC(void, atom_remove_element_class, (ATOM_ELEMENT_REFERENCE element, const char* className), {
	if (className == NULL) {
		return;
	}

	className = UTF8ToString(className);

	await Atom.atom_remove_element_class(element, className);
});

ATOM_JS_ASYNC(char*, atom_get_element_node_name, (ATOM_ELEMENT_REFERENCE element), {
	const name = await Atom.atom_get_element_node_name(element);
	
	if (name) {
		return Atom.atom_to_pointer(name);
	}

	return NULL;
});

ATOM_JS_ASYNC(ATOM_ELEMENT_REFERENCE, atom_get_element_parent, (ATOM_ELEMENT_REFERENCE element), {
	return await Atom.atom_get_element_parent(element);
});

ATOM_JS_ASYNC(size_t, atom_get_element_child_count, (ATOM_ELEMENT_REFERENCE element), {
	return await Atom.atom_get_element_child_count(element);
});

ATOM_JS_ASYNC(void, atom_scroll_to_element, (ATOM_ELEMENT_REFERENCE element, const char* viewType), {
	if (!viewType == NULL) {
		viewType = UTF8ToString(viewType);
		await Atom.atom_scroll_to_element(element, viewType);

		return;
	}

	await Atom.atom_scroll_to_element(element);
})

#else

ATOM_JS(ATOM_ELEMENT_REFERENCE, atom_create_element, (const char* type, const char* Namespace), {
	if (type == NULL) {
		return NULL;
	}

	type = UTF8ToString(type);
	
	if (Namespace != NULL) {
		Namespace = UTF8ToString(Namespace);
	}

	return Atom.atom_create_element(type, Namespace);
});

ATOM_JS(bool, atom_element_exists, (ATOM_ELEMENT_REFERENCE element), {
	return Atom.atom_element_exists(element);
});

ATOM_JS(void, atom_destroy_element, (ATOM_ELEMENT_REFERENCE element), {
	Atom.atom_destroy_element(element);
});

ATOM_JS(void, atom_free_element, (ATOM_ELEMENT_REFERENCE element), {
	Atom.atom_remove_element_reference(element);
});

ATOM_JS(bool, atom_is_same_element, (ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE target), {
	return Atom.atom_is_same_element(element, target);
});

ATOM_JS(void, atom_set_element_attribute, (ATOM_ELEMENT_REFERENCE element, const char* attribute, const char* value), {
	if (attribute == NULL) {
		return;
	}
	if (value == NULL) {
		return;
	}

	attribute = UTF8ToString(attribute);
	value = UTF8ToString(value);

	Atom.atom_set_element_attribute(element, attribute, value);
});

ATOM_JS(char*, atom_get_element_attribute, (ATOM_ELEMENT_REFERENCE element, const char* attribute), {
	if (attribute == NULL) {
		return NULL;
	}

	attribute = UTF8ToString(attribute);

	const value = Atom.atom_get_element_attribute(element, attribute);
	if (typeof value == "string") {
		return atom_to_pointer(value);
	}

	return value;
});

ATOM_JS(bool, atom_has_element_attribute, (ATOM_ELEMENT_REFERENCE element, const char* attribute), {
	if (attribute == NULL) {
		return false;
	}

	attribute = UTF8ToString(attribute);

	return Atom.atom_has_element_attribute(element, attribute);
});

ATOM_JS(void, atom_remove_element_attribute, (ATOM_ELEMENT_REFERENCE element, const char* attribute), {
	if (attribute == NULL) {
		return;
	}

	attribute = UTF8ToString(attribute);

	Atom.atom_remove_element_attribute(element, attribute);
});

ATOM_JS(void, atom_toggle_element_attribute, (ATOM_ELEMENT_REFERENCE element, const char* attribute), {
	if (attribute == NULL) {
		return;
	}

	attribute = UTF8ToString(attribute);

	Atom.atom_toggle_element_attribute(element, attribute);
});

ATOM_JS(void, atom_set_element_property, (ATOM_ELEMENT_REFERENCE element, const char* property, const char* value), {
	if (property == NULL) {
		return;
	}
	if (value == NULL) {
		return;
	}

	property = UTF8ToString(property);
	value = UTF8ToString(value);

	Atom.atom_set_element_property(element, property, value);
});

ATOM_JS(char*, atom_get_element_property, (ATOM_ELEMENT_REFERENCE element, const char* property), {
	if (property == NULL) {
		return NULL;
	}

	property = UTF8ToString(property);

	const value = Atom.atom_get_element_property(element, property);

	if (typeof value == "string") {
		return Atom.atom_to_pointer(value);
	}

	return value;
});

ATOM_JS(void, atom_element_append_child, (ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE target), {
	Atom.atom_element_append_child(element, target);
});

ATOM_JS(void, atom_set_element_style, (ATOM_ELEMENT_REFERENCE element, const char* property, const char* value), {
	if (property == NULL) {
		return;
	}
	if (value == NULL) {
		return;
	}

	property = UTF8ToString(property);
	value = UTF8ToString(value);

	Atom.atom_set_element_style(element, property, value);
});

ATOM_JS(char*, atom_get_element_style, (ATOM_ELEMENT_REFERENCE element, const char* property), {
	if (property == NULL) {
		return NULL;
	}

	property = UTF8ToString(property);

	const value = Atom.atom_get_element_style(element, property);

	if (typeof value == "string") {
		return Atom.atom_to_pointer(value);
	}

	return value;
});

ATOM_JS(ATOM_POINTER, _atom_get_element_bounding_box, (ATOM_ELEMENT_REFERENCE element), {
	const buffer = Atom.atom_get_element_bounding_box_bytes(element);

	if (buffer) {
		const size = buffer.byteLength;
		if (!size || size < 1) {
			return NULL;
		}

		const pointer = _malloc(size);

		const heap = new Uint8Array(HEAPU8.buffer, pointer, size);
		heap.set(new Uint8Array(buffer));

		return pointer;
	}

	return NULL;
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, _atom_document_query_selector, (const char* query), {
	if (query == NULL) {
		return NULL;
	}

	query = UTF8ToString(query);

	return Atom.atom_query_selector(NULL, query);
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, _atom_query_selector, (ATOM_ELEMENT_REFERENCE element, const char* query), {
	if (query == NULL) {
		return NULL;
	}

	query = UTF8ToString(query);

	return Atom.atom_query_selector(element, query);
});

ATOM_JS(ATOM_POINTER, _atom_document_query_selector_all_pointer, (const char* query), {
	if (query == NULL) {
		return NULL;
	}

	query = UTF8ToString(query);

	const elements = Atom.atom_query_selector_all(NULL, query);

	if (elements) {
		Atom.atom_set_temp_value(elements.length);

		return Atom.atom_to_pointer(new Uint32Array(elements));
	}

	return NULL;
});

ATOM_JS(ATOM_POINTER, _atom_query_selector_all_pointer, (ATOM_ELEMENT_REFERENCE element, const char* query), {
	if (query == NULL) {
		return NULL;
	}

	query = UTF8ToString(query);

	const elements = Atom.atom_query_selector_all(element, query);

	if (elements) {
		Atom.atom_set_temp_value(elements.length);

		return Atom.atom_to_pointer(new Uint32Array(elements));
	}

	return NULL;
});

ATOM_JS(void, atom_add_element_class, (ATOM_ELEMENT_REFERENCE element, const char* className), {
	if (className == NULL) {
		return;
	}

	className = UTF8ToString(className);

	Atom.atom_add_element_class(element, className);
});

ATOM_JS(bool, atom_element_class_exists, (ATOM_ELEMENT_REFERENCE element, const char* className), {
	if (className == NULL) {
		return;
	}

	className = UTF8ToString(className);

	return Atom.atom_element_class_exists(element, className);
});

ATOM_JS(void, atom_remove_element_class, (ATOM_ELEMENT_REFERENCE element, const char* className), {
	if (className == NULL) {
		return;
	}

	className = UTF8ToString(className);

	Atom.atom_remove_element_class(element, className);
});

ATOM_JS(char*, atom_get_element_node_name, (ATOM_ELEMENT_REFERENCE element), {
	const name = Atom.atom_get_element_node_name(element);
	
	if (name) {
		return Atom.atom_to_pointer(name);
	}

	return NULL;
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, atom_get_element_parent, (ATOM_ELEMENT_REFERENCE element), {
	return Atom.atom_get_element_parent(element);
});

ATOM_JS(Auint32, atom_get_element_child_count, (ATOM_ELEMENT_REFERENCE element), {
	return Atom.atom_get_element_child_count(element);
});

ATOM_JS(void, atom_scroll_to_element, (ATOM_ELEMENT_REFERENCE element, const char* viewType), {
	if (!viewType == NULL) {
		viewType = UTF8ToString(viewType);
		Atom.atom_scroll_to_element(element, viewType);
		
		return;
	}

	Atom.atom_scroll_to_element(element);
});

#endif

ATOM_JS(bool, atom_is_function_registered, (const char* name), {
	name = UTF8ToString(name);
	
	return Atom.atom_is_function_registered(name);
});

ATOM_JS(void, atom_unregister_function, (const char* name), {
	name = UTF8ToString(name);

	return Atom.atom_unregister_function(name);
});

ATOM_JS(ATOM_FUNCTION, atom_get_function, (const char* name), {
	name = UTF8ToString(name);

	return Atom.atom_get_function_pointer(name);
});

ATOM_JS(bool, atom_is_multi_thread_enabled, (), {
	return Atom.atom_is_multi_thread_enabled();
});

ATOM_JS(char*, atom_get_process_name, (), {
	return Atom.atom_to_pointer(Atom.atom_get_process_name());
});

ATOM_JS(bool, atom_is_main_process, (), {
	return Atom.atom_is_main_process();
});

ATOM_JS(void, atom_fork, (const char* name), {
	if (name == NULL) {
		name = Atom.atom_generage_random_key();
	}else{
		name = UTF8ToString(name);
	}

	Atom.atom_fork(name);
});

ATOM_JS(void, atom_post_child_process, (const char* name, ATOM_OBJECT_HANDLE data), {
	name = UTF8ToString(name);

	data = Emval.toValue(data);

	Atom.atom_post_child_process(name, data);
});

ATOM_JS(bool, atom_child_process_exists, (const char* name), {
	name = UTF8ToString(name);

	return Atom.atom_child_process_exists(name);
});

ATOM_JS(bool, atom_child_process_is_ready, (const char* name), {
	name = UTF8ToString(name);

	return Atom.atom_child_process_is_ready(name);
});

#ifdef ATOM_WASM_USE_MULTI_THREAD_DEFINITION

ATOM_JS_ASYNC(void, atom_wait_till_process_be_ready, (const char* name), {
	name = UTF8ToString(name);

	if (!Atom.atom_child_process_exists(name)) {
		return;
	}

	return new Promise(async resolve => {
		while (!Atom.atom_child_process_is_ready(name)) await Atom.atom_sleep(0);

		resolve();
	});
});

#endif

ATOM_JS(void, atom_terminate_child_process, (const char* name), {
	name = UTF8ToString(name);

	Atom.atom_terminate_child_process(name);
});


#ifdef ATOM_WASM_USE_MULTI_THREAD_DEFINITION

ATOM_JS_ASYNC(ATOM_FUNCTION, atom_loadstring_child_process, (const char* name, const char* code), {
	if (name == NULL) {
		return;
	}
	if (code == NULL) {
		return NULL;
	}

	name = UTF8ToString(name);
	code = UTF8ToString(code);

	const caller = await Atom.atom_loadstring_child_process(name, code);

	if (caller) {
		return Atom.atom_to_pointer(caller);
	}

	return NULL;
});

ATOM_JS_ASYNC(ATOM_OBJECT_HANDLE, atom_eval_child_process, (const char* name, const char* code), {
	if (name == NULL) {
		return NULL;
	}
	if (code == NULL) {
		return NULL;
	}

	name = UTF8ToString(name);
	code = UTF8ToString(code);

	const result = await Atom.atom_eval_child_process(name, code);

	if (result) {
		return Emval.toHandle(result);
	}

	return NULL;
});

ATOM_JS_ASYNC(void, atom_yield, (), {
	await Atom.atom_yield();
});

#endif

ATOM_JS(void, atom_resume, (const char* name), {
	name = UTF8ToString(name);

	Atom.atom_resume(name);
});

ATOM_JS(bool, atom_function_pointer_exists, (ATOM_FUNCTION func), {
	return Atom.atom_function_pointer_exists(func);
});

ATOM_JS(void, atom_delete_function_pointer, (ATOM_FUNCTION func), {
	Atom.atom_delete_function_pointer(func);
});

#ifdef ATOM_WASM_USE_MULTI_THREAD_DEFINITION

ATOM_JS_ASYNC(void, atom_register_shared_function, (const char* name, ATOM_FUNCTION func, bool clearMemory), {
	if (name == NULL) {
		return;
	}
	if (func == NULL) {
		return;
	}

	name = UTF8ToString(name);

	const processName = Atom.atom_get_process_name();
	
	await Atom.atom_register_shared_function(name, func, clearMemory, processName);
});

ATOM_JS_ASYNC(bool, atom_shared_function_exists, (const char* name), {
	if (name == NULL) {
		return false;
	}

	name = UTF8ToString(name);

	return await Atom.atom_shared_function_exists(name);
});

ATOM_JS_ASYNC(void, atom_remove_shared_function, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	return await Atom.atom_remove_shared_function(name);
});

ATOM_JS_ASYNC(char*, atom_get_shared_function_process, (const char* name), {
	if (name == NULL) {
		return NULL;
	}

	name = UTF8ToString(name);

	const process = await Atom.atom_get_shared_function_process(name);

	return Atom.atom_to_pointer(process);
});

ATOM_JS_ASYNC(ATOM_FUNCTION, atom_get_shared_function, (const char* name), {
	if (name == NULL) {
		return NULL;
	}

	name = UTF8ToString(name);

	const func = await Atom.atom_get_shared_function(name);

	if (func == NULL) {
		return NULL;
	}

	return Atom.atom_to_pointer(func);
});

ATOM_JS_ASYNC(void, atom_allocate_shared_memory, (const char* name, size_t size), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	await Atom.atom_allocate_shared_memory(name, size);
});

ATOM_JS_ASYNC(bool, atom_shared_memory_exists, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	return await Atom.atom_shared_memory_exists(name);
});

ATOM_JS_ASYNC(ATOM_POINTER_REFERENCE, atom_get_shared_memory_pointer, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	return await Atom.atom_get_shared_memory_pointer(name);
});

ATOM_JS_ASYNC(size_t, atom_get_shared_memory_size, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	return await Atom.atom_get_shared_memory_size(name);
});

ATOM_JS_ASYNC(void, atom_free_shared_memory, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	await Atom.atom_free_shared_memory(name);
});

ATOM_JS_ASYNC(ATOM_POINTER, atom_get_shared_memory, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	return await Atom.atom_get_shared_memory(name);
});

ATOM_JS_ASYNC(void, atom_update_shared_memory, (const char* name, const char* process), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);
	process = process == NULL ? null : UTF8ToString(process);

	await Atom.atom_update_shared_memory(name, process);
});

ATOM_JS_ASYNC(void, atom_update_main_shared_memory, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	await Atom.atom_update_main_shared_memory(name);
});

#endif

ATOM_JS(ATOM_POINTER, atom_get_pointer_from_reference, (ATOM_POINTER_REFERENCE reference), {
	return reference;
});

ATOM_JS(ATOM_POINTER_REFERENCE, atom_get_pointer_reference, (ATOM_POINTER pointer), {
	return pointer;
});

ATOM_JS(ATOM_ANIMATION_FRAME, atom_request_animation_frame, (ATOM_ANIMATION_FRAME_HANDLER handler, ATOM_POINTER value), {
	if (handler == NULL) {
		return;
	}

	return Atom.atom_request_animation_frame(handler, value);
});

ATOM_JS(bool, atom_exists_animation_frame, (ATOM_ANIMATION_FRAME id), {
	return Atom.atom_exists_animation_frame(id);
});

ATOM_JS(void, atom_cancel_animation_frame, (ATOM_ANIMATION_FRAME id), {
	Atom.atom_cancel_animation_frame(id);
});

ATOM_JS(double, atom_mod_number, (double a, double b), {
	return (a % b);
});

ATOM_JS(ATOM_ANIMATION_FRAME_HANDLER, atom_get_animation_frame_handler, (ATOM_ANIMATION_FRAME id), {
	return Atom.atom_get_animation_frame_handler(id);
});

ATOM_JS(ATOM_TIMER_REFERENCE, atom_set_timeout, (ATOM_TIMER_HANDLE func, Auint32 ms, ATOM_POINTER arg), {
	if (func == NULL) {
		return NULL;
	}

	const handle = wasmTable.get(func);

	if (typeof handle != "function") {
		return NULL;
	}

	return setTimeout(handle, ms, arg);
});

ATOM_JS(void, atom_clear_timeout, (ATOM_TIMER_REFERENCE timer), {
	clearTimeout(timer);
});

ATOM_JS(ATOM_TIMER_REFERENCE, atom_set_interval, (ATOM_TIMER_HANDLE func, Auint32 ms, ATOM_POINTER arg), {
	if (func == NULL) {
		return NULL;
	}

	const handle = wasmTable.get(func);

	if (typeof handle != "function") {
		return NULL;
	}

	return setInterval(handle, ms, arg);
});

ATOM_JS(void, atom_clear_interval, (ATOM_TIMER_REFERENCE timer), {
	clearInterval(timer);
});

ATOM_JS(float, atom_get_pixel_ratio, (), {
	return Atom.atom_get_pixel_ratio();
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, atom_create_render_target, (Auint32 width, Auint32 height, float ratio, bool alpha, const char* colorSpace, bool desynchronized, bool willReadFrequently), {
	colorSpace = colorSpace == NULL ? undefined : UTF8ToString(colorSpace);

	return Atom.atom_create_render_target(width, height, ratio, alpha, colorSpace, desynchronized, willReadFrequently);
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, atom_create_path2D, (), {
	return Atom.atom_create_path2D();
});

ATOM_JS(bool, atom_is_element_render_target, (ATOM_ELEMENT_REFERENCE element), {
	return Atom.atom_is_element_render_target(element);
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, atom_get_render_target_canvas, (ATOM_ELEMENT_REFERENCE element), {
	return Atom.atom_get_render_target_canvas(element);
});

ATOM_JS(float, atom_get_render_target_ratio, (ATOM_ELEMENT_REFERENCE element), {
	return Atom.atom_get_render_target_ratio(element);
});

ATOM_JS(void, atom_resize_render_target, (ATOM_ELEMENT_REFERENCE element, Auint32 width, Auint32 height, float ratio), {
	Atom.atom_resize_render_target(element, width, height, ratio);
});

ATOM_JS(Auint32, atom_get_render_target_width, (ATOM_ELEMENT_REFERENCE element), {
	return Atom.atom_get_render_target_width(element);
});

ATOM_JS(Auint32, atom_get_render_target_height, (ATOM_ELEMENT_REFERENCE element), {
	return Atom.atom_get_render_target_height(element);
});

ATOM_JS(Auint32, atom_get_render_target_real_width, (ATOM_ELEMENT_REFERENCE element), {
	return Atom.atom_get_render_target_real_width(element);
});

ATOM_JS(Auint32, atom_get_render_target_real_height, (ATOM_ELEMENT_REFERENCE element), {
	return Atom.atom_get_render_target_real_height(element);
});

ATOM_JS(ATOM_RT_PIXEL*, atom_get_render_target_pixels, (ATOM_ELEMENT_REFERENCE element, Auint32 x, Auint32 y, Auint32 width, Auint32 height, Auint32* size), {
	const imageData = Atom.atom_get_render_target_pixels(element, x, y, width, height);
	
	if (!imageData) {
		return NULL;
	}

	const data = imageData.data;
	
	const pixels = _malloc(data.byteLength);

	const heap = new Uint8Array(HEAPU8.buffer, pixels, data.byteLength);
	heap.set(new Uint8Array(data));

	const sizeHeap = new Uint32Array(HEAPU8.buffer, size, 1);
	sizeHeap.set(new Uint32Array([data.byteLength]));

	return pixels;
});

ATOM_JS(void, atom_set_render_target_pixels, (ATOM_ELEMENT_REFERENCE element, ATOM_RT_PIXEL* pixels, Auint32 x, Auint32 y, Auint32 width, Auint32 height, Aint32 dirtyX, Aint32 dirtyY, Aint32 dirtyWidth, Aint32 dirtyHeight), {
	if (pixels == NULL) {
		return;
	}

	width = Atom.atom_rt_filter_coord_by_ratio(width, element);
	height = Atom.atom_rt_filter_coord_by_ratio(height, element);

	pixels = new Uint8Array(HEAPU8.buffer, pixels, width * height * 4);

	const imageData = new ImageData(new Uint8ClampedArray(pixels), width, height);

	Atom.atom_set_render_target_pixels(element, imageData, x, y, dirtyX, dirtyY, dirtyWidth, dirtyHeight);
});

ATOM_JS(void, atom_set_render_target, (ATOM_ELEMENT_REFERENCE element), {
	Atom.atom_set_render_target(element);
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, atom_get_selected_render_target, (), {
	return Atom.atom_get_selected_render_target();
});

ATOM_JS(void, atom_set_render_target_property, (ATOM_ELEMENT_REFERENCE element, const char* propertyName, const char* value), {
	propertyName = UTF8ToString(propertyName);
	value = UTF8ToString(value);

	Atom.atom_set_render_target_property(element, propertyName, value);
});

ATOM_JS(char*, atom_get_render_target_property, (ATOM_ELEMENT_REFERENCE element, const char* propertyName), {
	propertyName = UTF8ToString(propertyName);

	return Atom.atom_to_pointer(Atom.atom_get_render_target_property(element, propertyName));
});

ATOM_JS(void, atom_rt_set_direction, (const char* direction), {
	direction = UTF8ToString(direction);

	Atom.atom_rt_set_direction(direction);
});

ATOM_JS(char*, atom_rt_get_direction, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_direction());
});

ATOM_JS(void, atom_rt_set_fill_style, (const char* style), {
	style = UTF8ToString(style);

	Atom.atom_rt_set_fill_style(style);
});

ATOM_JS(char*, atom_rt_get_fill_style, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_fill_style());
});

ATOM_JS(void, atom_rt_set_filter, (const char* style), {
	style = UTF8ToString(style);

	Atom.atom_rt_set_filter(style);
});

ATOM_JS(char*, atom_rt_get_filter, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_filter());
});

ATOM_JS(void, atom_rt_set_font, (const char* style), {
	style = UTF8ToString(style);

	Atom.atom_rt_set_font(style);
});

ATOM_JS(char*, atom_rt_get_font, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_font());
});

ATOM_JS(void, atom_rt_set_font_kerning, (const char* style), {
	style = UTF8ToString(style);

	Atom.atom_rt_set_font_kerning(style);
});

ATOM_JS(char*, atom_rt_get_font_kerning, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_font_kerning());
});

ATOM_JS(void, atom_rt_set_global_alpha, (float alpha), {
	Atom.atom_rt_set_global_alpha(alpha);
});

ATOM_JS(float, atom_rt_get_global_alpha, (), {
	return Atom.atom_rt_get_global_alpha();
});

ATOM_JS(void, atom_rt_set_global_composite_operation, (const char* op), {
	op = UTF8ToString(op);

	Atom.atom_rt_set_global_composite_operation(op);
});

ATOM_JS(char*, atom_rt_get_global_composite_operation, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_global_composite_operation());
});

ATOM_JS(void, atom_rt_set_image_smoothing_enabled, (bool state), {
	Atom.atom_rt_set_image_smoothing_enabled(state);
});

ATOM_JS(bool, atom_rt_is_image_smoothing_enabled, (), {
	return Atom.atom_rt_is_image_smoothing_enabled();
});

ATOM_JS(void, atom_rt_set_image_smoothing_quality, (const char* quality), {
	quality = UTF8ToString(quality);

	Atom.atom_rt_set_image_smoothing_quality(quality);
});

ATOM_JS(char*, atom_rt_get_image_smoothing_quality, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_image_smoothing_quality());
});

ATOM_JS(void, atom_rt_set_letter_spacing, (const char* style), {
	style = UTF8ToString(style);

	Atom.atom_rt_set_letter_spacing(style);
});

ATOM_JS(char*, atom_rt_get_letter_spacing, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_letter_spacing());
});

ATOM_JS(void, atom_rt_set_line_cap, (const char* style), {
	style = UTF8ToString(style);

	Atom.atom_rt_set_line_cap(style);
});

ATOM_JS(char*, atom_rt_get_line_cap, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_line_cap());
});

ATOM_JS(void, atom_rt_set_line_dash_offset, (float offset), {
	Atom.atom_rt_set_line_dash_offset(offset);
});

ATOM_JS(float, atom_rt_get_line_dash_offset, (), {
	return Atom.atom_rt_get_line_dash_offset();
});

ATOM_JS(void, atom_rt_set_line_join, (const char* style), {
	style = UTF8ToString(style);

	Atom.atom_rt_set_line_join(style);
});

ATOM_JS(char*, atom_rt_get_line_join, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_line_join());
});

ATOM_JS(void, atom_rt_set_line_width, (float width), {
	Atom.atom_rt_set_line_width(width);
});

ATOM_JS(float, atom_rt_get_line_width, (), {
	return Atom.atom_rt_get_line_width();
});

ATOM_JS(void, atom_rt_set_miter_limit, (float limit), {
	Atom.atom_rt_set_miter_limit(limit);
});

ATOM_JS(float, atom_rt_get_miter_limit, (), {
	return Atom.atom_rt_get_miter_limit();
});

ATOM_JS(void, atom_rt_set_shadow_blur, (float level), {
	Atom.atom_rt_set_shadow_blur(level);
});

ATOM_JS(float, atom_rt_get_shadow_blur, (), {
	return Atom.atom_rt_get_shadow_blur();
});

ATOM_JS(void, atom_rt_set_shadow_color, (const char* style), {
	style = UTF8ToString(style);

	Atom.atom_rt_set_shadow_color(style);
});

ATOM_JS(char*, atom_rt_get_shadow_color, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_shadow_color());
});

ATOM_JS(void, atom_rt_set_shadow_offset, (float x, float y), {
	Atom.atom_rt_set_shadow_offset(x, y);
});

ATOM_JS(float, atom_rt_get_shadow_offset_x, (), {
	return Atom.atom_rt_get_shadow_offset_x();
});

ATOM_JS(float, atom_rt_get_shadow_offset_y, (), {
	return Atom.atom_rt_get_shadow_offset_y();
});

ATOM_JS(void, atom_rt_set_stroke_style, (const char* style), {
	style = UTF8ToString(style);

	Atom.atom_rt_set_stroke_style(style);
});

ATOM_JS(char*, atom_rt_get_stroke_style, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_stroke_style());
});

ATOM_JS(void, atom_rt_set_text_align, (const char* style), {
	style = UTF8ToString(style);

	Atom.atom_rt_set_text_align(style);
});

ATOM_JS(char*, atom_rt_get_text_align, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_text_align());
});

ATOM_JS(void, atom_rt_set_text_baseline, (const char* style), {
	style = UTF8ToString(style);

	Atom.atom_rt_set_text_baseline(style);
});

ATOM_JS(char*, atom_rt_get_text_baseline, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_text_baseline());
});

ATOM_JS(void, atom_rt_set_text_rendering, (const char* style), {
	style = UTF8ToString(style);

	Atom.atom_rt_set_text_rendering(style);
});

ATOM_JS(char*, atom_rt_get_text_rendering, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_text_rendering());
});

ATOM_JS(void, atom_rt_set_word_spacing, (const char* style), {
	style = UTF8ToString(style);

	Atom.atom_rt_set_word_spacing(style);
});

ATOM_JS(char*, atom_rt_get_word_spacing, (), {
	return Atom.atom_to_pointer(Atom.atom_rt_get_word_spacing());
});

ATOM_JS(void, atom_rt_arc, (float x, float y, float radius, float startAngle, float endAngle, bool clockwise), {
	Atom.atom_rt_arc(x, y, radius, startAngle, endAngle, clockwise);
});

ATOM_JS(void, atom_rt_arc_to, (float x1, float y1, float x2, float y2, float radius), {
	Atom.atom_rt_arc_to(x1, y1, x2, y2, radius);
});

ATOM_JS(void, atom_rt_begin_path, (), {
	Atom.atom_rt_begin_path();
});

ATOM_JS(void, atom_rt_bezier_curve_to, (float cp1x, float cp1y, float cp2x, float cp2y, float x, float y), {
	Atom.atom_rt_bezier_curve_to(cp1x, cp1y, cp2x, cp2y, x, y);
});

ATOM_JS(void, atom_rt_clear_rect, (float x, float y, float width, float height), {
	Atom.atom_rt_clear_rect(x, y, width, height);
});

ATOM_JS(void, atom_rt_clip, (ATOM_ELEMENT_REFERENCE path, const char* fillRule), {
	if (fillRule != NULL) {
		fillRule = UTF8ToString(fillRule);
	}

	Atom.atom_rt_clip(path, fillRule);
});

ATOM_JS(void, atom_rt_close_path, (), {
	Atom.atom_rt_close_path();
});

ATOM_JS(void, atom_rt_draw_focus_if_needed, (ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE path), {
	Atom.atom_rt_draw_focus_if_needed(element, path);
});

ATOM_JS(void, atom_rt_draw_image, (float x, float y, float width, float height, ATOM_ELEMENT_REFERENCE image), {
	Atom.atom_rt_draw_image(x, y, width, height, image);
});

ATOM_JS(void, atom_rt_draw_image_section, (float x, float y, float width, float height, float dx, float dy, float dWidth, float dHeight, ATOM_ELEMENT_REFERENCE image), {
	Atom.atom_rt_draw_image_section(x, y, width, height, dx, dy, dWidth, dHeight, image);
});

ATOM_JS(void, atom_rt_ellipse, (float x, float y, float radiusX, float radiusY, float rotation, float startAngle, float endAngle, bool clockwise), {
	Atom.atom_rt_ellipse(x, y, radiusX, radiusY, rotation, startAngle, endAngle, clockwise);
});

ATOM_JS(void, atom_rt_fill, (ATOM_ELEMENT_REFERENCE path, const char* fillRule), {
	if (fillRule != NULL) {
		fillRule = UTF8ToString(fillRule);
	}

	Atom.atom_rt_fill(path, fillRule);
});

ATOM_JS(void, atom_rt_fill_rect, (float x, float y, float width, float height), {
	Atom.atom_rt_fill_rect(x, y, width, height);
});

ATOM_JS(void, atom_rt_fill_text, (const char* text, float x, float y, float maxWidth), {
	text = UTF8ToString(text);

	Atom.atom_rt_fill_text(text, x, y, maxWidth);
});

ATOM_JS(Aint32*, atom_rt_get_line_dash, (Auint32* length), {
	const lengthPointer = length;
	const lengthPointerSize = 4;

	const dash = Atom.atom_rt_get_line_dash();
	
	if (!dash || dash.length < 1) {
		const lengthHeap = new Uint32Array(HEAPU8.buffer, lengthPointer, 1);
		lengthHeap.set(new Uint32Array([0]));
		return NULL;
	}

	const dashSize = dash.length * lengthPointerSize;
	const dashData = _malloc(dashSize);

	const dataHeap = new Int32Array(HEAP8.buffer, dashData, dashSize);
	dataHeap.set(new Int32Array(dash));

	const lengthHeap = new Uint32Array(HEAPU8.buffer, lengthPointer, 1);
	lengthHeap.set(new Uint32Array([dash.length]));

	return dashData;
});

ATOM_JS(bool, atom_rt_is_context_lost, (), {
	return Atom.atom_rt_is_context_lost();
});

ATOM_JS(bool, atom_rt_is_point_in_path, (float x, float y, ATOM_ELEMENT_REFERENCE path, const char* fillRule), {
	if (fillRule != NULL) {
		fillRule = UTF8ToString(fillRule);
	}

	return Atom.atom_rt_is_point_in_path(x, y, path, fillRule);
});

ATOM_JS(bool, atom_rt_is_point_in_stroke, (float x, float y, ATOM_ELEMENT_REFERENCE path), {
	return Atom.atom_rt_is_point_in_stroke(x, y, path);
});

ATOM_JS(void, atom_rt_line_to, (float x, float y), {
	Atom.atom_rt_line_to(x, y);
});

ATOM_JS(void, atom_rt_move_to, (float x, float y), {
	Atom.atom_rt_move_to(x, y);
});

ATOM_JS(void, atom_rt_quadratic_curve_to, (float cpx, float cpy, float x, float y), {
	Atom.atom_rt_quadratic_curve_to(cpx, cpy, x, y);
});

ATOM_JS(void, atom_rt_rect, (float x, float y, float width, float height), {
	Atom.atom_rt_rect(x, y, width, height);
});

ATOM_JS(void, atom_rt_reset, (), {
	Atom.atom_rt_reset();
});

ATOM_JS(void, atom_rt_reset_transform, (), {
	Atom.atom_rt_reset_transform();
});

ATOM_JS(void, atom_rt_restore, (), {
	Atom.atom_rt_restore();
});

ATOM_JS(void, atom_rt_rotate, (float angle), {
	Atom.atom_rt_rotate(angle);
});

ATOM_JS(void, atom_rt_round_rect, (float x, float y, float width, float height, float* radii, Auint32 radiiSize), {
	const heap = new Float32Array(HEAP8.buffer, radii, radiiSize);

	Atom.atom_rt_round_rect(x, y, width, height, [...heap]);
});

ATOM_JS(void, atom_rt_save, (), {
	Atom.atom_rt_save();
});

ATOM_JS(void, atom_rt_scale, (float x, float y), {
	Atom.atom_rt_scale(x, y);
});

ATOM_JS(void, atom_rt_scroll_path_into_view, (ATOM_ELEMENT_REFERENCE path), {
	Atom.atom_rt_scroll_path_into_view(path);
});

ATOM_JS(void, atom_rt_set_line_dash, (Aint32* dash, Auint32 size), {
	if (dash == NULL) {
		return;
	}

	if (size == 0) {
		return;
	}

	const heap = new Int32Array(HEAP8.buffer, dash, size);

	Atom.atom_rt_set_line_dash([...heap]);
});

ATOM_JS(void, atom_rt_stroke, (ATOM_ELEMENT_REFERENCE path), {
	Atom.atom_rt_stroke(path);
});

ATOM_JS(void, atom_rt_stroke_rect, (float x, float y, float width, float height), {
	Atom.atom_rt_stroke_rect(x, y, width, height);
});

ATOM_JS(void, atom_rt_stroke_text, (const char* text, float x, float y, float maxWidth), {
	text = UTF8ToString(text);

	Atom.atom_rt_stroke_text(text, x, y, maxWidth);
});

ATOM_JS(void, atom_rt_translate, (float x, float y), {
	Atom.atom_rt_translate(x, y);
});

ATOM_C_ENV_OPEN

ATOM_ELEMENT_REFERENCE atom_document_query_selector(const char* query) {
	return _atom_document_query_selector(query);
}

ATOM_ELEMENT_REFERENCE atom_query_selector(ATOM_ELEMENT_REFERENCE element, const char* query) {
	return _atom_query_selector(element, query);
}

ATOM_ELEMENT_REFERENCE_LIST atom_document_query_selector_all(const char* query, Auint32* size) {
	ATOM_POINTER list = _atom_document_query_selector_all_pointer(query);

	if (!list) {
		return NULL;
	}

	if (size) {
		*size = _atom_get_temp_value();
	}

	return (ATOM_ELEMENT_REFERENCE_LIST)list;

	/*ATOM_ELEMENT_REFERENCE_LIST list = ATOM_ELEMENT_REFERENCE_LIST();

	if (data == NULL) {
		return list;
	}

	ATOM_ELEMENT_REFERENCE* elements = (ATOM_ELEMENT_REFERENCE*)data;

	size_t size = _atom_get_temp_value();

	for (size_t i = 0; i < size; list.push_back(elements[i++]));

	free(data);

	return list;*/
}

ATOM_ELEMENT_REFERENCE_LIST atom_query_selector_all(ATOM_ELEMENT_REFERENCE element, const char* query, Auint32* size) {
	ATOM_POINTER list = _atom_query_selector_all_pointer(element, query);

	if (!list) {
		return NULL;
	}

	if (size) {
		*size = _atom_get_temp_value();
	}

	return (ATOM_ELEMENT_REFERENCE_LIST)list;

	/*ATOM_ELEMENT_REFERENCE_LIST list = ATOM_ELEMENT_REFERENCE_LIST();

	if (data == NULL) {
		return list;
	}

	ATOM_ELEMENT_REFERENCE* elements = (ATOM_ELEMENT_REFERENCE*)data;

	size_t size = _atom_get_temp_value();

	for (size_t i = 0; i < size; list.push_back(elements[i++]));

	free(data);

	return list;*/
}

void atom_free_element_list(ATOM_ELEMENT_REFERENCE_LIST list, Auint32 size) {
	if (!list) {
		return;
	}

	if (size < 1) {
		ATOM_FREE_SAFE(list);
		return;
	}

	for (size_t i = 0; i < size; i++) {
		atom_free_element(list[i]);
	}

	ATOM_FREE_SAFE(list);
	/*if (list.empty()) {
		return;
	}

	for (const ATOM_ELEMENT_REFERENCE& element : list) {
		atom_free_element(element);
	}*/
}

void atom_register_function(const char* name, ATOM_FUNCTION handler) {
	if (name == NULL) {
		return;
	}
	if (handler == NULL) {
		return;
	}

	ATOM_DIRECT_ASM({
		Atom.atom_register_function($0, $1);
	}, name, handler);
}

char* atom_generage_random_key(const int& count) {
	const char   characters[] = "abcdefghijklmnopqrstuvwxyz123456789!@#$%^&*()_+[]{}";
	const size_t charLength = strlen(characters);

	char* key = new char[count + 1];

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < count; i++) {
		float        randomNumber = (float)std::rand() / (float)RAND_MAX;
		unsigned int index = (unsigned int)(randomNumber * (float)charLength);

		key[i] = characters[index];
	}

	key[count] = '\0';

	return key;
}

ATOM_BOUNDING_BOX atom_get_element_bounding_box(ATOM_ELEMENT_REFERENCE element) {
	ATOM_POINTER data = _atom_get_element_bounding_box(element);

	if (data == NULL) {
		return (ATOM_BOUNDING_BOX)0;
	}

	ATOM_BOUNDING_BOX* boxref = (ATOM_BOUNDING_BOX*)data;

	ATOM_BOUNDING_BOX box = *boxref;

	free(data);

	return box;
}

void atom_document_add_event_listener(const char* eventName, ATOM_EVENT_HANDLER handler) {
	if (eventName == NULL) {
		return;
	}
	if (handler == NULL) {
		return;
	}

	const char eventFunctionName[] = ATOM_EVENT_FUNCTION_NAME;

	atom_register_function(eventFunctionName, (ATOM_FUNCTION)handler);

	ATOM_DIRECT_ASM({
		const functionName = UTF8ToString($0);
		const eventName = UTF8ToString($1);

		const handler = Atom.atom_get_function(functionName, "asm");
		if (handler) {
			self.addEventListener(eventName, event => {
				handler(Emval.toHandle(event));
			});
		}
	}, eventFunctionName, eventName);

	atom_unregister_function(eventFunctionName);
}

void atom_add_event_listener(ATOM_ELEMENT_REFERENCE element, const char* eventName, ATOM_EVENT_HANDLER handler) {
	if (eventName == NULL) {
		return;
	}
	if (handler == NULL) {
		return;
	}

	const char eventFunctionName[] = ATOM_EVENT_FUNCTION_NAME;

	if (atom_is_main_process()) {
		atom_register_function(eventFunctionName, (ATOM_FUNCTION)handler);

		ATOM_DIRECT_ASM({
			const functionName = UTF8ToString($0);
			const eventName = UTF8ToString($1);
			var   element = $2;

			if (!Atom.atom_element_exists(element)) {
				return;
			}

			element = Atom.AtomElements[element];
			if (!element) {
				return;
			}

			const handler = Atom.atom_get_function(functionName, "asm");
			if (handler) {
				element.addEventListener(eventName, event => {
					handler(Emval.toHandle(event));
				});
			}
		}, eventFunctionName, eventName, element);

		atom_unregister_function(eventFunctionName);
	}
}

ATOM_RT_ATTRIBUTES* atom_get_render_target_attributes(ATOM_ELEMENT_REFERENCE element) {
	const Auint32 obj_size = sizeof(ATOM_RT_ATTRIBUTES);

	ATOM_RT_ATTRIBUTES* attributes = (ATOM_RT_ATTRIBUTES*)malloc(obj_size);
	attributes->alpha = false;
	attributes->desynchronized = false;
	attributes->willReadFrequently = false;
	
	attributes->colorSpace = (char*)ATOM_DIRECT_ASM({
		const element = $0;
		const attributesPointer = $1;
		const attributesPointerSize = $2;
		const extraSize = $3;

		const attr = Atom.atom_get_render_target_attributes(element);

		if (!attr) {
			return NULL;
		}

		const heap = new Int8Array(HEAP8.buffer, attributesPointer, attributesPointerSize - extraSize);
		heap.set(new Int8Array([
			Number(attr.alpha),
			Number(attr.desynchronized),
			Number(attr.willReadFrequently == "undefined" ? false : attr.willReadFrequently)
		]));

		return Atom.atom_to_pointer(attr.colorSpace);
	}, element, &attributes, obj_size, sizeof(char*));

	return attributes;
}

void atom_free_rt_attributes(ATOM_RT_ATTRIBUTES* attributes) {
	if (!attributes) {
		return;
	}
	
	if (attributes->colorSpace) {
		ATOM_FREE_SAFE(attributes->colorSpace);
	}

	ATOM_FREE_SAFE(attributes);
}

ATOM_TEXT_METRICS atom_rt_measure_text(const char* text) {
	ATOM_TEXT_METRICS metrics;
	metrics.actualBoundingBoxAscent = 0;
	metrics.actualBoundingBoxDescent = 0;
	metrics.actualBoundingBoxLeft = 0;
	metrics.actualBoundingBoxRight = 0;
	metrics.fontBoundingBoxAscent = 0;
	metrics.fontBoundingBoxDescent = 0;
	metrics.width = 0;

	if (text == NULL) {
		return metrics;
	}

	ATOM_DIRECT_ASM({
		const text = UTF8ToString($0);
		const metricsPointer = $1;
		const metricsPointerSize = $2;

		const textMetrics = Atom.atom_rt_measure_text(text);

		if (!textMetrics) {
			return;
		}

		const metrics = new Float64Array([
			textMetrics.actualBoundingBoxAscent,
			textMetrics.actualBoundingBoxDescent,
			textMetrics.actualBoundingBoxLeft,
			textMetrics.actualBoundingBoxRight,
			textMetrics.fontBoundingBoxAscent,
			textMetrics.fontBoundingBoxDescent,
			textMetrics.width
		]);

		const heap = new Uint8Array(HEAPU8.buffer, metricsPointer, metricsPointerSize);
		heap.set(new Uint8Array(metrics.buffer));
	}, text, &metrics, sizeof(ATOM_TEXT_METRICS));

	return metrics;
}

ATOM_MATRIX_4* atom_rt_get_transform() {
	const Auint32 obj_size = sizeof(ATOM_MATRIX_4);

	ATOM_MATRIX_4* matrix = (ATOM_MATRIX_4*)malloc(obj_size);
	matrix->m00 = 0.0f;
	matrix->m01 = 0.0f;
	matrix->m02 = 0.0f;
	matrix->m03 = 0.0f;
	matrix->m10 = 0.0f;
	matrix->m11 = 0.0f;
	matrix->m12 = 0.0f;
	matrix->m13 = 0.0f;
	matrix->m20 = 0.0f;
	matrix->m21 = 0.0f;
	matrix->m22 = 0.0f;
	matrix->m23 = 0.0f;
	matrix->m30 = 0.0f;
	matrix->m31 = 0.0f;
	matrix->m32 = 0.0f;
	matrix->m33 = 0.0f;
	
	ATOM_DIRECT_ASM({
		const obj = $0;
		const obj_size = $1;

		const matrix = Atom.atom_rt_get_transform();
		
		if (!matrix) {
			return;
		}

		const data = new Float32Array([
			matrix.m11,
			matrix.m21,
			matrix.m31,
			matrix.m41,
			matrix.m12,
			matrix.m22,
			matrix.m32,
			matrix.m42,
			matrix.m13,
			matrix.m23,
			matrix.m33,
			matrix.m43,
			matrix.m14,
			matrix.m24,
			matrix.m34,
			matrix.m44,
		]);

		const heap = new Uint8Array(HEAPU8.buffer, obj, obj_size);
		heap.set(new Uint8Array(data.buffer));
	}, matrix, obj_size);

	return matrix;
}

void atom_rt_set_transform(ATOM_MATRIX_4* matrix) {
	if (!matrix) {
		return;
	}

	ATOM_DIRECT_ASM(
		{
			const a = $0;
			const c = $1;
			const e = $2;
			const b = $3;
			const d = $4;
			const f = $5;

			Atom.atom_rt_set_transform(a, b, c, d, e, f);
		},
		matrix->m00, matrix->m01, matrix->m02,
		matrix->m10, matrix->m11, matrix->m12
	);
}

void atom_exit(int status, bool pthread) {
	if (pthread) {
		emscripten_force_exit(status);
		return;
	}

	if (atom_is_inside_worker()) {
		ATOM_DIRECT_ASM({
			const processName = Atom.atom_get_process_name();

			Atom.atom_post_child_process("main", {
				command : "terminate",
				fromProcess : processName,
				processName
			});
		});

		#ifdef ATOM_WASM_USE_MULTI_THREAD_DEFINITION
			atom_yield();
		#endif

		return;
	}

	ATOM_DIRECT_ASM({
		for (const processName in Module.ChildProcesses) {
			Atom.atom_terminate_child_process(processName);
		}
	});

	emscripten_force_exit(status);
}

ATOM_C_ENV_CLOSE

#endif