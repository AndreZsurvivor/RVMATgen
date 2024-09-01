#include "RVMATgen.h"


void RVMATgenLayer::createWindow_TextureList()
{
    ImGui::Begin("Texture List");

    const auto& texture_keys = m_texture_manager.get_texture_keys();

    // Convert the keys to const char* for ImGui
    std::vector<const char*> display_keys;
    for (const auto& key : texture_keys)
        display_keys.push_back(key.c_str());

    static int item_current_idx = 0;

    if (display_keys.empty())
    {
        ImGui::Text("No textures found. Use the 'Scan' button in the Configuration window to load textures.");
    }
    else
    {
        if (ImGui::BeginListBox("Textures"))
        {
            for (int n = 0; n < display_keys.size(); n++)
            {
                const bool is_selected = (item_current_idx == n);
                if (ImGui::Selectable(display_keys[n], is_selected))
                    item_current_idx = n;

                if (is_selected)
                    ImGui::SetItemDefaultFocus();
            }
            ImGui::EndListBox();
        }

        // Display selected texture details
        if (item_current_idx < texture_keys.size())
        {
            const std::string& selected_key = texture_keys[item_current_idx];
            const std::string& file_path = m_texture_manager.get_texture_path(selected_key);

            ImGui::Text("Selected Texture:");
            ImGui::Text("Key: %s", selected_key.c_str());
            ImGui::Text("File: %s", file_path.c_str());
        }
    }

    ImGui::End();
}