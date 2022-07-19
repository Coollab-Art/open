#include <open_link/open_link.hpp>

// Thanks to https://stackoverflow.com/questions/17347950/how-do-i-open-a-url-from-c

#if defined(_WIN32)

#include <windows.h>
// These two includes must be in that order, because windows.h #defines things that impact shellapi.h
#include <shellapi.h>

namespace open_link {
void open(const wchar_t* link)
{
    ShellExecuteW(0, 0, link, 0, 0, SW_SHOW);
}
void open(const char* link)
{
    ShellExecuteA(0, 0, link, 0, 0, SW_SHOW);
}
} // namespace open_link

#endif

#if defined(__linux__)

namespace open_link {
void open(const wchar_t* link)
{
}
void open(const char* link)
{
}
} // namespace open_link

#endif

#if defined(__APPLE__)

namespace open_link {
void open(const wchar_t* link)
{
}
void open(const char* link)
{
}
} // namespace open_link

#endif
