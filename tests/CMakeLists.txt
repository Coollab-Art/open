cmake_minimum_required(VERSION 3.8)
project(open_link-tests)

add_executable(${PROJECT_NAME} tests.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /WX /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
endif()

set(OPEN_LINK_ENABLE_WARNINGS_AS_ERRORS ON)
add_subdirectory(.. ${CMAKE_CURRENT_SOURCE_DIR}/build/open_link)
target_link_libraries(${PROJECT_NAME} PRIVATE open_link::open_link)
