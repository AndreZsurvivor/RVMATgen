#include "RVMATgen.h"


bool RVMATgenLayer::createWindow_TextureList()
{
    ImGui::SetWindowFontScale(0.95);
    ImGui::Begin("Texture List");
    ImGui::SetWindowFontScale(0.9);
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
        ImGui::TextWrapped("No textures found. Use the 'Scan' button in the Configuration window to load textures.");
        ImGui::End();
        return false;
    }

    ImGui::Text("Texture Sets  -> RVMAT");
    if (ImGui::BeginListBox("##Texture Sets", ImVec2(-1, 350)))
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
    ImGui::NewLine(); ImGui::NewLine();
    //image converter button
    {
        static bool path_error = false;
        bool clicked = false;
        if (ImGui::Button("Convert Scanned Files to PAA"))
            clicked = true;
        if (clicked)
        {
            std::string source = rvmatGen::Config::get_texture_dir();
            std::string destination = rvmatGen::Config::get_output_dir();
            std::string exepath = rvmatGen::Config::get_imagetopaa_path();
            path_error = !rvmatGen::pathIsValid(source.c_str());
            path_error = !rvmatGen::pathIsValid(destination.c_str());
            path_error = !rvmatGen::isValidImagetopaaExe(exepath.c_str());

            if (!path_error)
            {
                std::vector<std::string>& texture_keys = m_texture_manager.get_texture_keys();
                rvmatGen::convertImagesInParallel(exepath, source, destination);
            }
            else
                path_error = true;
        }
        if (path_error)
            ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "***PATH_ERROR***");
    }
    ImGui::End();
    return true;
}