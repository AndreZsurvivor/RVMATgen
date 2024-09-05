#include "RVMATgen.h"


bool RVMATgenLayer::createWindow_TextureList()
{
    ImGui::Begin("Texture List");

    const auto& texture_keys = m_texture_manager.get_texture_keys();
    const auto& texture_sets = m_texture_manager.get_texture_sets();

    // Convert the keys to const char* for ImGui
    std::vector<const char*> display_textures;
    for (const auto& key : texture_keys)
        display_textures.push_back(key.c_str());

    std::vector<const char*> display_texture_sets;
    for (const auto& key : texture_sets)
        display_texture_sets.push_back(key.c_str());

    static int tex_current_idx = 0;
    static int texset_current_idx = 0;

    if (display_textures.empty())
    {
        ImGui::Text("No textures found. Use the 'Scan' button in the Configuration window to load textures.");
        ImGui::End();
        return false;
    }

    ImGui::Text("Texture Sets");
    if (ImGui::BeginListBox("##Texture Sets", ImVec2(-1, 400)))
    {
        for (int n = 0; n < display_texture_sets.size(); n++)
        {
            const bool is_selected = (texset_current_idx == n);
            if (ImGui::Selectable(display_texture_sets[n], is_selected))
                texset_current_idx = n;

            if (is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndListBox();
    }
    ImGui::Text("Texture Files");
    if (ImGui::BeginListBox("##Texture Files", ImVec2(-1, 100)))
    {
        display_textures = rvmatGen::findAndCopyStrings(texture_keys, display_texture_sets[texset_current_idx]);
        for (int n = 0; n < display_textures.size(); n++)
        {
            const bool is_selected = (tex_current_idx == n);
            if (ImGui::Selectable(display_textures[n], is_selected))
                tex_current_idx = n;

            if (is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndListBox();
    }

    // Display selected texture details
    if (tex_current_idx < texture_keys.size())
    {
        const std::string& selected_key = texture_keys[tex_current_idx];
        const std::string& file_path = m_texture_manager.get_texture_path(selected_key);

        ImGui::Text("Selected Texture:");
        ImGui::Text("Key: %s", selected_key.c_str());
        ImGui::Text("File: %s", file_path.c_str());
    }
    ImGui::End();
    return true;
}