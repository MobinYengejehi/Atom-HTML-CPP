# Atom `HTML Graphics` Library for `C & CPP`

Atom is a library based on `C & CPP` that you can compile it to web assembly and use it in browsers.

This library is something similar to `React` that you can create your websites based on `C & CPP` with its help.

# How to use `Atom`

1. Download and install [Emscripten](https://emscripten.org/) (Its better you install emscripten on `C:\emsdk` and don't forget to add it to windows environment)
2. Create a directory
3. Copy `Atom library` codes to your directory
4. Create your `C` or `CPP` files and write your code

```cpp
//example
#include <iostream>

#include "Atom/Atom.h"

int main() {
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
        <script src="AtomHardwareAPI.js" atom_main></script>
    </body>
</html>
```

8. Open HTML file on your browser and you can see the preview.

# How to use `Atom` in `Visual Studio`

1. Download and install [Visual Studio](https://visualstudio.microsoft.com/downloads/)
2. Download and install `Cmake & Cmake Tools & Windows-Clang` from `Visual Studio` installer application
3. Make sure you installed the `Emscripten SDK`
4. Create a `Cmake Project` in visual studio
5. Add `Emscripten Cmake Toolchain` to your cmake project which located on `[emscripten_sdk installed directory]/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake`
6. Build your project
7. Open the `out` folder
8. You will see `.js` and `.js.map` files
9. Create a HTML file and use them on it

Note : Your `CMakeLists.txt` file should look like : (if you installed `Emscripten SDK` on `C:\emsdk`)

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

# Atom shared functions

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
        
        atom_wait_till_process_ready("other_thread");

        ATOM_JS_VARIABLE object = ATOM_JS_VARAIBLE::object();
        object.set("name", "Jash");
        object.set("lastname", "Handersone");
        object.set("age", 45);

        atom_post_child_process("other_thread", object.as_handle());
    }

    return NULL;
}
```
