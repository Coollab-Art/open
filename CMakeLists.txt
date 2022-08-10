cmake_minimum_required(VERSION 3.8)

add_library(open_link)
add_library(open_link::open_link ALIAS open_link)
target_compile_features(open_link PUBLIC cxx_std_11)

# ---Add source files---
target_include_directories(open_link PUBLIC include)
target_sources(open_link PRIVATE
    src/open_link.cpp
)

# ---Setup warnings---
if (OPEN_LINK_ENABLE_WARNINGS_AS_ERRORS)
    message("-- [open_link] Enabling warnings as errors for open_link")
    if(MSVC)
        target_compile_options(open_link PRIVATE /WX /W4)
    else()
        target_compile_options(open_link PRIVATE -Werror -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion -Wno-unused-result)
    endif()
else()
    message("-- [open_link] Not using warnings as errors for open_link")
endif()
