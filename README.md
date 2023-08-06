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

`Note`: Its better to use [AtomWorker.js]().

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

