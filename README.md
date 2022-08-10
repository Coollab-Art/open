# open_link

## Including

To add this library to your project, simply add these two lines to your _CMakeLists.txt_:

```cmake
add_subdirectory(path/to/open_link)
target_link_libraries(${PROJECT_NAME} PRIVATE open_link::open_link)
```

Then include it as:

```cpp
#include <open_link/open_link.hpp>
```

## Example

```cpp
Cool::open_link("https://github.com/CoolLibs/open_link");
```

## Running the tests

Simply use "tests/CMakeLists.txt" to generate a project, then run it.

<ins>_Detailed steps for VSCode:_</ins>

- Go to _Settings_ (<kbd>CTRL</kbd> + <kbd>,</kbd>), select _Workspace_, search for "Source Directory" and set it as `${workspaceFolder}/tests`.
- Reload the window (<kbd>CTRL</kbd> + <kbd>SHIFT</kbd> + <kbd>P</kbd> and search for "Reload Window").
- Delete the CMake cache (<kbd>CTRL</kbd> + <kbd>SHIFT</kbd> + <kbd>P</kbd> and search for "Delete cache and reconfigure").
- Then the CMake extension should pick it up and you can run the tests as usual with the triangle icon.
