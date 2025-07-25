#include "open/open.hpp"
#include <cassert>
#include <filesystem>

static auto make_valid_path(std::filesystem::path const& path) -> std::filesystem::path
{
    try
    {
        return std::filesystem::weakly_canonical(path); // weakly_canonical is required, e.g. to convert / to \ on Windows (paths with / will not work)
    }
    catch (...)
    {
        return path;
    }
}

static auto path_exists(std::filesystem::path const& path) -> bool
{
    try
    {
        return std::filesystem::exists(path);
    }
    catch (std::exception const&)
    {
        return false;
    }
}

static auto find_first_existing_folder_in_path(std::filesystem::path path) -> std::filesystem::path
{
    // NB: we assume that either path does not exist, or is a folder
    // If path was an existing file, we would need to add this:
    //
    // if (File::exists(path))
    // {
    //     if (is_folder(path))
    //         return path;
    //     else
    //         return without_file_name(path);
    // }

    auto prev_size = path.string().size();
    while (true)
    {
        if (path_exists(path))
            break;

        path            = path.parent_path();
        auto const size = path.string().size();
        if (size >= prev_size)
            break;
        prev_size = size;
    }
    return path;
}

#if defined(_WIN32)
#include <windows.h>

namespace Cool {

void open_link(const char* link)
{
    ShellExecuteA(nullptr, "open", link, nullptr, nullptr, SW_SHOWNORMAL);
}

void open_file(std::filesystem::path const& file_path)
{
    assert(!std::filesystem::is_directory(file_path));
    ShellExecuteW(nullptr, L"open", make_valid_path(file_path).wstring().c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

void open_focused_in_explorer(std::filesystem::path const& path)
{
    if (path_exists(path))
        ShellExecuteW(nullptr, L"open", L"explorer.exe", (L"/select,\"" + make_valid_path(path).wstring() + L"\"").c_str(), nullptr, SW_SHOWNORMAL);
    else
        open_folder_in_explorer(path);
}

void open_folder_in_explorer(std::filesystem::path const& folder_path)
{
    assert(!path_exists(folder_path) || std::filesystem::is_directory(folder_path));
    ShellExecuteW(nullptr, L"open", find_first_existing_folder_in_path(make_valid_path(folder_path)).wstring().c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

} // namespace Cool

#endif

#if defined(__linux__)
#include <string>

namespace Cool {

void open_link(const char* link)
{
    std::system((std::string{"xdg-open \""} + link + '\"').c_str());
}

void open_file(std::filesystem::path const& file_path)
{
    assert(!std::filesystem::is_directory(file_path));
    std::system(("xdg-open \"" + make_valid_path(file_path).string() + '\"').c_str());
}

void open_focused_in_explorer(std::filesystem::path const& path)
{
    try
    {
        open_folder_in_explorer(path.parent_path()); // TODO properly focus the file, for now we just open the containing folder
    }
    catch (...)
    {}
}

void open_folder_in_explorer(std::filesystem::path const& folder_path)
{
    assert(!path_exists(folder_path) || std::filesystem::is_directory(folder_path));
    std::system(("xdg-open \"" + find_first_existing_folder_in_path(make_valid_path(folder_path)).string() + '\"').c_str());
}

} // namespace Cool

#endif

#if defined(__APPLE__)
#include <string>

namespace Cool {

void open_link(const char* link)
{
    std::system((std::string{"open \""} + link + '\"').c_str());
}

void open_file(std::filesystem::path const& file_path)
{
    assert(!std::filesystem::is_directory(file_path));
    std::system(("open \"" + make_valid_path(file_path).string() + '\"').c_str());
}

void open_focused_in_explorer(std::filesystem::path const& path)
{
    if (path_exists(path))
        std::system(("open -R \"" + make_valid_path(path).string() + '\"').c_str());
    else
        open_folder_in_explorer(path);
}

void open_folder_in_explorer(std::filesystem::path const& folder_path)
{
    assert(!path_exists(folder_path) || std::filesystem::is_directory(folder_path));
    std::system(("open \"" + find_first_existing_folder_in_path(make_valid_path(folder_path)).string() + '\"').c_str());
}

} // namespace Cool

#endif
