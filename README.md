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
