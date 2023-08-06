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

<a name="atom_sleep">`atom_sleep`</a>
