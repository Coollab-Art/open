#pragma once
#include <filesystem>

namespace Cool {

/// Opens the link in the user's default web browser, or the folder in the folder explorer, or the file in the default configured software.
void open(const char* link_or_path);
/// Opens the link in the user's default web browser, or the folder in the folder explorer, or the file in the default configured software.
inline void open(std::filesystem::path const& path)
{
    open(path.string().c_str());
}

} // namespace Cool