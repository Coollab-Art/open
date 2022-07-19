# open_link

## Including

To add this library to your project, simply add those two lines to your *CMakeLists.txt*:
```cmake
add_subdirectory(path/to/open_link)
target_link_libraries(${PROJECT_NAME} PRIVATE open_link::open_link)
```

Then include it as:
```cpp
#include <open_link/open_link.hpp>
```

## Running the tests

Simply use "tests/CMakeLists.txt" to generate a project, then run it.

<ins>*Detailed steps for VSCode:*</ins>

- Go to *Settings* (<kbd>CTRL</kbd> + <kbd>,</kbd>), select *Workspace*, search for "Source Directory" and set it as "${workspaceFolder}/tests".
- Reload the window (<kbd>CTRL</kbd> + <kbd>SHIFT</kbd> + <kbd>P</kbd> and search "Reload Window")
- Then the CMake extension should pick it up and you can run the tests as usual with the triangle icon.