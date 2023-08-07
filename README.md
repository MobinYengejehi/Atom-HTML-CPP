# Guidline

>   🔵 [What is Atom](#what_is_atom)
>
>   🔵 [How to use Atom](#how_to_use_atom)
>
>   🔵 [How to use Atom in Visual Studio](#how_to_use_atom_vs)
>
>   🔵 [How to create and use Atom Components](#how_to_create_atom_component)
>
>   🔵 [How to create and use Atom Css StyleSheet](#how_to_create_atom_css_style)
>
>   🔵 [How to use Css Properties for Atom Element directly](#how_to_use_css_properties_for_atom_element)
>
>   🔵 [How to write Javascript code in CPP](#how_to_write_js_code_in_cpp)
>
>   🔵 [Atom shared functions](#atom_shared_function)
>
>>   🔵 [atom_sleep](#atom_sleep)
>
>>   🔵 [atom_get_now](#atom_get_now)
>
>>   🔵 [atom_clear_console](#atom_clear_console)
>
>>   🔵 [atom_application_init](#atom_application_init)
>
>>   🔵 [atom_get_main_script_path](#atom_get_main_script_path)
>
>>   🔵 [atom_get_worker_script_path](#atom_get_worker_script_path)
>
>>   🔵 [atom_is_inside_worker](#atom_is_inside_worker)
>
>>   🔵 [atom_get_document_head](#atom_get_document_head)
>
>>   🔵 [atom_get_document_body](#atom_get_document_body)
>
>>   🔵 [atom_create_element](#atom_create_element)
>
>>   🔵 [atom_element_exists](#atom_element_exists)
>
>>   🔵 [atom_destroy_element](#atom_destroy_element)
>
>>   🔵 [atom_free_element](#atom_free_element)
>
>>   🔵 [atom_is_same_element](#atom_is_same_element)
>
>>   🔵 [atom_set_element_attribute](#atom_set_element_attribute)
>
>>   🔵 [atom_get_element_attribute](#atom_get_element_attribute)
>
>>   🔵 [atom_set_element_property](#atom_set_element_property)
>
>>   🔵 [atom_get_element_property](#atom_get_element_property)
>
>>   🔵 [atom_element_append_child](#atom_element_append_child)
>
>>   🔵 [atom_set_element_style](#atom_set_element_style)
>
>>   🔵 [atom_get_element_style](#atom_get_element_style)
>
>>   🔵 [atom_add_element_class](#atom_add_element_class)
>
>>   🔵 [atom_element_class_exists](#atom_element_class_exists)
>
>>   🔵 [atom_remove_element_class](#atom_remove_element_class)
>
>>   🔵 [atom_get_element_node_name](#atom_get_element_node_name)
>
>>   🔵 [atom_get_element_parent](#atom_get_element_parent)
>
>>   🔵 [atom_is_function_registered](#atom_is_function_registered)
>
>>   🔵 [atom_unregister_function](#atom_unregister_function)
>
>>   🔵 [atom_get_function](#atom_get_function)
>
>>   🔵 [atom_is_multi_thread_enabled](#atom_is_multi_thread_enabled)
>
>>   🔵 [atom_get_process_name](#atom_get_process_name)
>
>>   🔵 [atom_is_main_process](#atom_is_main_process)
>
>>   🔵 [atom_fork](#atom_fork)
>
>>   🔵 [atom_post_child_process](#atom_post_child_process)
>
>>   🔵 [atom_child_process_exists](#atom_child_process_exists)
>
>>   🔵 [atom_child_process_is_ready](#atom_child_process_is_ready)
>
>>   🔵 [atom_wait_till_process_be_ready](#atom_wait_till_process_be_ready)
>
>>   🔵 [atom_terminate_child_process](#atom_terminate_child_process)
>
>>   🔵 [atom_loadstring_child_process](#atom_loadstring_child_process)
>
>>   🔵 [atom_eval_child_process](#atom_eval_child_process)
>
>>   🔵 [atom_yield](#atom_yield)
>
>>   🔵 [atom_resume](#atom_resume)
>
>>   🔵 [atom_function_pointer_exists](#atom_function_pointer_exists)
>
>>   🔵 [atom_delete_function_pointer](#atom_delete_function_pointer)
>
>>   🔵 [atom_register_shared_function](#atom_register_shared_function)
>
>>   🔵 [atom_shared_function_exists](#atom_shared_function_exists)
>
>>   🔵 [atom_remove_shared_function](#atom_remove_shared_function)
>
>>   🔵 [atom_get_shared_function_process](#atom_get_shared_function_process)
>
>>   🔵 [atom_get_shared_function](#atom_get_shared_function)
>
>>   🔵 [atom_allocate_shared_memory](#atom_allocate_shared_memory)
>
>>   🔵 [atom_shared_memory_exists](#atom_shared_memory_exists)
>
>>   🔵 [atom_get_shared_memory_pointer](#atom_get_shared_memory_pointer)
>
>>   🔵 [atom_get_shared_memory_size](#atom_get_shared_memory_size)
>
>>   🔵 [atom_free_shared_memory](#atom_free_shared_memory)
>
>>   🔵 [atom_get_shared_memory](#atom_get_shared_memory)
>
>>   🔵 [atom_update_shared_memory](#atom_update_shared_memory)
>
>>   🔵 [atom_update_main_shared_memory](#atom_update_main_shared_memory)
>
>>   🔵 [atom_get_pointer_from_reference](#atom_get_pointer_from_reference)
>
>>   🔵 [atom_get_pointer_reference](#atom_get_pointer_reference)
>
>>   🔵 [atom_request_animation_frame](#atom_request_animation_frame)
>
>>   🔵 [atom_exists_animation_frame](#atom_exists_animation_frame)
>
>>   🔵 [atom_cancel_animation_frame](#atom_cancel_animation_frame)
>
>>   🔵 [atom_get_animation_frame_handler](#atom_get_animation_frame_handler)
>
>>   🔵 [atom_query_selector](#atom_query_selector)
>
>>   🔵 [atom_query_selector_all](#atom_query_selector_all)
>
>>   🔵 [atom_free_element_list](#atom_free_element_list)
>
>>   🔵 [atom_register_function](#atom_register_function)
>
>>   🔵 [atom_generage_random_key](#atom_generage_random_key)
>
>>   🔵 [atom_get_element_bounding_box](#atom_get_element_bounding_box)
>
>>   🔵 [atom_add_event_listener](#atom_add_event_listener)
>
>>   🔵 [atom_exit](#atom_exit)

# <a name="what_is_atom">Atom `HTML Graphics` Library for `C & CPP`</a>

Atom is a library based on `C & CPP` that you can compile it to web assembly and use it in browsers.

This library is something similar to `React` that you can create your websites based on `C & CPP` with its help.

# <a name="how_to_use_atom">How to use `Atom`</a>

1. Download and install [Emscripten](https://emscripten.org/) (Its better you install emscripten on `C:\emsdk` and don't forget to add it to windows environment)
2. Create a directory
3. Copy `Atom library` codes to your directory
4. Create your `C` or `CPP` files and write your code

```cpp
//example
#include <iostream>

#include "Atom/Atom.h"

int main() {
    atom_init_application();

    char* processName = atom_get_process_name();
    
    std::cout << "process name is : " << processName << std::endl;
    
    free((void*)processName);
    
    return NULL;
}
```

5. Open the terminal on your projects directory
6. Build your code to web assembly with the following command : 

```powershell
# Debug
emcc -lembind -s ASYNCIFY -s EXIT_RUNTIME=1 -s ALLOW_MEMORY_GROWTH=1 -s TOTAL_MEMORY=2097152000 -s WASM=0 main.cpp -o app.js

# Release
emcc -lembind -s ASYNCIFY -s EXIT_RUNTIME=1 -s ALLOW_MEMORY_GROWTH=1 -s TOTAL_MEMORY=2097152000 -s WASM=0 -Os main.cpp -o app.js
```

7. Create a HTML file and load `app.js` code with the following code :

```html
<html>
    <head></head>
    <body>
        <script src="app.js" atom_main></script>
    </body>
</html>
```

8. Open HTML file on your browser and you can see the preview.

# <a name="how_to_use_atom_vs">How to use `Atom` in `Visual Studio`</a>

1. Download and install [Visual Studio](https://visualstudio.microsoft.com/downloads/)
2. Download and install `Cmake & Cmake Tools & Windows-Clang` from `Visual Studio` installer application
3. Make sure you installed the `Emscripten SDK`
4. Create a `Cmake Project` in visual studio
5. Add `Emscripten Cmake Toolchain` to your cmake project which located on `[emscripten_sdk installed directory]/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake`
6. Add `Atom Library` to your project (Don't forget to add files to `CMakeLists.txt` file!)
7. Build your project
8. Open the `out` folder
9. You will see `.js` and `.js.map` files
10. Create a HTML file and use them on it

Note : Your `CMakeSettings.json` file should look like : (if you installed `Emscripten SDK` on `C:\emsdk`)

```json
{
  "configurations": [
    {
      "name": "x64-Debug",
      "generator": "Ninja",
      "configurationType": "Debug",
      "buildRoot": "${projectDir}\\out\\build\\${name}",
      "installRoot": "${projectDir}\\out\\install\\${name}",
      "cmakeCommandArgs": "",
      "buildCommandArgs": "",
      "ctestCommandArgs": "",
      "cmakeToolchain": "C:/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake",
      "inheritEnvironments": [],
      "intelliSenseMode": "windows-clang-x64",
      "variables": [
        {
          "name": "CMAKE_CXX_FLAGS",
          "value": "-lembind -s ASYNCIFY -s EXIT_RUNTIME=1 -s ALLOW_MEMORY_GROWTH=1 -s TOTAL_MEMORY=2097152000 -s WASM=0 -Os",
          "type": "STRING"
        }
      ]
    },
    {
      "name": "x64-Release",
      "generator": "Ninja",
      "configurationType": "Release",
      "buildRoot": "${projectDir}\\out\\build\\${name}",
      "installRoot": "${projectDir}\\out\\install\\${name}",
      "cmakeCommandArgs": "",
      "buildCommandArgs": "",
      "ctestCommandArgs": "",
      "cmakeToolchain": "C:/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake",
      "inheritEnvironments": [],
      "intelliSenseMode": "windows-clang-x64",
      "variables": [
        {
          "name": "CMAKE_CXX_FLAGS",
          "value": "-lembind -s ASYNCIFY -s EXIT_RUNTIME=1 -s ALLOW_MEMORY_GROWTH=1 -s TOTAL_MEMORY=2097152000 -s WASM=0 -Os",
          "type": "STRING"
        }
      ]
    }
  ]
}
```

You can see an example from `Cmake` and `Visual Studio` with `Atom` if you [click here]().

# <a name="how_to_create_atom_component">How to create and use `Atom Components`</a>
For creating `Atom Components` all you need is including `AtomMacros.h` header file and use it like the following example:

```cpp
#include "Atom/Atom.h"
#include "Atom/AtomMacros.h"

const std::string DefaultTitle = "atom app";

AtomElement Title(const std::string& title) {
    return Element { Node "h1", Id "app_title",
        ([&title]() -> auto {
            if (title.empty()) {
                return TextContent DefaultTitle;
            }
            return TextContent title;
        })()
    };
}

AtomElement List(const size_t& itemCount) {
    const size_t count = itemCount > 5 ? itemCount : 5;

    return Element { Node "div", Class "list itemHolder",
        ([&count]() -> auto {
            AtomElementList items;
            
            for (size_t i = 0; i < count; i++) {
                items.push_back(Element {
                    Node "span",
                    InnerHTML "im item number : ",
                    InnerHTML std::to_string(i)
                });
            }

            return items;
        })(),

        OnMouseMove [](ATOM_EVENT eventHandle) {
            ATOM_JS_VARIABLE e = ATOM_EVENT_VARIABLE(eventHandle);

            int x = e["clientX"] ATOM_AS_INT;
            int y = e["clientY"] ATOM_AS_INT;

            std::cout << "mouse is moving on list : " << x << ", " << y << std::endl;
        }
    };
}

AtomElement App() {
    return Element { Node "div", Class "atom_app_container",
        Title("this is simple atom application"),
        List(15),
        BreakLine,
        Element { Node "h1",
            TextConten "im footer!"
        }
    };
}

int main() {
    atom_application_init();

    AtomElement body = AtomGetDocumentBodyElement();

    AtomElement app = App();

    {
        body += app;
        // or :
        body.AppendChild(app);
    }

    return NULL;
}
```

To earn more information about this feature you can check out [AtomMacros.h]() file. 

# <a name="how_to_create_atom_css_style">How to create and use `Atom Css StyleSheet`</a>

For creating `Css StyleSheets` using `Atom` you just need to include `AtomStyleMacros.h` and `AtomCssPropertiesMacros.h` and use them like the following example:

```cpp
#include "Atom/Atom.h"
#include "Atom/AtomStyleMacros.h"
#include "Atom/AtomCssPropertiesMacros.h"

AtomCssStyleProperties CssStyle() {
    return CssStyleSheet {
        Query(*) {
            Margin = Css(0px),
            Padding = Css(0px)
        },
        Query(body) {
            Position = Css(absolute),
            Left = "50%", // you can use strings too
            Top = "50%",
            Transform = Css(translate(-50%, -50%))
        },
        Query(body .atom_app_container) {
            Width = Css(100%),
            Height = Css(100%),
            Background = Css(#ff00ff), // you can also use `CssProperty(background)`
            CssProperty(position) = Css(absolute),
            Animation = Css(container_animation 1s ease 0s infinite)
        },
        $KeyFrames(container_animation) {
            Query(0%, 100%) {
                CssProperty(transform) = Css(translateY(0px))
            },
            Query(50%) {
                Transform = Css(translateY(100%))
            }
        }
    }
}

int main() {
    atom_application_init();

    AtomElement head = AtomGetDocumentHeadElement();

    AtomElement styleSheet = AtomCreateStyleElement(CssStyle());

    head += styleSheet;

    return NULL;
}
```

To earn more information about this feature you can check out [AtomStyleMacros.h]() and [AtomCssPropertiesMacros.h]() files.

# <a name="how_to_use_css_properties_for_atom_element">How to use `Css Properties` for `Atom Element` directly</a>

`Example`:

```cpp
#include "Atom/Atom.h"
#include "Atom/AtomMacros.h"
#include "Atom/AtomCssPropertiesMacros.h"

AtomElement App() {
    return Element { Node "div", Class "atom_app",
        Style {
            Position = Css(absolute),
            Width = Css(100px),
            Height = Css(150px),
            Left = Css(50%),
            Top = Css(50%),
            Transform = Css(translate(-50%, -50%))
        },
        InnerHTML "<h1>hi this is the app</h1>",
        InnerHTML "<span>this is an span element</span>"
    }
}

int main() {
    atom_application_init();

    AtomGetDocumentBodyElement() += App();

    return NULL;
}
```

# <a name="how_to_write_js_code_in_cpp">How to write `Javascript` code in `CPP`</a>

`Example`:

```cpp
#include <iostream>
#include "Atom/Atom.h"

ATOM_JS_DEFINITION void JsError(const char* error);
ATOM_JS(void, JsError, (const char* error), {
    if (error == NULL) {
        return;
    }

    error = UTF8ToString(error);

    console.error("Error:", error);
});

void JavascriptLog() {
    std::cout << "writing js code : " << std::endl;

    ATOM_DIRECT_ASM({
        console.log("this is javascript log!");
    });
}

int main() {
    atom_application_init();

    JavascriptLog();

    std::cout << "this is cpp!" << std::endl;

    JsError("error bla bla bla");

    char* data = (char*)ATOM_DIRECT_ASM({
        const x = $0; // 10
        const y = $1; // 50

        console.log("numbers came from cpp are : ", { x, y });

        const string = `numbers are : ${x}, ${y} and with togheter are : ${x + y}`;
        return atom_to_pointer(string);
    }, 10, 50)

    std::cout << "data came from js is : " << data << std::endl;

    free((void*)data);

    // ATOM_ASM(processName, javascriptCode);
    ATOM_ASM("main", {
        const processName = atom_get_process_name();
        
        console.log("process name is : ", processName);
    });

    // ATOM_LOAD_STRING(processName, javascriptCode);
    ATOM_FUNCTION jsFunction = ATOM_LOAD_STRING("main", {
        const cppString = UTF8ToString(arguments[0]);
        const x = arguments[1];
        const y = arguments[2];

        console.log("js function data is : ", { cppString, x, y, result : x + y });
    });

    typedef void (*JSFunc)(const char*, int, int);

    JSFunc func = (JSFunc)jsFunction;

    func("this is a cpp string!", 30, 24);
    func("this is second use of function", 10, 9093);

    return NULL;
}
```

# <a name="atom_shared_function">Atom shared functions</a>

<a name="atom_sleep"><h3>Function name : atom_sleep</h3></a>

`Definition:`
```cpp
void atom_sleep(unsigned int ms);
```

`Description`: This function yields the thread untill the specified time.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    std::cout << "start the program : " << std::endl;

    int sleepforseconds = 5;

    atom_sleep(sleepforseconds*1000);

    std::cout << "after " << sleepforseconds << " seconds" << std::endl;

    return NULL;
}
```

<a name="atom_get_now"><h3>Function name : atom_get_now</h3></a>

`Definition:`
```cpp
ATOM_TICK atom_get_now();
```

`Description`: This function gets the timestamp for current time.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    std::cout << "start the program : " << std::endl;

    ATOM_TICK last = atom_get_now();

    int sleepforseconds = 5;

    atom_sleep(sleepforseconds*1000);

    std::cout << ((atom_get_now() - last)/1000) << " seconds elpased!" << std::endl;

    return NULL;
}
```

<a name="atom_clear_console"><h3>Function name : atom_clear_console</h3></a>

`Definition:`
```cpp
void atom_clear_console();
```

`Description`: This function clears the debug console.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    std::cout << "this is cpp web app !" << std::endl;

    std::cout << "clear console after 10 seconds" << std::endl;
    
    atom_sleep(10000);

    atom_clear_console();

    return NULL;
}
```

<a name="atom_application_init"><h3>Function name : atom_application_init</h3></a>

`Definition:`
```cpp
void atom_application_init();
```

`Description`: This function defines all Atom shared functions for cpp and javascript.

`Note 1`: If you don't use this function you won't be able to use Atom library at all.

`Note 2`: Use this function just once otherwise it will break your code

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();
    std::cout << "start the program : " << std::endl;
    return NULL;
}
```

<a name="atom_get_main_script_path"><h3>Function name : atom_get_main_script_path</h3></a>

`Definition:`
```cpp
char* atom_get_main_script_path();
```

`Description`: This function gets the current script path or url.

`Note`: If you don't free the string returned from this function it will occupie all your memory blocks

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    char* scriptPath = atom_get_main_script_path();

    std::cout << "script path is : " << scriptPath << std::endl;

    free((void*)scriptPath); // cleanup memory

    return NULL;
}
```

<a name="atom_get_worker_script_path"><h3>Function name : atom_get_worker_script_path</h3></a>

`Definition:`
```cpp
char* atom_get_worker_script_path();
```

`Description`: This function gets the javascript code that application will use on threads.

`Note 1`: Its better to use [AtomWorker.js]().

`Note 2`: If you don't free the string returned from this function it will occupie all your memory blocks

You can set the script path this way on your html content:

```html
<script src="app.js" atom_main atom_worker="AtomWorker.js"></script>
```

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    char* scriptPath = atom_get_worker_script_path();
    std::cout << "worker script path is : " << scriptPath << std::endl;

    free((void*)scriptPath);

    return NULL;
}
```

<a name="atom_is_inside_worker"><h3>Function name : atom_is_inside_worker</h3></a>

`Definition:`
```cpp
bool atom_is_inside_worker();
```

`Description`: This function checks if process is inside another thread or not.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    char* processName = atom_get_process_name();
    std::cout << "process is : " << processName << std::endl;
    free((void*)processName);

    if (atom_is_inside_worker()) {
        std::cout << "this is inside worker!" << std::endl;

        return;
    }

    atom_fork(NULL);

    return NULL;
}
```

<a name="atom_get_documnet_head"><h3>Function name : atom_get_document_head</h3></a>

`Definition:`
```cpp
ATOM_ELEMENT_REFERENCE atom_get_document_head();
```

`Description`: This function gets the html head element.

`Note`: This function create a reference for the target element, then you must use [atom_free_element](#atom_free_element) function to delete the reference.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();
    
    ATOM_ELEMENT_REFERENCE head = atom_get_document_head();

    ATOM_ELEMENT_REFERENCE style = atom_create_element("style");

    atom_set_element_property(style, "innerHTML", "body{ background: red; }");

    atom_element_append_child(head, style);

    atom_free_element(style);
    atom_free_element(head);

    return NULL;
}
```

<a name="atom_get_document_body"><h3>Function name : atom_get_document_body</h3></a>

`Definition:`
```cpp
ATOM_ELEMENT_REFERENCE atom_get_document_body();
```

`Description`: This function gets the body element.

`Note`: This function create a reference for the target element, then you must use [atom_free_element](#atom_free_element) function to delete the reference.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    if (body) {
        char* nodeName = atom_get_element_node_name(body);
        std::cout << "element node name is : " << nodeName << std::endl;
        free((void*)nodeName);
    }

    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_create_element"><h3>Function name : atom_create_element</h3></a>

`Definition:`
```cpp
ATOM_ELEMENT_REFERENCE atom_create_element(const char* nodeName);
```

`Description`: This function creates a new element.

`Note`: This function create a reference for the target element, then you must use [atom_free_element](#atom_free_element) function to delete the reference.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    
    ATOM_ELEMENT_REFERENCE div = atom_create_element("div");

    atom_set_element_style(div, "width", "100px");
    atom_set_element_style(div, "height", "150px");
    atom_set_element_style(div, "background", "blue");

    atom_element_append_child(body, div);

    atom_free_element(div);
    atom_free_element(body);

    return NULL;
}
```

<a name="atom_element_exists"><h3>Function name : atom_element_exists</h3></a>

`Definition:`
```cpp
bool atom_element_exists(ATOM_ELEMENT_REFERENCE element);
```

`Description`: This function checks if the element reference exists or not.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    
    if (atom_element_exists(body)) {
        std::cout << "element exists" << std::endl;
    }else{
        std::cout << "element doesn't exist" << std::endl;
    }
    
    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_destroy_element"><h3>Function name : atom_destroy_element</h3></a>

`Definition:`
```cpp
void atom_destroy_element(ATOM_ELEMENT_REFERENCE element);
```

`Description`: This function completely removes an element from document.

`Node`: This function also automatically removes the element reference.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    
    ATOM_ELEMENT_REFERNECE header = atom_create_element("h1");
    atom_set_element_property(header, "textContent", "this is a header");

    atom_element_append_child(body, header);
    atom_free_element(body);

    atom_sleep(10000);

    atom_destroy_element(header);

    return NULL;
}
```

<a name="atom_free_element"><h3>Function name : atom_free_element</h3></a>

`Definition:`
```cpp
void atom_free_element(ATOM_ELEMENT_REFERENCE element);
```

`Description`: This function deletes the reference that attached to a HTML element.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    if (body) {
        char* nodeName = atom_get_element_node_name(body);
        std::cout << "element node name is : " << nodeName << std::endl;
        free((void*)nodeName);
    }

    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_is_same_element"><h3>Function name : atom_is_same_element</h3></a>

`Definition:`
```cpp
bool atom_is_same_element(ATOM_ELEMENT_REFERENCE element, ATOM_ELEMENT_REFERENCE target);
```

`Description`: This function checks if both references are holding the same HTML element.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    
    ATOM_ELEMENT_REFERENCE b2 = atom_query_selector("body");
    
    if (atom_is_same_element(body, b2)) {
        std::cout << "both are the same element" << std::endl;
    }
    
    atom_free_element(b2);
    atom_free_element(body);

    return NULL;
}
```

<a name="atom_set_element_attribute"><h3>Function name : atom_set_element_attribute</h3></a>

`Definition:`
```cpp
void atom_set_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute, const char* value);
```

`Description`: This function sets an attribute for element.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();

    atom_set_element_attribute(body, "style", "background: red;");

    atom_free_element(body);

    return NULL;
}
```

<a name="atom_get_element_attribute"><h3>Function name : atom_get_element_attribute</h3></a>

`Definition:`
```cpp
char* atom_get_element_attribute(ATOM_ELEMENT_REFERENCE element, const char* attribute);
```

`Description`: This function gets attribute value for an element.

`Note`: don't forget to free up the `char*` returned data.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    
    char* attr = atom_get_element_attribute(body, "onload");
    std::cout << "attribute is : " << attr << std::endl;
    free((void*)attr);

    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_set_element_property"><h3>Function name : atom_set_element_property</h3></a>

`Definition:`
```cpp
void atom_set_element_property(ATOM_ELEMENT_REFERENCE element, const char* propertyName, const char* value);
```

`Description`: This function sets a property for element.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    
    atom_set_element_property(body, "innerHTML", "<div><h1>hi im a haeder</h1></div>");

    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_get_element_property"><h3>Function name : atom_get_element_property</h3></a>

`Definition:`
```cpp
char* atom_get_element_property(ATOM_ELEMENT_REFERENCE element, const char* propertyName);
```

`Description`: This function gets a property value for element.

`Note`: don't forget to free up `char*` return data.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    
    char* htmlContent = atom_get_element_property(body, "innerHTML");
    std::cout << "html content is : " << htmlContent << std::endl;
    free((void*)htmlContent);

    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_element_append_child"><h3>Function name : atom_element_append_child</h3></a>

`Definition:`
```cpp
void atom_element_append_child(ATOM_ELEMENT_REFERENCE parent, ATOM_ELEMENT_REFERENCE child);
```

`Description`: This function attaches an element to another element.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    ATOM_ELEMNET_REFERENCE h1 = atom_create_element("h1");

    atom_set_element_property(h1, "textContent", "hi");

    atom_element_append_child(body, h1);

    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_set_element_style"><h3>Function name : atom_set_element_style</h3></a>

`Definition:`
```cpp
void atom_set_element_style(ATOM_ELEMENT_REFERENCE element, const char* styleProperty, const char* value);
```

`Description`: This function sets the style property for an element.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    
    atom_set_element_style(body, "background", "#ffccff");

    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_get_element_style"><h3>Function name : atom_get_element_style</h3></a>

`Definition:`
```cpp
char* atom_get_element_style(ATOM_ELEMENT_REFERENCE element, const char* styleProperty);
```

`Description`: This function gets the style property value for an element.

`Note`: don't forget to free up `char*` returned data.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    
    char* background = atom_get_element_style(body, "background");
    std::cout << "background is : " << background << std::endl;
    free((void*)background);

    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_add_element_class"><h3>Function name : atom_add_element_class</h3></a>

`Definition:`
```cpp
void atom_add_element_class(ATOM_ELEMENT_REFERENCE element, const char* className);
```

`Description`: This function adds a class name to an HTML element.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    atom_add_element_class(body, "doc_body");

    ATOM_ELEMENT_REFERENCE b2 = atom_query_selector(".doc_body");

    if (atom_is_same_element(body, b2)) {
        std::cout << "both are the same element" << std::endl;
    }

    atom_free_element(b2);
    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_element_class_exists"><h3>Function name : atom_element_class_exists</h3></a>

`Definition:`
```cpp
bool atom_element_class_exists(ATOM_ELEMENT_REFERENCE element, const char* className);
```

`Description`: This function checks if element class list contains the class name or not.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    atom_add_element_class(body, "doc_body");

    if (atom_element_class_exists(body, "doc_body")) {
        std::cout << "class name exists" << std::endl;
    }

    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_remove_element_class"><h3>Function name : atom_remove_element_class</h3></a>

`Definition:`
```cpp
void atom_remove_element_class(ATOM_ELEMENT_REFERENCE element, const char* className);
```

`Description`: This function removes a class name from element class list.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    
    if (atom_element_exists_class(body, "doc_body")) {
        atom_remove_element_class(body, "doc_body");
    }

    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_get_element_node_name"><h3>Function name : atom_get_element_node_name</h3></a>

`Definition:`
```cpp
char* atom_get_element_node_name(ATOM_ELEMENT_REFERENCE element);
```

`Description`: This function gets the node name of a HTML element.

`Note`: don't forget to free up `char*` returned data.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    if (body) {
        char* nodeName = atom_get_element_node_name(body);
        std::cout << "element node name is : " << nodeName << std::endl;
        free((void*)nodeName);
    }

    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_get_element_parent"><h3>Function name : atom_get_element_parent</h3></a>

`Definition:`
```cpp
ATOM_ELEMENT_REFERENCE atom_get_element_parent(ATOM_ELEMENT_REFERENCE element);
```

`Description`: This function gets the parent element for a HTML element.

`Note`: This function create a reference for the target element, then you must use [atom_free_element](#atom_free_element) function to delete the reference.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_get_document_body();
    ATOM_ELEMENT_REFERENCE document = atom_get_element_parent(body);

    char* nodeName = atom_get_element_node_name(document);
    std::cout << "parent node name is : " << nodeName << std::endl;
    free((void*)nodeName);

    atom_free_element(body); // delete the reference to body element

    return NULL;
}
```

<a name="atom_is_function_registered"><h3>Function name : atom_is_function_registered</h3></a>

`Definition:`
```cpp
bool atom_is_function_registered(const char* functionName);
```

`Description`: This function checks if the cpp function registered or not.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int cppFunction(int x, int y) {
    return x + y;
}

int main () {
    atom_application_init();
    
    atom_register_function("my_func", (ATOM_FUNCTION)cppFunction);
    
    if (atom_is_function_registered("my_func")) {
        std::cout << "registered!" << std::endl;
    }

    return NULL;
}
```

<a name="atom_unregister_function"><h3>Function name : atom_unregister_function</h3></a>

`Definition:`
```cpp
void atom_unregister_function(const char* functionName);
```

`Description`: This function unregisters a cpp function.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    if (atom_is_function_registered("my_func")) {
        atom_unregister_function("my_func");
    }

    return NULL;
}
```

<a name="atom_get_function"><h3>Function name : atom_get_function</h3></a>

`Definition:`
```cpp
ATOM_FUNCTION atom_get_function(const char* functionName);
```

`Description`: This function gets the registered cpp function.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int cppFunction(int x, int y) {
    return x + y;
}

int main () {
    atom_application_init();

    atom_register_function("add", (ATOM_FUNCTION)cppFunction);

    if (atom_is_function_registered("add")) {
        typedef int (*FunctionType)(int, int);

        FunctionType add = atom_get_function("add");

        int data = add(5, 10);

        std::cout << "data is : " << data << std::endl;
    }

    return NULL;
}
```

<a name="atom_is_multi_thread_enabled"><h3>Function name : atom_is_multi_thread_enabled</h3></a>

`Definition:`
```cpp
bool atom_is_multi_thread_enabled();
```

`Description`: This function checks if you can create other threads or not.

`Note`: If you want to enable this feature you need to define `atom_worker="worker_script.js"` attribute on script element.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    if (!atom_is_main_process()) {
        return;
    }

    if (atom_is_multi_thread_enabled()) {
        atom_fork("other_thread");
    }

    return NULL;
}
```

<a name="atom_get_process_name"><h3>Function name : atom_get_process_name</h3></a>

`Definition:`
```cpp
char* atom_get_process_name();
```

`Description`: This function gets the current process name.

`Note`: don't forget to free up `char*` returned data;

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    char* processName = atom_get_process_name();
    std::cout << "process name is : " << processName << std::endl;
    free((void*)processName);

    if (!atom_is_main_process()) {
        return;
    }

    if (atom_is_multi_thread_enabled()) {
        atom_fork("other_thread");
    }

    return NULL;
}
```

<a name="atom_is_main_thread"><h3>Function name : atom_is_main_thread</h3></a>

`Definition:`
```cpp
bool atom_is_main_thread();
```

`Description`: This function checks if is main process or not.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    if (!atom_is_main_process()) {
        return;
    }

    if (atom_is_multi_thread_enabled()) {
        atom_fork("other_thread");
    }

    return NULL;
}
```

<a name="atom_fork"><h3>Function name : atom_fork</h3></a>

`Definition:`
```cpp
void atom_fork(const char* processName); // if you pass `NULL` as first argument application will choose a random name.
```

`Description`: This function creates a child process in a different thread.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    if (!atom_is_main_process()) {
        return;
    }

    if (atom_is_multi_thread_enabled()) {
        atom_fork("other_thread");
    }

    return NULL;
}
```

<a name="atom_post_child_process"><h3>Function name : atom_post_child_process</h3></a>

`Definition:`
```cpp
void atom_post_child_process(const char* processName, ATOM_JS_VARIABLE_HANDLE data);
```

`Description`: This function posts data to a child process.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    if (!atom_is_main_process()) {
        return;
    }

    if (atom_is_multi_thread_enabled()) {
        atom_fork("other_thread");
        
        atom_wait_till_process_be_ready("other_thread");

        ATOM_JS_VARIABLE object = ATOM_JS_VARAIBLE::object();
        object.set("name", "Jash");
        object.set("lastname", "Handersone");
        object.set("age", 45);

        atom_post_child_process("other_thread", object.as_handle());
    }

    return NULL;
}
```

<a name="atom_child_process_exists"><h3>Function name : atom_child_process_exists</h3></a>

`Definition:`
```cpp
bool atom_child_process_exists(const char* processName);
```

`Description`: This function checks if child process exists or not.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    if (!atom_is_main_process()) {
        return;
    }

    atom_fork("secondThread");

    if (atom_child_process_exists("secondThread")) {
        std::cout << "exists" << std::endl;
    }

    return NULL;
}
```

<a name="atom_child_process_is_ready"><h3>Function name : atom_child_process_is_ready</h3></a>

`Definition:`
```cpp
bool atom_child_process_is_ready(const char* processName);
```

`Description`: This function checks if scripts loaded in child process or not.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    if (!atom_is_main_process()) {
        return;
    }

    atom_fork("secondThread");

    if (atom_child_process_is_ready("secondThread")) {
        std::cout << "exists" << std::endl;
    }

    return NULL;
}
```

<a name="atom_wait_till_process_be_ready"><h3>Function name : atom_wait_till_process_be_ready</h3></a>

`Definition:`
```cpp
void atom_wait_till_process_be_ready(const char* processName);
```

`Description`: This function suspends the current thread until the target process be ready.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    if (!atom_is_main_process()) {
        return;
    }

    atom_fork("secondThread");

    atom_wait_till_process_be_ready("secondThread");

    if (atom_child_process_is_ready("secondThread")) {
        std::cout << "exists" << std::endl;
    }

    return NULL;
}
```

<a name="atom_terminate_child_process"><h3>Function name : atom_terminate_child_process</h3></a>

`Definition:`
```cpp
void atom_terminate_child_process(const char* processName);
```

`Description`: This function terminates child process.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    if (!atom_is_main_process()) {
        return;
    }

    atom_fork("secondThread");

    atom_wait_till_process_be_ready("secondThread");

    if (atom_child_process_exists("secondThread")) {
        std::cout << "exists" << std::endl;
    }

    atom_terminate_child_process("secondThread");

    return NULL;
}
```

<a name="atom_loadstring_child_process"><h3>Function name : atom_loadstring_child_process</h3></a>

`Definition:`
```cpp
ATOM_FUNCTION atom_loadstring_child_process(const char* processName, const char* javascriptCode);
```

`Description`: This function loads a javascript code in target process and returns a function that you can call that javascript code whenever you want.

`Note`: Don't forget to free up `ATOM_FUNCTION` return data.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    const char* jsCode = 
        "const x = arguments[0];"
        "const y = arguments[1];"
        "console.log('arguments are : ', { x, y })"
        "return x + y;"
    ;

    typedef int (*JsFunction)(int, int);

    JsFunction func = (JsFunction)atom_loadstring_child_process("main", jsCode);

    std::cout << "data is : " << func(5, 15) << std::endl;

    free((void*)func);

    return NULL;
}
```

<a name="atom_eval_child_process"><h3>Function name : atom_eval_child_process</h3></a>

`Definition:`
```cpp
ATOM_JS_VARIABLE_HANDLE atom_eval_child_process(const char* processName, const char* javascriptCode);
```

`Description`: This function executes javascript code in target process.

`Example`:
```cpp
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    atom_eval_child_process("main", "console.log('hi this is in js');");

    return NULL;
}
```

<a name="atom_yield"><h3>Function name : atom_yield</h3></a>

`Definition:`
```cpp
void atom_yield();
```

`Description`: This function suspends the current thread.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;
    atom_resume("main");
    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        atom_fork("secondThread");

        atom_yield();

        std::cout << "second thread resumed this thread" << std::endl;
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_resume"><h3>Function name : atom_resume</h3></a>

`Definition:`
```cpp
void atom_resume(const char* processName);
```

`Description`: This function resumes the target suspended thread.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;
    atom_resume("main");
    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        atom_fork("secondThread");

        atom_yield();

        std::cout << "second thread resumed this thread" << std::endl;
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_function_pointer_exists"><h3>Function name : atom_function_pointer_exists</h3></a>

`Definition:`
```cpp
bool atom_function_pointer_exists(ATOM_FUNCTION function);
```

`Description`: This function checks if current function exists in memory or not.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void myFunciton() {
    std::cout << "this is my function" << std::endl;
}

int main () {
    atom_application_init();

    if (atom_function_pointer_exists((ATOM_FUNCTION)myFunction)) {
        std::cout << "exists" << std::endl;
    }

    return NULL;
}
```

<a name="atom_delete_function_pointer"><h3>Function name : atom_delete_function_pointer</h3></a>

`Definition:`
```cpp
void atom_delete_function_pointer(ATOM_FUNCTION function);
```

`Description`: This function deletes function from memory.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void myFunc() {
    std::cout << "this is my func" << std::endl;
}

int main () {
    atom_application_init();

    myFunc();

    atom_delete_function_pointer((ATOM_FUNCTION)myFunc);

    myFunc(); // error

    return NULL;
}
```

<a name="atom_register_shared_function"><h3>Function name : atom_register_shared_function</h3></a>

`Definition:`
```cpp
void atom_register_shared_function(const char* name, ATOM_FUNCTION function, bool clearMemory);
```

`Description`: This function registers a function that you can use it in other processes.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;

    auto sFunction = [](int x, int y) -> void {
        std::cout << "this is a shared function on SecondThread : " << (x + y) << std::endl;
    };

    atom_register_shared_function("shfunc", (ATOM_FUNCTION)sFunction, false);

    atom_resume("main");

    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        atom_fork("secondThread");

        atom_yield();

        if (!atom_shared_function_exists("shfunc")) {
            return;
        }

        ATOM_SHARED_FUNCTION_TYPE(SharedFunction, int, int);

        char* processName = atom_get_shared_function_process("shfunc");
        std::cout << "getting function from : " << processName << std::endl;
        free((void*)processName);

        SharedFunction sFunction = (SharedFunction)atom_get_shared_function("shfunc");
        if (sFunction) {
            sFunction(5, 10);
        }

        free((void*)sFunction);

        atom_remove_shared_function("shfunc");
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_shared_function_exists"><h3>Function name : atom_shared_function_exists</h3></a>

`Definition:`
```cpp
bool atom_shared_function_exists(const char* name);
```

`Description`: This function checks if shared function exists or not.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;

    auto sFunction = [](int x, int y) -> void {
        std::cout << "this is a shared function on SecondThread : " << (x + y) << std::endl;
    };

    atom_register_shared_function("shfunc", (ATOM_FUNCTION)sFunction, false);

    atom_resume("main");

    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        atom_fork("secondThread");

        atom_yield();

        if (!atom_shared_function_exists("shfunc")) {
            return;
        }

        ATOM_SHARED_FUNCTION_TYPE(SharedFunction, int, int);

        char* processName = atom_get_shared_function_process("shfunc");
        std::cout << "getting function from : " << processName << std::endl;
        free((void*)processName);

        SharedFunction sFunction = (SharedFunction)atom_get_shared_function("shfunc");
        if (sFunction) {
            sFunction(5, 10);
        }

        free((void*)sFunction);

        atom_remove_shared_function("shfunc");
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_remove_shared_function"><h3>Function name : atom_remove_shared_function</h3></a>

`Definition:`
```cpp
void atom_remove_shared_function(const char* name);
```

`Description`: This function removes registered shared function.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;

    auto sFunction = [](int x, int y) -> void {
        std::cout << "this is a shared function on SecondThread : " << (x + y) << std::endl;
    };

    atom_register_shared_function("shfunc", (ATOM_FUNCTION)sFunction, false);

    atom_resume("main");

    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        atom_fork("secondThread");

        atom_yield();

        if (!atom_shared_function_exists("shfunc")) {
            return;
        }

        ATOM_SHARED_FUNCTION_TYPE(SharedFunction, int, int);

        char* processName = atom_get_shared_function_process("shfunc");
        std::cout << "getting function from : " << processName << std::endl;
        free((void*)processName);

        SharedFunction sFunction = (SharedFunction)atom_get_shared_function("shfunc");
        if (sFunction) {
            sFunction(5, 10);
        }

        free((void*)sFunction);

        atom_remove_shared_function("shfunc");
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_get_shared_function_process"><h3>Function name : atom_get_shared_function_process</h3></a>

`Definition:`
```cpp
char* atom_register_shared_function(const char* name);
```

`Description`: This function gets the process name which registered the shared function.

`Note`: Don't forget to free up `char*` returned data.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;

    auto sFunction = [](int x, int y) -> void {
        std::cout << "this is a shared function on SecondThread : " << (x + y) << std::endl;
    };

    atom_register_shared_function("shfunc", (ATOM_FUNCTION)sFunction, false);

    atom_resume("main");

    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        atom_fork("secondThread");

        atom_yield();

        if (!atom_shared_function_exists("shfunc")) {
            return;
        }

        ATOM_SHARED_FUNCTION_TYPE(SharedFunction, int, int);

        char* processName = atom_get_shared_function_process("shfunc");
        std::cout << "getting function from : " << processName << std::endl;
        free((void*)processName);

        SharedFunction sFunction = (SharedFunction)atom_get_shared_function("shfunc");
        if (sFunction) {
            sFunction(5, 10);
        }

        free((void*)sFunction);

        atom_remove_shared_function("shfunc");
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_get_shared_function"><h3>Function name : atom_get_shared_function</h3></a>

`Definition:`
```cpp
ATOM_FUNCTION atom_register_shared_function(const char* name);
```

`Description`: This function gets the registered shared function.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;

    auto sFunction = [](int x, int y) -> void {
        std::cout << "this is a shared function on SecondThread : " << (x + y) << std::endl;
    };

    atom_register_shared_function("shfunc", (ATOM_FUNCTION)sFunction, false);

    atom_resume("main");

    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        atom_fork("secondThread");

        atom_yield();

        if (!atom_shared_function_exists("shfunc")) {
            return;
        }

        ATOM_SHARED_FUNCTION_TYPE(SharedFunction, int, int);

        char* processName = atom_get_shared_function_process("shfunc");
        std::cout << "getting function from : " << processName << std::endl;
        free((void*)processName);

        SharedFunction sFunction = (SharedFunction)atom_get_shared_function("shfunc");
        if (sFunction) {
            sFunction(5, 10);
        }

        free((void*)sFunction);

        atom_remove_shared_function("shfunc");
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_allocate_shared_memory"><h3>Function name : atom_allocate_shared_memory</h3></a>

`Definition:`
```cpp
void atom_allocate_shared_memory(const char* name, size_t size_of_bytes);
```

`Description`: This function allocates shared memory for using between processes.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;

    if (!atom_shared_memory_exists("my_data")) {
        atom_resume("main");
        atom_exit(NULL);
        return;
    }

    const size_t dataSize = atom_get_shared_memory_size("my_data");

    ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
    const char* data = (char*)sharedMem;

    std::cout << "shared data is : " << data << std::endl;

    memset(data, 'f', dataSize);

    atom_update_main_shared_memory("my_data");

    atom_resume("main");

    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        const char data[] = "hi this is my shared data!";

        const size_t size = strlen(data);

        atom_allocate_shared_memory("my_data", size);

        ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
        memcpy(sharedMem, data, size);

        atom_update_shared_memory("my_data", NULL);

        ATOM_POINTER_REFERENCE pointerRef = atom_get_shared_memory_pointer("my_data");
        std::cout << "shared memory pointer ref is : " << pointerRef << std::endl;
        
        atom_fork("secondThread");

        atom_yield();

        sharedMem = atom_get_shared_memory("my_data");
        const char* updatedData = (char*)sharedMem;

        std::cout << "updated mem is : " << updatedData << std::endl;

        atom_free_shared_memory("my_data");
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_shared_memory_exists"><h3>Function name : atom_shared_memory_exists</h3></a>

`Definition:`
```cpp
bool atom_shared_memory_exists(const char* name);
```

`Description`: This function checks if target shared memory exists or not.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;

    if (!atom_shared_memory_exists("my_data")) {
        atom_resume("main");
        atom_exit(NULL);
        return;
    }

    const size_t dataSize = atom_get_shared_memory_size("my_data");

    ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
    const char* data = (char*)sharedMem;

    std::cout << "shared data is : " << data << std::endl;

    memset(data, 'f', dataSize);

    atom_update_main_shared_memory("my_data");

    atom_resume("main");

    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        const char data[] = "hi this is my shared data!";

        const size_t size = strlen(data);

        atom_allocate_shared_memory("my_data", size);

        ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
        memcpy(sharedMem, data, size);

        atom_update_shared_memory("my_data", NULL);

        ATOM_POINTER_REFERENCE pointerRef = atom_get_shared_memory_pointer("my_data");
        std::cout << "shared memory pointer ref is : " << pointerRef << std::endl;
        
        atom_fork("secondThread");

        atom_yield();

        sharedMem = atom_get_shared_memory("my_data");
        const char* updatedData = (char*)sharedMem;

        std::cout << "updated mem is : " << updatedData << std::endl;

        atom_free_shared_memory("my_data");
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_get_shared_memory_pointer"><h3>Function name : atom_get_shared_memory_pointer</h3></a>

`Definition:`
```cpp
ATOM_POINTER_REFERENCE atom_get_shared_memory_pointer(const char* name);
```

`Description`: This function gets the memory address of target shared memory.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;

    if (!atom_shared_memory_exists("my_data")) {
        atom_resume("main");
        atom_exit(NULL);
        return;
    }

    const size_t dataSize = atom_get_shared_memory_size("my_data");

    ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
    const char* data = (char*)sharedMem;

    std::cout << "shared data is : " << data << std::endl;

    memset(data, 'f', dataSize);

    atom_update_main_shared_memory("my_data");

    atom_resume("main");

    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        const char data[] = "hi this is my shared data!";

        const size_t size = strlen(data);

        atom_allocate_shared_memory("my_data", size);

        ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
        memcpy(sharedMem, data, size);

        atom_update_shared_memory("my_data", NULL);

        ATOM_POINTER_REFERENCE pointerRef = atom_get_shared_memory_pointer("my_data");
        std::cout << "shared memory pointer ref is : " << pointerRef << std::endl;
        
        atom_fork("secondThread");

        atom_yield();

        sharedMem = atom_get_shared_memory("my_data");
        const char* updatedData = (char*)sharedMem;

        std::cout << "updated mem is : " << updatedData << std::endl;

        atom_free_shared_memory("my_data");
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_get_shared_memory_size"><h3>Function name : atom_get_shared_memory_size</h3></a>

`Definition:`
```cpp
size_t atom_get_shared_memory_size(const char* name);
```

`Description`: This function gets the size of bytes for target shared memory.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;

    if (!atom_shared_memory_exists("my_data")) {
        atom_resume("main");
        atom_exit(NULL);
        return;
    }

    const size_t dataSize = atom_get_shared_memory_size("my_data");

    ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
    const char* data = (char*)sharedMem;

    std::cout << "shared data is : " << data << std::endl;

    memset(data, 'f', dataSize);

    atom_update_main_shared_memory("my_data");

    atom_resume("main");

    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        const char data[] = "hi this is my shared data!";

        const size_t size = strlen(data);

        atom_allocate_shared_memory("my_data", size);

        ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
        memcpy(sharedMem, data, size);

        atom_update_shared_memory("my_data", NULL);

        ATOM_POINTER_REFERENCE pointerRef = atom_get_shared_memory_pointer("my_data");
        std::cout << "shared memory pointer ref is : " << pointerRef << std::endl;
        
        atom_fork("secondThread");

        atom_yield();

        sharedMem = atom_get_shared_memory("my_data");
        const char* updatedData = (char*)sharedMem;

        std::cout << "updated mem is : " << updatedData << std::endl;

        atom_free_shared_memory("my_data");
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_free_shared_memory"><h3>Function name : atom_free_shared_memory</h3></a>

`Definition:`
```cpp
void atom_free_shared_memory(const char* name);
```

`Description`: This function deletes shared memory bytes from memory.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;

    if (!atom_shared_memory_exists("my_data")) {
        atom_resume("main");
        atom_exit(NULL);
        return;
    }

    const size_t dataSize = atom_get_shared_memory_size("my_data");

    ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
    const char* data = (char*)sharedMem;

    std::cout << "shared data is : " << data << std::endl;

    memset(data, 'f', dataSize);

    atom_update_main_shared_memory("my_data");

    atom_resume("main");

    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        const char data[] = "hi this is my shared data!";

        const size_t size = strlen(data);

        atom_allocate_shared_memory("my_data", size);

        ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
        memcpy(sharedMem, data, size);

        atom_update_shared_memory("my_data", NULL);

        ATOM_POINTER_REFERENCE pointerRef = atom_get_shared_memory_pointer("my_data");
        std::cout << "shared memory pointer ref is : " << pointerRef << std::endl;
        
        atom_fork("secondThread");

        atom_yield();

        sharedMem = atom_get_shared_memory("my_data");
        const char* updatedData = (char*)sharedMem;

        std::cout << "updated mem is : " << updatedData << std::endl;

        atom_free_shared_memory("my_data");
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_get_shared_memory"><h3>Function name : atom_get_shared_memory</h3></a>

`Definition:`
```cpp
ATOM_POINTER atom_get_shared_memory(const char* name);
```

`Description`: This function gets the shared memory bytes.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;

    if (!atom_shared_memory_exists("my_data")) {
        atom_resume("main");
        atom_exit(NULL);
        return;
    }

    const size_t dataSize = atom_get_shared_memory_size("my_data");

    ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
    const char* data = (char*)sharedMem;

    std::cout << "shared data is : " << data << std::endl;

    memset(data, 'f', dataSize);

    atom_update_main_shared_memory("my_data");

    atom_resume("main");

    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        const char data[] = "hi this is my shared data!";

        const size_t size = strlen(data);

        atom_allocate_shared_memory("my_data", size);

        ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
        memcpy(sharedMem, data, size);

        atom_update_shared_memory("my_data", NULL);

        ATOM_POINTER_REFERENCE pointerRef = atom_get_shared_memory_pointer("my_data");
        std::cout << "shared memory pointer ref is : " << pointerRef << std::endl;
        
        atom_fork("secondThread");

        atom_yield();

        sharedMem = atom_get_shared_memory("my_data");
        const char* updatedData = (char*)sharedMem;

        std::cout << "updated mem is : " << updatedData << std::endl;

        atom_free_shared_memory("my_data");
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_update_shared_memory"><h3>Function name : atom_update_shared_memory</h3></a>

`Definition:`
```cpp
void atom_update_shared_memory(const char* name, const char* processName);
```

`Description`: This function forces the target process to get new shared memory bytes.

`Note`: If processName be `NULL`, it will force all processes to update their bytes;

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;

    if (!atom_shared_memory_exists("my_data")) {
        atom_resume("main");
        atom_exit(NULL);
        return;
    }

    const size_t dataSize = atom_get_shared_memory_size("my_data");

    ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
    const char* data = (char*)sharedMem;

    std::cout << "shared data is : " << data << std::endl;

    memset(data, 'f', dataSize);

    atom_update_main_shared_memory("my_data");

    atom_resume("main");

    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        const char data[] = "hi this is my shared data!";

        const size_t size = strlen(data);

        atom_allocate_shared_memory("my_data", size);

        ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
        memcpy(sharedMem, data, size);

        atom_update_shared_memory("my_data", NULL);

        ATOM_POINTER_REFERENCE pointerRef = atom_get_shared_memory_pointer("my_data");
        std::cout << "shared memory pointer ref is : " << pointerRef << std::endl;
        
        atom_fork("secondThread");

        atom_yield();

        sharedMem = atom_get_shared_memory("my_data");
        const char* updatedData = (char*)sharedMem;

        std::cout << "updated mem is : " << updatedData << std::endl;

        atom_free_shared_memory("my_data");
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_update_main_shared_memory"><h3>Function name : atom_update_main_shared_memory</h3></a>

`Definition:`
```cpp
void atom_update_main_shared_memory(const char* name);
```

`Description`: This function updates shared memory bytes on main thread.

`Note`: This function only works on child processes and you can't use it on main process.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void SecondThread() {
    std::cout << "this is second thread" << std::endl;

    if (!atom_shared_memory_exists("my_data")) {
        atom_resume("main");
        atom_exit(NULL);
        return;
    }

    const size_t dataSize = atom_get_shared_memory_size("my_data");

    ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
    const char* data = (char*)sharedMem;

    std::cout << "shared data is : " << data << std::endl;

    memset(data, 'f', dataSize);

    atom_update_main_shared_memory("my_data");

    atom_resume("main");

    atom_exit(NULL);
}

int main () {
    atom_application_init();

    if (atom_is_main_process()) {
        const char data[] = "hi this is my shared data!";

        const size_t size = strlen(data);

        atom_allocate_shared_memory("my_data", size);

        ATOM_POINTER sharedMem = atom_get_shared_memory("my_data");
        memcpy(sharedMem, data, size);

        atom_update_shared_memory("my_data", NULL);

        ATOM_POINTER_REFERENCE pointerRef = atom_get_shared_memory_pointer("my_data");
        std::cout << "shared memory pointer ref is : " << pointerRef << std::endl;
        
        atom_fork("secondThread");

        atom_yield();

        sharedMem = atom_get_shared_memory("my_data");
        const char* updatedData = (char*)sharedMem;

        std::cout << "updated mem is : " << updatedData << std::endl;

        atom_free_shared_memory("my_data");
    }else{
        SecondThread();
    }

    return NULL;
}
```

<a name="atom_get_pointer_from_reference"><h3>Function name : atom_get_pointer_from_reference</h3></a>

`Definition:`
```cpp
ATOM_POINTER atom_get_pointer_from_reference(ATOM_POINTER_REFERENCE pointerRef);
```

`Description`: This function gets the memory pointer from memory address.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_POINTER ptr = malloc(0xfff);

    ATOM_POINTER_REFERENCE pAddress = atom_get_pointer_reference(ptr);
    std::cout << "memory address is : " << pAddress << std::endl;

    ATOM_POINTER ptr2 = atom_get_pointer_from_reference(pAddress);
    
    if (ptr == ptr2) {
        std::cout << "both are the same pointer" << std::endl;
    }

    return NULL;
}
```

<a name="atom_get_pointer_reference"><h3>Function name : atom_get_pointer_reference</h3></a>

`Definition:`
```cpp
ATOM_POINTER_REFERENCE atom_get_pointer_reference(ATOM_POINTER pointer);
```

`Description`: This function gets the pointer from memory address.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_POINTER ptr = malloc(0xfff);

    ATOM_POINTER_REFERENCE pAddress = atom_get_pointer_reference(ptr);
    std::cout << "memory address is : " << pAddress << std::endl;

    ATOM_POINTER ptr2 = atom_get_pointer_from_reference(pAddress);
    
    if (ptr == ptr2) {
        std::cout << "both are the same pointer" << std::endl;
    }

    return NULL;
}
```

<a name="atom_request_animation_frame"><h3>Function name : atom_request_animation_frame</h3></a>

`Definition:`
```cpp
ATOM_ANIMATION_FRAME atom_get_pointer_from_reference(ATOM_ANIMATION_FRAME_HANDLER handler, ATOM_POINTER data);
```

`Description`: This function creates an animation frame.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void Animation(ATOM_TICK, ATOM_POINTER) {
    std::cout << "animation frame!!" << std::endl;
}

int main () {
    atom_application_init();

    ATOM_ANIMATION_FRAME animation = atom_request_animation_frame(Animation, NULL);

    if (atom_exists_animation_frame(animation)) {
        atom_sleep(5000);

        atom_cancel_animation_frame(animation);
    }

    ATOM_ANIMATION_FRAME_HANDLER handler = atom_get_animation_frame_handler(animation);

    if (handler == Animation) {
        std::cout << "both are the same thing" << std::endl;
    }

    return NULL;
}
```

<a name="atom_exists_animation_frame"><h3>Function name : atom_exist_animation_frame</h3></a>

`Definition:`
```cpp
bool atom_exists_animation_frame(ATOM_ANIMATION_FRAME animationID);
```

`Description`: This function checks if animation frame exists or not.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void Animation(ATOM_TICK, ATOM_POINTER) {
    std::cout << "animation frame!!" << std::endl;
}

int main () {
    atom_application_init();

    ATOM_ANIMATION_FRAME animation = atom_request_animation_frame(Animation, NULL);

    if (atom_exists_animation_frame(animation)) {
        atom_sleep(5000);

        atom_cancel_animation_frame(animation);
    }

    ATOM_ANIMATION_FRAME_HANDLER handler = atom_get_animation_frame_handler(animation);

    if (handler == Animation) {
        std::cout << "both are the same thing" << std::endl;
    }

    return NULL;
}
```

<a name="atom_cancel_animation_frame"><h3>Function name : atom_cancel_animation_frame</h3></a>

`Definition:`
```cpp
void atom_cancel_animation_frame(ATOM_ANIMATION_FRAME animationID);
```

`Description`: This function cancels animation frame.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void Animation(ATOM_TICK, ATOM_POINTER) {
    std::cout << "animation frame!!" << std::endl;
}

int main () {
    atom_application_init();

    ATOM_ANIMATION_FRAME animation = atom_request_animation_frame(Animation, NULL);

    if (atom_exists_animation_frame(animation)) {
        atom_sleep(5000);

        atom_cancel_animation_frame(animation);
    }

    ATOM_ANIMATION_FRAME_HANDLER handler = atom_get_animation_frame_handler(animation);

    if (handler == Animation) {
        std::cout << "both are the same thing" << std::endl;
    }

    return NULL;
}
```

<a name="atom_get_animation_frame_handler"><h3>Function name : atom_get_animation_frame_handler</h3></a>

`Definition:`
```cpp
ATOM_ANIMATION_FRAME_HANDLER atom_get_animation_frame_handler(ATOM_ANIMATION_FRAME animationID);
```

`Description`: This function gets the animation handler.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void Animation(ATOM_TICK, ATOM_POINTER) {
    std::cout << "animation frame!!" << std::endl;
}

int main () {
    atom_application_init();

    ATOM_ANIMATION_FRAME animation = atom_request_animation_frame(Animation, NULL);

    if (atom_exists_animation_frame(animation)) {
        atom_sleep(5000);

        atom_cancel_animation_frame(animation);
    }

    ATOM_ANIMATION_FRAME_HANDLER handler = atom_get_animation_frame_handler(animation);

    if (handler == Animation) {
        std::cout << "both are the same thing" << std::endl;
    }

    return NULL;
}
```

<a name="atom_query_selector"><h3>Function name : atom_query_selector</h3></a>

`Definition:`
```cpp
ATOM_ELEMENT_REFERENCE atom_query_selector([ATOM_ELEMENT_REFERENCE parent,] const char* query);
```

`Description`: This function selects element with css query.

`Note`: This function create a reference for the target element, then you must use [atom_free_element](#atom_free_element) function to delete the reference.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_query_selector("body");

    ATOM_ELEMENT_REFERENCE header = atom_query_selector(body, "h1");

    std::cout << "body is : " << body << " | and header is : " << header << std::endl;

    atom_free_element(header);
    atom_free_element(body);

    return NULL;
}
```

<a name="atom_query_selector_all"><h3>Function name : atom_query_selector_all</h3></a>

`Definition:`
```cpp
ATOM_ELEMENT_REFERENCE_LIST atom_query_selector_all([ATOM_ELEMENT_REFERENCE parent,] const char* query);
```

`Description`: This function selects all elements with css query.

`Note`: This function creates a list of references for selected elements, then you must use [atom_free_element_lsit](#atom_free_element_list) function to delete the references.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_query_selector("body");

    ATOM_ELEMENT_REFERENCE_LIST header = atom_query_selector_all(body, "h1");

    size_t headersCount = header.size();

    std::cout << "body has " << headersCount << " headers" << std::endl;

    atom_free_element_list(header);
    atom_free_element(body);

    return NULL;
}
```

<a name="atom_free_element_list"><h3>Function name : atom_free_element_list</h3></a>

`Definition:`
```cpp
void atom_free_element_list(ATOM_ELEMENT_REFERENCE_LIST elementList);
```

`Description`: This function deletes all element references inside a list.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_query_selector("body");

    ATOM_ELEMENT_REFERENCE_LIST header = atom_query_selector_all(body, "h1");

    std::cout << "body is : " << body << " | and header is : " << header << std::endl;

    atom_free_element_list(header);
    atom_free_element(body);

    return NULL;
}
```

<a name="atom_register_function"><h3>Function name : atom_register_function</h3></a>

`Definition:`
```cpp
void atom_register_function(const char* name, ATOM_FUNCTION function);
```

`Description`: This function registeres a cpp function in memory that you can use it in both javascript and cpp.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    atom_register_function("myf", []() {
        std::cout << "hi this is myf" << std::endl;
    });

    return NULL;
}
```

<a name="atom_generate_random_key"><h3>Function name : atom_generate_random_key</h3></a>

`Definition:`
```cpp
char* atom_generate_random_key(const int& characterCount);
```

`Description`: This function generates a random key.

`Note`: Don't forget to free up `char*` returned data.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    char* randomKey = atom_generate_random_key(16);

    std::cout << "random key is : " << randomKey << std::endl;

    free((void*)randomKey);

    return NULL;
}
```

<a name="atom_get_element_bounding_box"><h3>Function name : atom_get_element_bounding_box</h3></a>

`Definition:`
```cpp
ATOM_BOUNDING_BOX atom_get_element_bounding_box(ATOM_ELEMENT_REFERENCE element);
```

`Description`: This function gets client bounding rect of a HTML element.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_query_selector("body");

    ATOM_ELEMENT_REFERENCE header = atom_query_selector(body, "h1");

    ATOM_BOUNDING_BOX rect = atom_get_element_bounding_box(header);

    std::cout << "header position : " << rect.x << " | " << rect.y << std::endl;

    atom_free_element(header);
    atom_free_element(body);

    return NULL;
}
```

<a name="atom_add_event_listener"><h3>Function name : atom_add_event_listener</h3></a>

`Definition:`
```cpp
void atom_add_event_listener([ATOM_ELEMENT_REFERENCE element,] const char* eventName, ATOM_EVENT_HANDLER handler);
```

`Description`: This function adds an event listener for an element.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

void OnClickEvent(ATOM_EVENT eventHandle) {
    ATOM_JS_VARIABLE e = ATOM_EVENT_VARIABLE(eventHandle);

    int x = e["clientX"] ATOM_AS_INT;
    int y = e["clientY"] ATOM_AS_INT;

    std::cout << "clicked on : " << x << " | " << y << std::endl;
}

int main () {
    atom_application_init();

    ATOM_ELEMENT_REFERENCE body = atom_query_selector("body");

    atom_add_event_listener(body, "click", OnClickEvent);

    atom_free_element(body);

    return NULL;
}
```

<a name="atom_exit"><h3>Function name : atom_exit</h3></a>

`Definition:`
```cpp
void atom_exit(int status);
```

`Description`: This function quit from application.

`Example`:
```cpp
#include <iostream>
#include "Atom/Atom.h"

int main () {
    atom_application_init();

    std::cout << "atom application !" << std::endl;

    atom_exit(NULL);

    return NULL;
}
```
