/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomJSDefinitions.cpp
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#include "AtomJSDefinitions.h"

ATOM_JS(void, atom_sleep, (unsigned int ms), {
 	await new Promise(resolve => setTimeout(resolve, ms));
});

ATOM_JS(ATOM_TICK, atom_get_now, (), {
	return atom_get_now();
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

	self.ATOM_MAIN_SCRIPT_PATH = self.ATOM_MAIN_SCRIPT_PATH || null;
	self.ATOM_WORKER_SCRIPT_PATH = self.ATOM_WORKER_SCRIPT_PATH || null;
	self.ATOM_MULTI_THREAD_ENABLED = self.ATOM_MULTI_THREAD_ENABLED || false;
	self.ATOM_PROCESS_NAME = self.ATOM_PROCESS_NAME || "main";
	self.ATOM_FUNCTION_POINTER_SIZE = self.ATOM_FUNCTION_POINTER_SIZE || 8;

	const IsInsideWorker = ENVIRONMENT_IS_WORKER;

	const MAX_INT = 1410065406;

	Module.AtomElements = {};
	Module.ChildProcesses = {};
	Module.ThreadPromises = {};
	Module.SharedFunctions = {};
	Module.SharedMemories = {};
	Module.YieldPromise = null;
	Module.Animations = {};

	Module.AnimationsOffset = 1;

	if (!IsInsideWorker) {
		const script = document.querySelector('script[atom_main]');

		var terminate = false;

		if (script) {
			ATOM_MAIN_SCRIPT_PATH = script.src;

			if (!ATOM_MAIN_SCRIPT_PATH) {
				terminate = true;
			}

			ATOM_WORKER_SCRIPT_PATH = script.getAttribute("atom_worker");
			if (ATOM_WORKER_SCRIPT_PATH && ATOM_WORKER_SCRIPT_PATH.length > 0) {
				ATOM_MULTI_THREAD_ENABLED = true;
			}
		}else{
			terminate = true;
		}

		if (terminate) {
			throw Error("Couldn't find Atom Main script. You have to add `atom_main` attribute to your script element. (example:\n<script src=\"script.js\" atom_main />\n)");
		}

		Module.AtomElements[1] = document.head;
		Module.AtomElements[2] = document.body;
	}

	Module.AtomElementsOffset = 3;
	
	Module.AtomFunctions = {};

	Module.TempValue = 0;

	self.NULL = 0;

	function atom_get_now() {
		return (new Date).getTime();
	}

	function atom_get_main_script_path() {
		return ATOM_MAIN_SCRIPT_PATH;
	}

	function atom_get_worker_script_path() {
		return ATOM_WORKER_SCRIPT_PATH;
	}

	function atom_is_multi_thread_enabled() {
		return ATOM_MULTI_THREAD_ENABLED;
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
		const caller = atom_find_signature_caller(signature);

		if (caller) {
			return caller(pointer, ...args);
		}
	}

	function atom_create_element_reference(element) {
		if (!self.atom_is_main_process()) {
			return;
		}

		var offset = Module.AtomElementsOffset;

		if (offset > MAX_INT) {
			offset = 3;
		}

		while (Module.AtomElements[offset]) offset++;

		const ref = offset++;

		Module.AtomElements[ref] = element;

		Module.AtomElementsOffset = offset;

		return ref;
	}

	function atom_create_element(type) {
		if (typeof type != "string" || type.length < 1) {
			return;
		}

		const element = document.createElement(type);

		return atom_create_element_reference(element);
	}

	function atom_element_exists(element) {
		return Module.AtomElements[element] ? true : false;
	}

	function atom_remove_element_reference(element) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		delete Module.AtomElements[element];
	}

	function atom_destroy_element(element) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		const elm = Module.AtomElements[element];
		if (elm) {
			elm.remove();
		}

		self.atom_remove_element_reference(element);
	}

	function atom_is_same_element(element, target) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		if (!self.atom_element_exists(target)) {
			return;
		}

		element = Module.AtomElements[element];
		target = Module.AtomElements[target];

		return element == target;
	}

	function atom_set_element_attribute(element, attribute, value) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		element = Module.AtomElements[element];
		if (element) {
			element.setAttribute(attribute, value);
		}
	}

	function atom_get_element_attribute(element, attribute) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		element = Module.AtomElements[element];
		if (element) {
			return element.getAttribute(element, attribute);
		}
	}

	function atom_set_element_property(element, property, value) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		element = Module.AtomElements[element];
		if (element) {
			element[property] = value;
		}
	}

	function atom_get_element_property(element, property) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		element = Module.AtomElements[element];
		if (element) {
			return element[property];
		}
	}

	function atom_element_append_child(element, child) {
		if (!self.atom_element_exists(element)) {
			return;
		}
		if (!self.atom_element_exists(child)) {
			return;
		}

		element = Module.AtomElements[element];
		child = Module.AtomElements[child];

		if (element && child) {
			element.appendChild(child);
		}
	}

	function atom_set_element_style(element, property, value) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		element = Module.AtomElements[element];
		if (element) {
			element.style.setProperty(property, value);
		}
	}

	function atom_get_element_style(element, property) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		element = Module.AtomElements[element];
		if (element) {
			return element.style.getPropertyValue(property);
		}
	}
	
	function atom_get_element_bounding_box_bytes(element) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		element = Module.AtomElements[element];
		if (element) {
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
			if (!self.atom_element_exists(element)) {
				return;
			}

			element = Module.AtomElements[element];
		}

		if (element) {
			const selected = element.querySelector(query);
			if (selected) {
				return self.atom_create_element_reference(selected);
			}
		}
	}

	function atom_query_selector_all(element, query) {
		if (!element || element == NULL) {
			element = document;
		}else{
			if (!self.atom_element_exists(element)) {
				return;
			}

			element = Module.AtomElements[element];
		}

		if (element) {
			const list = element.querySelectorAll(query);
			if (list && list.length > 0) {
				const elements = [];
				
				for (const selected of list) {
					elements.push(atom_create_element_reference(selected));
				}

				return elements;
			}
		}
	}

	function atom_add_element_class(element, className) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		element = Module.AtomElements[element];
		if (element) {
			if (element.classList.contains(className)) {
				return;
			}

			element.classList.add(className);
		}
	}

	function atom_element_class_exists(element, className) {
		if (!self.atom_element_exists(element)) {
			return false;
		}

		element = Module.AtomElements[element];
		if (element) {
			return element.classList.contains(className);
		}
	}

	function atom_remove_element_class(element, className) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		element = Module.AtomElements[element];
		if (element) {
			if (!element.classList.contains(className)) {
				return;
			}

			element.classList.remove(className);
		}
	}

	function atom_get_element_node_name(element) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		element = Module.AtomElements[element];
		if (element) {
			return element.nodeName;
		}
	}

	function atom_get_element_parent(element) {
		if (!self.atom_element_exists(element)) {
			return;
		}

		element = Module.AtomElements[element];
		if (element) {
			const parent = element.parentElement;

			return self.atom_create_element_reference(parent);
		}
	}

	function atom_add_event_listener(element, eventName, handler) {
		if (typeof element == "string") {
			handler = eventName;
			eventName = element;
			element = self;
		}else{
			if (!self.atom_element_exists(element)) {
				return;
			}

			element = Module.AtomElements[element];
		}

		if (typeof eventName != "string" || typeof handler != "function") {
			return;
		}

		element.addEventListener(eventName, handler);
	}

	function atom_set_temp_value(value) {
		Module.TempValue = value;
	}

	function atom_register_function(name, handler) {
		name = typeof name == "number" ? UTF8ToString(name) : name;

		if (name && name.length > 0) {
			if (!Module.AtomFunctions[name]) {
				Module.AtomFunctions[name] = handler;
			}
		}
	}

	function atom_is_function_registered(name) {
		if (name && name.length > 0) {
			return Module.AtomFunctions[name] ? true : false;
		}

		return false;
	}

	function atom_unregister_function(name) {
		if (!self.atom_is_function_registered(name)) {
			return;
		}

		Module.AtomFunctions[name] = undefined;
		delete Module.AtomFunctions[name];
	}

	function atom_get_function_pointer(name) {
		if (!self.atom_is_function_registered(name)) {
			return NULL;
		}

		return Module.AtomFunctions[name];
	}

	function atom_get_function(name, signature) {
		if (!self.atom_is_function_registered(name)) {
			return;
		}

		const functionPointer = self.atom_get_function_pointer(name);

		var caller;

		if (typeof signature == "string" && signature.length > 0) {
			caller = self.atom_find_signature_caller(signature);
		}else{
			caller = self.atom_dynamic_call;
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
		}else if (value instanceof Uint32Array) {
			var size = value.byteLength;

			var pointer = _malloc(size);

			var heap = new Uint8Array(HEAPU8.buffer, pointer, size);
			heap.set(new Uint8Array(value.buffer));

			return pointer;
		}else if (typeof value == "function") {
			var pointer = _malloc(ATOM_FUNCTION_POINTER_SIZE);

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
		return ATOM_PROCESS_NAME;
	}

	function atom_is_main_process() {
		return !self.atom_is_inside_worker();
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
			self.atom_terminate_child_process(processName);
		}else if (cmd == "ready") {
			Module.ChildProcesses[processName].ready = true;
		}else if (cmd == "alert") {
			alert(message);
		}else if (cmd == "post") {
			self.atom_post_child_process(processName, message);
		}else if (cmd == "resume") {
			if (processName == self.atom_get_process_name()) {
				const resolver = Module.YieldPromise;
				if (resolver) {
					resolver(data.result);
				}
			}else{
				self.atom_post_child_process(processName, {
					command : cmd,
					processName,
					fromProcess,
					result : data.result
				});
			}
		}else if (cmd == "calln" || cmd == "callm") {
			if (processName == self.atom_get_process_name()) {
				var result = undefined;

				const func = (cmd == "callm" ? Module : self)[functionName];
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
				
				if (fromProcess == processName) await self.atom_sleep(0);

				self.atom_post_child_process(fromProcess, {
					command : "result",
					processName : fromProcess,
					fromProcess : processName,
					key,
					result
				});
			}else{
				self.atom_post_child_process(processName, {
					command : cmd,
					processName,
					fromProcess,
					key,
					functionName,
					functionArgs
				});
			}
		}else if (cmd == "result") {
			if (processName == self.atom_get_process_name()) {
				const resolvers = fromProcess == processName ? Module.ThreadPromises : Module.ChildProcesses[fromProcess].resolvers;

				const resolver = resolvers[key];
				if (resolver) {
					resolver(data.result);
				}

				delete resolvers[key];
			}else{
				self.atom_post_child_process(processName, {
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
			name = self.atom_generage_random_key();
		}

		if (name == "main") {
			throw Error("You can't create a child process with name `main`");
		}

		if (!self.atom_is_multi_thread_enabled()) {
			throw Error("Atom multi thread is not enabled!");
		}

		if (self.atom_child_process_exists(name)) {
			return;
		}

		const process = new Worker(self.atom_get_worker_script_path());
		if (!process) {
			throw Error("Couldn't create child process `" + name + "` !");
		}

		Module.ChildProcesses[name] = { thread : process, ready : false, resolvers : {} };

		process.onmessage = _atom_handle_process_message;

		process.postMessage({
			command: "load",
			atomMainScriptPath : self.atom_get_main_script_path(),
			workerScriptPath : self.atom_get_worker_script_path(),
			processName : name,
			fromProcess : self.atom_get_process_name()
		});
	}

	function atom_post_child_process(name, message) {
		const currentProcessName = self.atom_get_process_name();

		if (!self.atom_is_main_process()) {
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

		if (!self.atom_child_process_exists(name)) {
			return;
		}

		message.tempValue = Module.TempValue;

		Module.ChildProcesses[name].thread.postMessage(message);
	}

	function atom_child_process_exists(name) {
		if (!name || name == NULL) {
			return false;
		}

		if (name == "main") {
			return true;
		}

		return Module.ChildProcesses[name] ? true : false;
	}

	function atom_child_process_is_ready(name) {
		if (!self.atom_child_process_exists(name)) {
			return false;
		}

		return Module.ChildProcesses[name].ready;
	}

	function atom_terminate_child_process(name) {
		if (!self.atom_child_process_exists(name)) {
			return;
		}

		Module.ChildProcesses[name].thread.terminate();

		Module.ChildProcesses[name] = undefined;
		delete Module.ChildProcesses[name];
	}

	function atom_call_child_process_native(name, functionName, ...args) {
		var promiseHandler = () => {};

		const key = atom_generage_random_key();
		const currentProcess = atom_get_process_name();

		if (self.atom_is_main_process()) {
			if (name == currentProcess) {
				promiseHandler = resolver => Module.ThreadPromises[key] = resolver;
			}else{
				if (!atom_child_process_exists(name)) {
					return;
				}

				promiseHandler = resolver => Module.ChildProcesses[name].resolvers[key] = resolver;
			}
		}else{
			promiseHandler = resolver => Module.ThreadPromises[key] = resolver;
		}

		self.atom_post_child_process(name, {
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
		const key = atom_generage_random_key();
		const currentProcess = atom_get_process_name();

		if (
			self.atom_is_main_process() &&
			name != currentProcess &&
			!self.atom_child_process_exists(name)
		) {
			return;
		}

		self.atom_post_child_process(name, {
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

		const key = self.atom_generage_random_key();
		const currentProcess = self.atom_get_process_name();

		if (self.atom_is_main_process()) {
			if (name == currentProcess) {
				promiseHandler = resolver => Module.ThreadPromises[key] = resolver;
			}else{
				if (!self.atom_child_process_exists(name)) {
					return;
				}

				promiseHandler = resolver => Module.ChildProcesses[name].resolvers[key] = resolver;
			}
		}else{
			promiseHandler = resolver => Module.ThreadPromises[key] = resolver;
		}

		self.atom_post_child_process(name, {
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
		const key = self.atom_generage_random_key();
		const currentProcess = self.atom_get_process_name();

		if (
			self.atom_is_main_process() &&
			name != currentProcess &&
			!self.atom_child_process_exists(name)
		) {
			return;
		}

		self.atom_post_child_process(name, {
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
		const currentProcess = self.atom_get_process_name();

		if (process == currentProcess) {
			var caller = () => {};

			eval(`caller = async function() { ${code} };`);

			return caller;
		}

		if (!await self.atom_child_process_exists(process)) {
			return;
		}

		return async function(...args) {
			return await self.atom_call_child_process_native(process, "_atom_eval", code, ...args);
		}
	}

	async function _atom_eval(code, ...args) {
		var caller = () => {};

		eval(`caller = async function() { ${code} };`);

		return await caller(...args);
	}

	async function atom_eval_child_process(process, code, ...args) {
		const currentProcess = self.atom_get_process_name();

		if (process == currentProcess) {
			var caller = () => {};

			eval(`caller = async function() { ${code} };`);

			return await caller(...args);
		}

		return await atom_call_child_process_native(process, "_atom_eval", code, ...args);
	}

	function atom_yield() {
		return new Promise(resolver => {
			Module.YieldPromise = resolver;
		});
	}

	function atom_resume(name, result) {
		const currentProcess = self.atom_get_process_name();

		if (self.atom_is_main_process()) {
			if (name == currentProcess) {
				const resolver = Module.YieldPromise;

				if (resolver) {
					resolver(result);
				}

				return;
			}

			if (!self.atom_child_process_exists(name)) {
				return;
			}
		}

		self.atom_post_child_process(name, {
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
		if (!self.atom_function_pointer_exists(pointer)) {
			return;
		}

		delete wasmTable[pointer];
		_free(pointer);
	}
	
	function atom_register_shared_function(name, handler, clearMemory, process) {
		if (self.atom_shared_function_exists(name)) {
			return;
		}

		if (handler == NULL) {
			return;
		}

		const currentProcess = self.atom_get_process_name();

		const func = { pointer : handler, process : currentProcess, caller : wasmTable[handler] };
		if (clearMemory) {
			func.clearMemory = true;
		}

		if (typeof process == "string" && process != currentProcess) {
			func.process = process;

			func.caller = function(...args) {
				self.atom_post_child_process(process, {
					command : "sfcall",
					processName : process,
					fromProcess : currentProcess,
					pointer : handler,
					functionArgs : args
				});
			};
		}

		Module.SharedFunctions[name] = func;
	}

	function atom_shared_function_exists(name) {
		return Module.SharedFunctions[name] ? true : false;
	}

	function atom_remove_shared_function(name) {
		if (!self.atom_shared_function_exists(name)) {
			return;
		}

		const func = Module.SharedFunctions[name];

		const currentProcess = self.atom_get_process_name();
		const process = func.process;

		if (process != currentProcess) {
			if (func.clearMemory) {
				self.atom_post_child_process(process, {
					command : "sfremove",
					processName : process,
					fromProcess : currentProcess,
					pointer : func.pointer
				});
			}
		}

		delete Module.SharedFunctions[name];
	}

	function atom_get_shared_function_pointer(name) {
		if (!self.atom_shared_function_exists(name)) {
			return NULL;
		}

		return Module.SharedFunctions[name].pointer || NULL;
	}

	function atom_get_shared_function_process(name) {
		if (!self.atom_shared_function_exists(name)) {
			return NULL;
		}

		return Module.SharedFunctions[name].process || NULL;
	}

	function atom_invoke_shared_function(name, ...args) {
		if (!self.atom_shared_function_exists(name)) {
			return;
		}

		Module.SharedFunctions[name].caller(...args);
	}

	async function atom_get_shared_function(name) {
		if (!await self.atom_shared_function_exists(name)) {
			return NULL;
		}

		if (self.atom_is_main_process()) {
			const func = Module.SharedFunctions[name];

			return func.caller;
		}

		return function(...args) {
			self.atom_invoke_shared_function(name, ...args);
		}
	}

	function atom_allocate_shared_memory(name, size) {
		if (self.atom_shared_memory_exists(name)) {
			return;
		}

		if (size < 1) {
			return;
		}

		const pointer = _malloc(size);
		if (!pointer || pointer == NULL) {
			return;
		}

		Module.SharedMemories[name] = { pointer, size };
	}

	function atom_shared_memory_exists(name) {
		return Module.SharedMemories[name] ? true : false;
	}

	async function atom_get_shared_memory_pointer(name) {
		if (!self.atom_is_main_process()) {
			const memory = Module.SharedMemories[name];
			if (memory) {
				return memory.pointer;
			}

			return await self.atom_call_child_process_native("main", "atom_get_shared_memory_pointer", name);
		}

		if (!self.atom_shared_memory_exists(name)) {
			return NULL;
		}

		return Module.SharedMemories[name].pointer;
	}

	async function atom_get_shared_memory_size(name) {
		if (!self.atom_is_main_process()) {
			const memory = Module.SharedMemories[name];
			if (memory) {
				return memory.size;
			}

			return await self.atom_call_child_process_native("main", "atom_get_shared_memory_size", name);
		}

		if (!self.atom_shared_memory_exists(name)) {
			return NULL;
		}

		return Module.SharedMemories[name].size;
	}

	async function atom_free_shared_memory(name) {
		if (!self.atom_is_main_process()) {
			const memory = Module.SharedMemories[name];
			if (memory) {
				_free(memory.pointer);

				delete Module.SharedMemories[name];
			}

			await self.atom_call_child_process_native("main", "atom_free_shared_memory", name);
			return;
		}

		if (!self.atom_shared_memory_exists(name)) {
			return;
		}

		const memory = Module.SharedMemories[name];

		if (!memory || memory == NULL) {
			return NULL;
		}

		_free(memory.pointer);

		delete Module.SharedMemories[name];
	}

	async function atom_get_shared_memory(name) {
		if (!self.atom_is_main_process()) {
			const memory = Module.SharedMemories[name];
			if (memory) {
				return memory.pointer;
			}
		}

		if (!await self.atom_shared_memory_exists(name)) {
			return NULL;
		}

		if (self.atom_is_main_process()) {
			const memory = Module.SharedMemories[name];
			
			return memory.pointer;
		}

		const size = await self.atom_get_shared_memory_size(name);

		if (!size || size == NULL) {
			return NULL;
		}

		const pointer = _malloc(size);

		Module.SharedMemories[name] = { pointer, size };

		await self.atom_update_shared_memory(name);

		return pointer;
	}

	function _atom_on_shared_memory_update(name, buffer) {
		const memory = Module.SharedMemories[name];

		if (!memory || memory == NULL) {
			return;
		}

		const pointer = memory.pointer;
		const size = memory.size;

		const mem = new Uint8Array(HEAPU8.buffer, pointer, size);
		mem.set(new Uint8Array(buffer));
	}

	async function atom_update_shared_memory(name, process) {
		if (!self.atom_shared_memory_exists(name)) {
			return;
		}

		const currentProcess = self.atom_get_process_name();

		const memory = Module.SharedMemories[name];
		const pointer = memory.pointer;
		const size = memory.size;

		const buffer = new ArrayBuffer(size);
		(new Uint8Array(buffer)).set(new Uint8Array(HEAPU8.buffer, pointer, size));

		if (typeof process == "string" && process.length > 0) {
			if (!self.atom_child_process_exists(process)) {
				return;
			}

			await self.atom_call_child_process_native(process, "_atom_on_shared_memory_update", name, buffer);
		}else{
			for (const child_process in Module.ChildProcesses) {
				await self.atom_call_child_process_native(child_process, "_atom_on_shared_memory_update", name, buffer);
			}
		}
	}

	async function atom_update_main_shared_memory(name) {
		if (self.atom_is_main_process()) {
			return;
		}

		const memory = Module.SharedMemories[name];
		if (!memory || memory == NULL) {
			return;
		}

		const pointer = memory.pointer;
		const size = memory.size;

		const buffer = new ArrayBuffer(size);
		(new Uint8Array(buffer)).set(new Uint8Array(HEAPU8.buffer, pointer, size));

		await self.atom_call_child_process_native("main", "_atom_on_shared_memory_update", name, buffer);
	}

	function atom_request_animation_frame(handler, value) {
		if (!handler || handler == NULL) {
			return;
		}

		const cfunction = typeof handler == "function" ? handler : wasmTable.get(handler);
		if (!cfunction) {
			return;
		}

		var offset = Module.AnimationsOffset;

		if (offset > MAX_INT) {
			offset = 1;
		}

		while (Module.Animations[offset]) offset++;

		const ref = offset++;

		const caller = function(tick) {
			const animation = Module.Animations[ref];

			if (animation) {
				cfunction(tick, value);

				requestAnimationFrame(caller);
			}
		};

		Module.Animations[ref] = { pointer : handler, caller };

		Module.AnimationsOffset = offset;

		requestAnimationFrame(caller);

		return ref;
	}

	function atom_exists_animation_frame(id) {
		return Module.Animations[id] ? true : false;
	}

	function atom_cancel_animation_frame(id) {
		if (!self.atom_exists_animation_frame(id)) {
			return;
		}

		delete Module.Animations[id];
	}

	function atom_get_animation_frame_handler(id) {
		if (!self.atom_exists_animation_frame(id)) {
			return;
		}

		return Module.Animations[id].pointer;
	}

	function CreateInternalSharedFunction(func, ifNotMain, dontWait) {
		if (self.atom_is_main_process()) {
			return func;
		}

		if (ifNotMain) {
			return ifNotMain;
		}

		const name = func.name;

		const caller = dontWait ? self.atom_call_child_process_native_no_wait : self.atom_call_child_process_native;
		
		return function() {
			return caller("main", name, ...arguments);
		}
	}

	self.atom_get_now = atom_get_now;
	self.atom_call_child_process_native = atom_call_child_process_native;
	self.atom_call_child_process_native_no_wait = atom_call_child_process_native_no_wait;
	self.atom_call_child_process_module = atom_call_child_process_module;
	self.atom_call_child_process_module_no_wait = atom_call_child_process_module_no_wait;
	self.atom_is_main_process = atom_is_main_process;
	self.atom_get_main_script_path = atom_get_main_script_path;
	self.atom_get_worker_script_path = atom_get_worker_script_path;
	self.atom_is_multi_thread_enabled = atom_is_multi_thread_enabled;
	self.atom_is_inside_worker = atom_is_inside_worker;
	self.atom_dynamic_call = atom_dynamic_call;
	self.atom_find_signature_caller = atom_find_signature_caller;
	self.atom_signature_call = atom_signature_call;
	self.atom_create_element_reference = CreateInternalSharedFunction(atom_create_element_reference);
	self.atom_create_element = CreateInternalSharedFunction(atom_create_element);
	self.atom_element_exists = CreateInternalSharedFunction(atom_element_exists);
	self.atom_remove_element_reference = CreateInternalSharedFunction(atom_remove_element_reference);
	self.atom_destroy_element = CreateInternalSharedFunction(atom_destroy_element);
	self.atom_is_same_element = CreateInternalSharedFunction(atom_is_same_element);
	self.atom_set_element_attribute = CreateInternalSharedFunction(atom_set_element_attribute);
	self.atom_get_element_attribute = CreateInternalSharedFunction(atom_get_element_attribute);
	self.atom_set_element_property = CreateInternalSharedFunction(atom_set_element_property);
	self.atom_get_element_property = CreateInternalSharedFunction(atom_get_element_property);
	self.atom_element_append_child = CreateInternalSharedFunction(atom_element_append_child);
	self.atom_set_element_style = CreateInternalSharedFunction(atom_set_element_style);
	self.atom_get_element_style = CreateInternalSharedFunction(atom_get_element_style);
	self.atom_get_element_bounding_box_bytes = CreateInternalSharedFunction(atom_get_element_bounding_box_bytes);
	self.atom_query_selector = CreateInternalSharedFunction(atom_query_selector);
	self.atom_query_selector_all = CreateInternalSharedFunction(atom_query_selector_all);
	self.atom_add_element_class = CreateInternalSharedFunction(atom_add_element_class);
	self.atom_element_class_exists = CreateInternalSharedFunction(atom_element_class_exists);
	self.atom_remove_element_class = CreateInternalSharedFunction(atom_remove_element_class);
	self.atom_get_element_node_name = CreateInternalSharedFunction(atom_get_element_node_name);
	self.atom_get_element_parent = CreateInternalSharedFunction(atom_get_element_parent);
	self.atom_add_event_listener = atom_add_event_listener;
	self.atom_set_temp_value = atom_set_temp_value;
	self.atom_register_function = atom_register_function;
	self.atom_is_function_registered = atom_is_function_registered;
	self.atom_unregister_function = atom_unregister_function;
	self.atom_get_function_pointer = atom_get_function_pointer;
	self.atom_get_function = atom_get_function;
	self.atom_to_pointer = atom_to_pointer;
	self.atom_generage_random_key = atom_generage_random_key;
	self.atom_get_process_name = atom_get_process_name;
	self.atom_fork = CreateInternalSharedFunction(atom_fork);
	self.atom_post_child_process = atom_post_child_process;
	self.atom_child_process_exists = CreateInternalSharedFunction(atom_child_process_exists);
	self.atom_terminate_child_process = CreateInternalSharedFunction(atom_terminate_child_process);
	self.atom_child_process_is_ready = CreateInternalSharedFunction(atom_child_process_is_ready);
	self.atom_loadstring_child_process = atom_loadstring_child_process;
	self._atom_eval = _atom_eval;
	self.atom_eval_child_process = atom_eval_child_process;
	self.atom_yield = atom_yield;
	self.atom_resume = atom_resume;
	self.atom_sleep = atom_sleep;
	self.atom_function_pointer_exists = atom_function_pointer_exists;
	self.atom_delete_function_pointer = atom_delete_function_pointer;
	self.atom_register_shared_function = CreateInternalSharedFunction(atom_register_shared_function);
	self.atom_shared_function_exists = CreateInternalSharedFunction(atom_shared_function_exists);
	self.atom_remove_shared_function = CreateInternalSharedFunction(atom_remove_shared_function);
	self.atom_get_shared_function_pointer = CreateInternalSharedFunction(atom_get_shared_function_pointer);
	self.atom_get_shared_function_process = CreateInternalSharedFunction(atom_get_shared_function_process);
	self.atom_invoke_shared_function = CreateInternalSharedFunction(atom_invoke_shared_function, null, true);
	self.atom_get_shared_function = atom_get_shared_function;
	self.atom_allocate_shared_memory = CreateInternalSharedFunction(atom_allocate_shared_memory);
	self.atom_shared_memory_exists = CreateInternalSharedFunction(atom_shared_memory_exists);
	self.atom_get_shared_memory_pointer = atom_get_shared_memory_pointer;
	self.atom_get_shared_memory_size = atom_get_shared_memory_size;
	self.atom_free_shared_memory = atom_free_shared_memory;
	self.atom_get_shared_memory = atom_get_shared_memory;
	self._atom_on_shared_memory_update = _atom_on_shared_memory_update;
	self.atom_update_shared_memory = CreateInternalSharedFunction(atom_update_shared_memory);
	self.atom_update_main_shared_memory = atom_update_main_shared_memory;
	self.atom_request_animation_frame = atom_request_animation_frame;
	self.atom_exists_animation_frame = atom_exists_animation_frame;
	self.atom_cancel_animation_frame = atom_cancel_animation_frame;
	self.atom_get_animation_frame_handler = atom_get_animation_frame_handler;

	if (IsInsideWorker) {
		postMessage({
			command: "ready",
			processName : self.atom_get_process_name()
		});
	}
});

ATOM_JS(char*, atom_get_main_script_path, (), {
	return atom_to_pointer(atom_get_main_script_path());
});

ATOM_JS(char*, atom_get_worker_script_path, (), {
	return atom_to_pointer(atom_get_worker_script_path());
});

ATOM_JS(bool, atom_is_inside_worker, (), {
	return atom_is_inside_worker();
});

ATOM_JS(unsigned int, _atom_get_temp_value, (), {
	return Module.TempValue;
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, atom_get_document_head, (), {
	return 1;
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, atom_get_document_body, (), {
	return 2;
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, atom_create_element, (const char* type), {
	if (type == NULL) {
		return NULL;
	}

	type = UTF8ToString(type);

	return await atom_create_element(type);
});

ATOM_JS(bool, atom_element_exists, (ATOM_ELEMENT_REFERENCE element), {
	return await atom_element_exists(element);
});

ATOM_JS(void, atom_destroy_element, (ATOM_ELEMENT_REFERENCE element), {
	await atom_destroy_element(element);
});

ATOM_JS(void, atom_free_element, (ATOM_ELEMENT_REFERENCE element), {
	await atom_remove_element_reference(element);
});

ATOM_JS(bool, atom_is_same_element, (ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE target), {
	return await atom_is_same_element(element, target);
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

	await atom_set_element_attribute(element, attribute, value);
});

ATOM_JS(char*, atom_get_element_attribute, (ATOM_ELEMENT_REFERENCE element, const char* attribute), {
	if (attribute == NULL) {
		return NULL;
	}

	attribute = UTF8ToString(attribute);

	const value = await atom_get_element_attribute(element, attribute);
	if (typeof value == "string") {
		return atom_to_pointer(value);
	}

	return value;
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

	await atom_set_element_property(element, property, value);
});

ATOM_JS(char*, atom_get_element_property, (ATOM_ELEMENT_REFERENCE element, const char* property), {
	if (property == NULL) {
		return NULL;
	}

	property = UTF8ToString(property);

	const value = await atom_get_element_property(element, property);

	if (typeof value == "string") {
		return self.atom_to_pointer(value);
	}

	return value;
});

ATOM_JS(void, atom_element_append_child, (ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE target), {
	await atom_element_append_child(element, target);
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

	await atom_set_element_style(element, property, value);
});

ATOM_JS(char*, atom_get_element_style, (ATOM_ELEMENT_REFERENCE element, const char* property), {
	if (propert == NULL) {
		return NULL;
	}

	property = UTF8ToString(property);

	const value = await atom_get_element_style(element, property);

	if (typeof value == "string") {
		return self.atom_to_pointer(value);
	}

	return value;
});

ATOM_JS(ATOM_POINTER, _atom_get_element_bounding_box, (ATOM_ELEMENT_REFERENCE element), {
	const buffer = await atom_get_element_bounding_box_bytes(element);

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

	return await atom_query_selector(NULL, query);
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, _atom_query_selector, (ATOM_ELEMENT_REFERENCE element, const char* query), {
	if (query == NULL) {
		return NULL;
	}

	query = UTF8ToString(query);

	return await atom_query_selector(element, query);
});

ATOM_JS(ATOM_POINTER, _atom_document_query_selector_all_pointer, (const char* query), {
	if (query == NULL) {
		return NULL;
	}

	query = UTF8ToString(query);

	const elements = await atom_query_selector_all(NULL, query);

	if (elements) {
		atom_set_temp_value(elements.length);

		return self.atom_to_pointer(new Uint32Array(elements));
	}

	return NULL;
});

ATOM_JS(ATOM_POINTER, _atom_query_selector_all_pointer, (ATOM_ELEMENT_REFERENCE element, const char* query), {
	if (query == NULL) {
		return NULL;
	}

	query = UTF8ToString(query);

	const elements = await atom_query_selector_all(element, query);

	if (elements) {
		atom_set_temp_value(elements.length);

		return self.atom_to_pointer(new Uint32Array(elements));
	}

	return NULL;
});

ATOM_JS(void, atom_add_element_class, (ATOM_ELEMENT_REFERENCE element, const char* className), {
	if (className == NULL) {
		return;
	}

	className = UTF8ToString(className);

	await atom_add_element_class(element, className);
});

ATOM_JS(bool, atom_element_class_exists, (ATOM_ELEMENT_REFERENCE element, const char* className), {
	if (className == NULL) {
		return;
	}

	className = UTF8ToString(className);

	return await atom_element_class_exists(element, className);
});

ATOM_JS(void, atom_remove_element_class, (ATOM_ELEMENT_REFERENCE element, const char* className), {
	if (className == NULL) {
		return;
	}

	className = UTF8ToString(className);

	await atom_remove_element_class(element, className);
});

ATOM_JS(char*, atom_get_element_node_name, (ATOM_ELEMENT_REFERENCE element), {
	const name = await atom_get_element_node_name(element);
	
	if (name) {
		return atom_to_pointer(name);
	}

	return NULL;
});

ATOM_JS(ATOM_ELEMENT_REFERENCE, atom_get_element_parent, (ATOM_ELEMENT_REFERENCE element), {
	return await atom_get_element_parent(element);
});

ATOM_JS(bool, atom_is_function_registered, (const char* name), {
	name = UTF8ToString(name);
	
	return atom_is_function_registered(name);
});

ATOM_JS(void, atom_unregister_function, (const char* name), {
	name = UTF8ToString(name);

	return atom_unregister_function(name);
});

ATOM_JS(ATOM_FUNCTION, atom_get_function, (const char* name), {
	name = UTF8ToString(name);

	return atom_get_function_pointer(name);
});

ATOM_JS(bool, atom_is_multi_thread_enabled, (), {
	return atom_is_multi_thread_enabled();
});

ATOM_JS(char*, atom_get_process_name, (), {
	return atom_to_pointer(atom_get_process_name());
});

ATOM_JS(bool, atom_is_main_process, (), {
	return atom_is_main_process();
});

ATOM_JS(void, atom_fork, (const char* name), {
	if (name == NULL) {
		name = atom_generage_random_key();
	}else{
		name = UTF8ToString(name);
	}

	atom_fork(name);
});

ATOM_JS(void, atom_post_child_process, (const char* name, ATOM_JS_VARIABLE_HANDLE data), {
	name = UTF8ToString(name);

	data = Emval.toValue(data);

	atom_post_child_process(name, data);
});

ATOM_JS(bool, atom_child_process_exists, (const char* name), {
	name = UTF8ToString(name);

	return atom_child_process_exists(name);
});

ATOM_JS(bool, atom_child_process_is_ready, (const char* name), {
	name = UTF8ToString(name);

	return atom_child_process_is_ready(name);
});

EM_ASYNC_JS(void, atom_wait_till_process_be_ready, (const char* name), {
	name = UTF8ToString(name);

	if (!atom_child_process_exists(name)) {
		return;
	}

	return new Promise(async resolve => {
		while (!atom_child_process_is_ready(name)) await atom_sleep(0);

		resolve();
	});
});

ATOM_JS(void, atom_terminate_child_process, (const char* name), {
	name = UTF8ToString(name);

	atom_terminate_child_process(name);
});

ATOM_JS(ATOM_FUNCTION, atom_loadstring_child_process, (const char* name, const char* code), {
	if (name == NULL) {
		return;
	}
	if (code == NULL) {
		return NULL;
	}

	name = UTF8ToString(name);
	code = UTF8ToString(code);

	const caller = await atom_loadstring_child_process(name, code);

	if (caller) {
		return atom_to_pointer(caller);
	}

	return NULL;
});

ATOM_JS(ATOM_JS_VARIABLE_HANDLE, atom_eval_child_process, (const char* name, const char* code), {
	if (name == NULL) {
		return NULL;
	}
	if (code == NULL) {
		return NULL;
	}

	name = UTF8ToString(name);
	code = UTF8ToString(code);

	const result = await atom_eval_child_process(name, code);

	if (result) {
		return Emval.toHandle(result);
	}

	return NULL;
});

ATOM_JS(void, atom_yield, (), {
	await atom_yield();
});

ATOM_JS(void, atom_resume, (const char* name), {
	name = UTF8ToString(name);

	atom_resume(name);
});

ATOM_JS(bool, atom_function_pointer_exists, (ATOM_FUNCTION func), {
	return atom_function_pointer_exists(func);
});

ATOM_JS(void, atom_delete_function_pointer, (ATOM_FUNCTION func), {
	atom_delete_function_pointer(func);
});

ATOM_JS(void, atom_register_shared_function, (const char* name, ATOM_FUNCTION func, bool clearMemory), {
	if (name == NULL) {
		return;
	}
	if (func == NULL) {
		return;
	}

	name = UTF8ToString(name);

	const processName = atom_get_process_name();
	
	await atom_register_shared_function(name, func, clearMemory, processName);
});

ATOM_JS(bool, atom_shared_function_exists, (const char* name), {
	if (name == NULL) {
		return false;
	}

	name = UTF8ToString(name);

	return await atom_shared_function_exists(name);
});

ATOM_JS(void, atom_remove_shared_function, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	return await atom_remove_shared_function(name);
});

ATOM_JS(char*, atom_get_shared_function_process, (const char* name), {
	if (name == NULL) {
		return NULL;
	}

	name = UTF8ToString(name);

	const process = await atom_get_shared_function_process(name);

	return atom_to_pointer(process);
});

ATOM_JS(ATOM_FUNCTION, atom_get_shared_function, (const char* name), {
	if (name == NULL) {
		return NULL;
	}

	name = UTF8ToString(name);

	const func = await atom_get_shared_function(name);

	if (func == NULL) {
		return NULL;
	}

	return atom_to_pointer(func);
});

ATOM_JS(void, atom_allocate_shared_memory, (const char* name, size_t size), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	await atom_allocate_shared_memory(name, size);
});

ATOM_JS(bool, atom_shared_memory_exists, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	return await atom_shared_memory_exists(name);
});

ATOM_JS(ATOM_POINTER_REFERENCE, atom_get_shared_memory_pointer, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	return await atom_get_shared_memory_pointer(name);
});

ATOM_JS(size_t, atom_get_shared_memory_size, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	return await atom_get_shared_memory_size(name);
});

ATOM_JS(void, atom_free_shared_memory, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	await atom_free_shared_memory(name);
});

ATOM_JS(ATOM_POINTER, atom_get_shared_memory, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	return await atom_get_shared_memory(name);
});

ATOM_JS(void, atom_update_shared_memory, (const char* name, const char* process), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);
	process = process == NULL ? null : UTF8ToString(process);

	await atom_update_shared_memory(name, process);
});

ATOM_JS(void, atom_update_main_shared_memory, (const char* name), {
	if (name == NULL) {
		return;
	}

	name = UTF8ToString(name);

	await atom_update_main_shared_memory(name);
});

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

	return atom_request_animation_frame(handler, value);
});

ATOM_JS(bool, atom_exists_animation_frame, (ATOM_ANIMATION_FRAME id), {
	return atom_exists_animation_frame(id);
});

ATOM_JS(void, atom_cancel_animation_frame, (ATOM_ANIMATION_FRAME id), {
	atom_cancel_animation_frame(id);
});

ATOM_JS(ATOM_ANIMATION_FRAME_HANDLER, atom_get_animation_frame_handler, (ATOM_ANIMATION_FRAME id), {
	return atom_get_animation_frame_handler(id);
});

ATOM_ELEMENT_REFERENCE atom_query_selector(const char* query) {
	return _atom_document_query_selector(query);
}

ATOM_ELEMENT_REFERENCE atom_query_selector(ATOM_ELEMENT_REFERENCE element, const char* query) {
	return _atom_query_selector(element, query);
}

ATOM_ELEMENT_REFERENCE_LIST atom_query_selector_all(const char* query) {
	ATOM_POINTER data = _atom_document_query_selector_all_pointer(query);

	ATOM_ELEMENT_REFERENCE_LIST list = ATOM_ELEMENT_REFERENCE_LIST();

	if (data == NULL) {
		return list;
	}

	ATOM_ELEMENT_REFERENCE* elements = (ATOM_ELEMENT_REFERENCE*)data;

	size_t size = _atom_get_temp_value();

	for (size_t i = 0; i < size; list.push_back(elements[i++]));

	free(data);

	return list;
}

ATOM_ELEMENT_REFERENCE_LIST atom_query_selector_all(ATOM_ELEMENT_REFERENCE element, const char* query) {
	ATOM_POINTER data = _atom_query_selector_all_pointer(element, query);

	ATOM_ELEMENT_REFERENCE_LIST list = ATOM_ELEMENT_REFERENCE_LIST();

	if (data == NULL) {
		return list;
	}

	ATOM_ELEMENT_REFERENCE* elements = (ATOM_ELEMENT_REFERENCE*)data;

	size_t size = _atom_get_temp_value();

	for (size_t i = 0; i < size; list.push_back(elements[i++]));

	free(data);

	return list;
}

void atom_free_element_list(const ATOM_ELEMENT_REFERENCE_LIST list) {
	if (list.empty()) {
		return;
	}

	for (const ATOM_ELEMENT_REFERENCE& element : list) {
		atom_free_element(element);
	}
}

void atom_register_function(const char* name, ATOM_FUNCTION handler) {
	if (name == NULL) {
		return;
	}
	if (handler == NULL) {
		return;
	}

	EM_ASM_ARGS({
		atom_register_function($0, $1);
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

void atom_add_event_listener(const char* eventName, ATOM_EVENT_HANDLER handler) {
	if (eventName == NULL) {
		return;
	}
	if (handler == NULL) {
		return;
	}

	const char eventFunctionName[] = ATOM_EVENT_FUNCTION_NAME;

	atom_register_function(eventFunctionName, (ATOM_FUNCTION)handler);

	EM_ASM_ARGS({
		const functionName = UTF8ToString($0);
		const eventName = UTF8ToString($1);

		const handler = atom_get_function(functionName);
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

		EM_ASM_ARGS({
			const functionName = UTF8ToString($0);
			const eventName = UTF8ToString($1);
			var   element = $2;

			if (!atom_element_exists(element)) {
				return;
			}

			element = Module.AtomElements[element];
			if (!element) {
				return;
			}

			const handler = atom_get_function(functionName);
			if (handler) {
				element.addEventListener(eventName, event => {
					handler(Emval.toHandle(event));
				});
			}
		}, eventFunctionName, eventName, element);

		atom_unregister_function(eventFunctionName);
	}
}

void atom_exit(int status) {
	if (atom_is_inside_worker()) {
		EM_ASM({
			const processName = atom_get_process_name();

			atom_post_child_process("main", {
				command : "terminate",
				fromProcess : processName,
				processName
			});
		});

		atom_yield();

		return;
	}

	EM_ASM({
		for (const processName in Module.ChildProcesses) {
			atom_terminate_child_process(processName);
		}
	});

	emscripten_force_exit(status);
}