#pragma once
#include "imgui.h"
#include "structs.h"

namespace rvmatGen
{
    const FresnelDefaultValue fresnelValues[] =
    {
        {"Aluminum",    ImVec2(1.3f, 7.0f)},
        {"Cobalt",      ImVec2(0.2f, 3.0f)},
        {"Copper",      ImVec2(2.08f, 7.15f)},
        {"Gold",        ImVec2(0.3f, 3.0f)},
        {"Iron",        ImVec2(3.12f, 3.87f)},
        {"Lead",        ImVec2(1.44f, 4.35f)},
        {"Molybdenum",  ImVec2(2.77f, 3.74f)},
        {"Nickel",      ImVec2(2.59f, 4.55f)},
        {"Palladium",   ImVec2(2.17f, 5.22f)},
        {"Platinum",    ImVec2(2.92f, 5.07f)},
        {"Silver",      ImVec2(0.2f, 3.0f)},
        {"Titanium",    ImVec2(3.21f, 4.01f)},
        {"Vanadium",    ImVec2(2.94f, 3.50f)},
        {"Tungsten",    ImVec2(3.48f, 2.79f)}
    };

    const ScanningPattern patterns[] =
    {
        {"UDIM",        R"(_(\w+)(\d{4})_(co|nohq|smdi|as)\.(png|paa))"},
        {"Normal",      R"(_(\w+)_(co|nohq|smdi|as)\.(png|paa))"}
    };
}