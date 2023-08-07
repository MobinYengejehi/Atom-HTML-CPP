'use strict';

var Module = {};

function assert(condition, text) {
    if (!condition) {
        abort('Assertion failed: ' + text);
    }
}

function threadPrintErr() {
    var text = Array.prototype.slice.call(arguments).join(' ');
    console.error(text);
}

function threadAlert() {
    var text = Array.prototype.slice.call(arguments).join(' ');
    postMessage({
        command : "alert",
        message : text
    });
}

var out = () => { throw 'out() is not defined in worker.js.'; }
var err = threadPrintErr;
self.alert = threadAlert;
var dbg = threadPrintErr;

self.onunhandledrejection = (e) => {
    throw e.reason ?? e;
};

async function handleMessage(e) {
    const data = e.data;
    const cmd = data.command;
    const processName = data.processName;
    const fromProcess = data.fromProcess;
    const key = data.key;
    const functionName = data.functionName;
    const functionArgs = data.functionArgs;

    Module.TempValue = data.tempValue;

    try{
        if (cmd == "load") {
            const atomMainScriptPath = data.atomMainScriptPath;

            self.ATOM_MAIN_SCRIPT_PATH = atomMainScriptPath;
            self.ATOM_WORKER_SCRIPT_PATH = data.workerScriptPath;
            self.ATOM_MULTI_THREAD_ENABLED = true;
            self.ATOM_PROCESS_NAME = data.processName;

            importScripts(atomMainScriptPath);
        }else if (cmd == "calln" || cmd == "callm") {
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

            if (fromProcess == processName) await atom_sleep(0);

            atom_post_child_process(fromProcess, {
                command : "result",
                processName : fromProcess,
                fromProcess : processName,
                key,
                result
            });
        }else if (cmd == "result") {
            const resolver = Module.ThreadPromises[key];

            if (resolver) {
                resolver(data.result);
            }

            delete Module.ThreadPromises[key];
        }else if (cmd == "resume") {
            const resolver = Module.YieldPromise;

            if (resolver) {
                resolver(data.result);
            }
        }else if (cmd == "sfremove") {
            atom_delete_function_pointer(data.pointer);
        }else if (cmd == "sfcall") {
            const pointer = data.pointer;

            if (pointer == NULL) {
                return;
            }

            const func = wasmTable.get(pointer);

            if (typeof func == "function") {
                func.apply(null, functionArgs);
            }
        }
    }catch (error) {
        console.error(error);
    }
}

self.onmessage = handleMessage;