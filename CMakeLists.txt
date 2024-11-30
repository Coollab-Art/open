cmake_minimum_required(VERSION 3.8)

set(WARNINGS_AS_ERRORS_FOR_OPEN OFF CACHE BOOL "ON iff you want to treat warnings as errors")

add_library(open)
add_library(Cool::open ALIAS open)
target_compile_features(open PUBLIC cxx_std_17)

# ---Add source files---
if(WARNINGS_AS_ERRORS_FOR_OPEN)
    target_include_directories(open PUBLIC include)
else()
    target_include_directories(open SYSTEM PUBLIC include)
endif()

target_sources(open PRIVATE
    src/open.cpp
)

# Set warning level
if(MSVC)
    target_compile_options(open PRIVATE /W4)
else()
    target_compile_options(open PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion -Wno-unused-result)
endif()

# Maybe enable warnings as errors
if(WARNINGS_AS_ERRORS_FOR_OPEN)
    if(MSVC)
        target_compile_options(open PRIVATE /WX)
    else()
        target_compile_options(open PRIVATE -Werror)
    endif()
endif()