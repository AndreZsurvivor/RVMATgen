#include "RVMATgen.h"

//std::string texture_dir = R"(D:\stMo_assets_source\vehicles\civilian\Bus_Citaro\export_SP\Ceiling_backint)";
rvmatGen::Scanner scanner;

void RVMATgenLayer::createWindow_Config()
{
	ImGui::Begin("Configuration");//begin config window

	{
		static char texture_path[256] = "D:\\testconvert";
		ImGui::InputText("Texture directory path", texture_path, IM_ARRAYSIZE(texture_path));
		ImGui::SameLine(); rvmatGen::GUI::HelpMarker("enter the path to your folder with the textures\n");
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
		static char output_dir[256] = "D:\\testconvert\\output";
		ImGui::InputText("Output directory path", output_dir, IM_ARRAYSIZE(output_dir));
		ImGui::SameLine(); rvmatGen::GUI::HelpMarker(
			"enter the path to your output folder\n");
		ImGui::SameLine();
		bool clicked = false;
		static bool path_error = false;
		if (ImGui::Button("Set##OUTPUT"))
			clicked = true;
		if (clicked)
		{
			if (rvmatGen::pathIsValid(output_dir))
			{
				path_error = false;
				rvmatGen::Config::set_output_dir(output_dir);
			}
			else
				path_error = true;
		}
		if (path_error)
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "***OUTPUT_PATH_ERROR*** path or directory does not exist.");
	}
	{
		static char imagetopaa_path[256] = "E:\\SteamLibrary\\steamapps\\common\\DayZ Tools\\Bin\\ImageToPAA\\ImageToPAA.exe";
		ImGui::InputText("ImageToPAA path", imagetopaa_path, IM_ARRAYSIZE(imagetopaa_path));
		ImGui::SameLine(); rvmatGen::GUI::HelpMarker(
			"enter the path to your copy of imagetopaa.exe\n");
		ImGui::SameLine();
		bool clicked = false;
		static bool path_error = false;
		if (ImGui::Button("Set##IMAGETOPAA"))
			clicked = true;
		if (clicked)
		{
			if (rvmatGen::isValidImagetopaaExe(imagetopaa_path))
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