#include "RVMATgen.h"

//std::string texture_dir = R"(D:\stMo_assets_source\vehicles\civilian\Bus_Citaro\export_SP\Ceiling_backint)";
rvmatGen::Scanner scanner;



static void HelpMarker(const char* desc)
{
	ImGui::TextDisabled("*");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

void RVMATgenLayer::createWindow_Config()
{
	ImGui::Begin("Configuration");//begin config window

	{
		static char texture_path[256] = "path\\to\\textures";
		ImGui::InputText("Texture directory path", texture_path, IM_ARRAYSIZE(texture_path));
		ImGui::SameLine(); HelpMarker(
			"enter the path to your folder with the textures\n");
		ImGui::SameLine();
		bool clicked = false;
		static bool path_error = false;
		if (ImGui::Button("Scan"))
			clicked = true;
		if (clicked)
		{
			if (rvmatGen::pathIsValid(texture_path))
			{
				path_error = false;
				rvmatGen::Config::set_texture_dir(texture_path);
				RVMATgenLayer layer;
				m_texture_manager.scan_and_update(texture_path);
			}
			else
				path_error = true;
		}
		if (path_error)
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "***TEXTURE_PATH_ERROR*** path or directory does not exist.");
	}
	{
		static char mod_path[256] = "path\\to\\mod";
		ImGui::InputText("Mod directory path", mod_path, IM_ARRAYSIZE(mod_path));
		ImGui::SameLine(); HelpMarker(
			"enter the path to your mod folder\n");
		ImGui::SameLine();
		bool clicked = false;
		static bool path_error = false;
		if (ImGui::Button("Set##MOD"))
			clicked = true;
		if (clicked)
		{
			if (rvmatGen::pathIsValid(mod_path))
			{
				path_error = false;
				rvmatGen::Config::set_mod_data_dir(mod_path);
			}
			else
				path_error = true;
		}
		if (path_error)
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "***MOD_PATH_ERROR*** path or directory does not exist.");
	}
	{
		static char imagetopaa_path[256] = "path\\to\\imagetopaa.exe";
		ImGui::InputText("ImageToPAA path", imagetopaa_path, IM_ARRAYSIZE(imagetopaa_path));
		ImGui::SameLine(); HelpMarker(
			"enter the path to your copy of imagetopaa.exe\n");
		ImGui::SameLine();
		bool clicked = false;
		static bool path_error = false;
		if (ImGui::Button("Set##IMAGETOPAA"))
			clicked = true;
		if (clicked)
		{
			if (rvmatGen::pathIsValid(imagetopaa_path))
			{
				path_error = false;
				rvmatGen::Config::set_imagetopaa_path(imagetopaa_path);
			}
			else
				path_error = true;
		}
		if (path_error)
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "***IMAGETOPAA_PATH_ERROR*** path does not exist.");
	}




	ImGui::End();//end config window
}