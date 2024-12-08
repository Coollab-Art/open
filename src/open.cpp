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
    ShellExecuteW(nullptr, L"open", L"explorer.exe", (L"/select,\"" + make_valid_path(path).wstring() + L"\"").c_str(), nullptr, SW_SHOWNORMAL);
}

void open_folder_in_explorer(std::filesystem::path const& folder_path)
{
    assert(std::filesystem::is_directory(folder_path));
    ShellExecuteW(nullptr, L"open", make_valid_path(folder_path).wstring().c_str(), nullptr, nullptr, SW_SHOWNORMAL);
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
    assert(std::filesystem::is_directory(folder_path));
    std::system(("xdg-open \"" + make_valid_path(folder_path).string() + '\"').c_str());
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
    std::system(("open -R \"" + make_valid_path(file_path).string() + '\"').c_str());
}

void open_folder_in_explorer(std::filesystem::path const& folder_path)
{
    assert(std::filesystem::is_directory(folder_path));
    std::system(("open \"" + make_valid_path(folder_path).string() + '\"').c_str());
}

} // namespace Cool

#endif
