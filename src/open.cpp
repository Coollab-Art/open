#include <open/open.hpp>

// Thanks to https://stackoverflow.com/questions/17347950/how-do-i-open-a-url-from-c

#if defined(_WIN32)

#include <windows.h>
// These two includes must be in that order, because windows.h #defines things that impact shellapi.h
#include <shellapi.h>

namespace Cool {
void open(const char* link)
{
    ShellExecuteA(nullptr, nullptr, link, nullptr, nullptr, SW_SHOW);
}
} // namespace Cool

#endif

#if defined(__linux__)

#include <string>

namespace Cool {
void open(const char* link)
{
    system((std::string{"xdg-open "} + link).c_str());
}
} // namespace Cool

#endif

#if defined(__APPLE__)

#include <string>

namespace Cool {
void open(const char* link)
{
    system((std::string{"open "} + link).c_str());
}
} // namespace Cool

#endif
