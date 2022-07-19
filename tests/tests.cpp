#include <open_link/open_link.hpp>

// This should open the GitHub page of open_link twice.
auto main() -> int
{
    open_link::open(L"https://github.com/CoolLibs/open_link");
    open_link::open("https://github.com/CoolLibs/open_link");
}