#pragma once
#include <filesystem>

namespace Cool {

/// Opens the link in the user's default web browser
void open_link(const char* link);

/// Opens the file in the default configured software
void open_file(std::filesystem::path const& file_path);

/// Opens a file explorer and focus / select the given file or folder
void open_focused_in_explorer(std::filesystem::path const& path);

/// Opens a file explorer in the given folder
void open_folder_in_explorer(std::filesystem::path const& folder_path);

} // namespace Cool