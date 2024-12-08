#include <imgui.h>
#include "imgui/misc/cpp/imgui_stdlib.h"
#include "open/open.hpp"
#include "quick_imgui/quick_imgui.hpp"

auto main(int argc, char* argv[]) -> int
{
    // It's very important to set the locale to handle paths with characters like é and 分 on Windows
#ifdef _WIN32
    if (!std::setlocale(LC_ALL, ".65001"))
    {
        assert(false);
    }
#endif

    bool const should_run_imgui_tests = argc < 2 || strcmp(argv[1], "-nogpu") != 0; // NOLINT(*pointer-arithmetic)
    if (!should_run_imgui_tests)
        return 0;

    auto link = std::string{"https://github.com/CoolLibs/open/blob/main/tests/logo.png"};
    auto path = std::string{TESTS_FOLDER} + "/logo.png";

    quick_imgui::loop("open tests", [&]() {
        ImGui::Begin("open tests");

        ImGui::InputText("Link", &link);

        if (ImGui::Button("Open link"))
            Cool::open_link(link.c_str());

        ImGui::NewLine();

        ImGui::InputText("Path", &path);

        if (ImGui::Button("Reveal file in explorer"))
            Cool::open_focused_in_explorer(path);

        if (ImGui::Button("Open file"))
            Cool::open_file(path);

        if (ImGui::Button("Open folder in explorer"))
            Cool::open_folder_in_explorer(path);

        ImGui::End();
    });

    return 0;
}