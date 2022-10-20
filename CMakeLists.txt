cmake_minimum_required(VERSION 3.8)

add_library(open_link)
add_library(open_link::open_link ALIAS open_link)
target_compile_features(open_link PUBLIC cxx_std_11)

# ---Add source files---
target_include_directories(open_link PUBLIC include)
target_sources(open_link PRIVATE
    src/open_link.cpp
)

# Set warning level
if(MSVC)
    target_compile_options(open_link PRIVATE /W4)
else()
    target_compile_options(open_link PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion -Wno-unused-result)
endif()

# Maybe enable warnings as errors
set(WARNINGS_AS_ERRORS_FOR_OPEN_LINK OFF CACHE BOOL "ON iff you want to treat warnings as errors")
if(WARNINGS_AS_ERRORS_FOR_OPEN_LINK)
    if(MSVC)
        target_compile_options(open_link PRIVATE /WX)
    else()
        target_compile_options(open_link PRIVATE -Werror)
    endif()
endif()