# open

Open any link, folder or file. Cross-platform.

## Including

To add this library to your project, simply add these two lines to your _CMakeLists.txt_:

```cmake
add_subdirectory(path/to/open)
target_link_libraries(${PROJECT_NAME} PRIVATE Cool::open)
```

Then include it as:

```cpp
#include <open/open.hpp>
```

## Usage

⚠ You might really want to consider calling
```cpp
// It's very important to set the locale to handle paths with characters like é and 分 on Windows
if (!std::setlocale(LC_ALL,
#ifdef _WIN32
                    ".65001" // utf-8
#else
                    "UTF-8"
#endif
    ))
{
    assert(false);
}
```
at the beginning of your application, to make sure special characters are handled properly.

```cpp
Cool::open_link("https://github.com/CoolLibs/open");
```

## Running the tests

Simply use "tests/CMakeLists.txt" to generate a project, then run it.

<ins>_Detailed steps for VSCode:_</ins>

- Go to _Settings_ (<kbd>CTRL</kbd> + <kbd>,</kbd>), select _Workspace_, search for "Source Directory" and set it as `${workspaceFolder}/tests`.
- Reload the window (<kbd>CTRL</kbd> + <kbd>SHIFT</kbd> + <kbd>P</kbd> and search for "Reload Window").
- Delete the CMake cache (<kbd>CTRL</kbd> + <kbd>SHIFT</kbd> + <kbd>P</kbd> and search for "Delete cache and reconfigure").
- Then the CMake extension should pick it up and you can run the tests as usual with the triangle icon.
