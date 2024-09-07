#include "RVMATgen.h"

rvmatGen::Scanner scanner;

bool RVMATgenLayer::createWindow_Config()
{
	ImGui::SetWindowFontScale(0.95);
	ImGui::Begin("Configuration");//begin config window
	ImGui::SetWindowFontScale(0.9);
	static char scan_prefix[24] = "";
	static char texture_path[256] = "D:\\testconvert";
	static char output_dir[256] = "D:\\testconvert\\output";
	static char imagetopaa_path[256] = "E:\\SteamLibrary\\steamapps\\common\\DayZ Tools\\Bin\\ImageToPAA\\ImageToPAA.exe";
	static bool path_error_scan = false;
	if (path_error_scan)
		ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "***PATH_ERROR*** some path or directory does not exist.");

	ImGui::InputText("Source Directory Path", texture_path, IM_ARRAYSIZE(texture_path));
	ImGui::SameLine(); rvmatGen::GUI::HelpMarker("enter the path to your source texture directory\n");
	ImGui::SameLine();
	bool clicked = false;

	if (ImGui::Button("Scan"))
		clicked = true;
	if (clicked)
	{
		if (rvmatGen::pathIsValid(texture_path) && rvmatGen::pathIsValid(output_dir) && rvmatGen::isValidImagetopaaExe(imagetopaa_path))
		{
			path_error_scan = false;
			rvmatGen::Config::set_texture_dir(texture_path);
			rvmatGen::Config::set_output_dir(output_dir);
			rvmatGen::Config::set_imagetopaa_path(imagetopaa_path);
			rvmatGen::Config::set_scan_prefix(scan_prefix);
			m_texture_manager.scan_and_update(texture_path);
		}
		else
			path_error_scan = true;


	}

	ImGui::InputText("Output Directory Path", output_dir, IM_ARRAYSIZE(output_dir));
	ImGui::SameLine(); rvmatGen::GUI::HelpMarker("enter the path to your output folder\n");
#ifdef _DEBUG
	ImGui::SameLine();
	clicked = false;
	static bool path_error_output = false;
	if (ImGui::Button("Set##OUTPUT"))
		clicked = true;
	if (clicked)
	{
		if (rvmatGen::pathIsValid(output_dir))
		{
			path_error_output = false;
			rvmatGen::Config::set_output_dir(output_dir);
		}
		else
			path_error_output = true;
	}
	if (path_error_output)
		ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "***OUTPUT_PATH_ERROR*** path or directory does not exist.");
#endif
	ImGui::InputText("ImageToPAA path", imagetopaa_path, IM_ARRAYSIZE(imagetopaa_path));
	ImGui::SameLine(); rvmatGen::GUI::HelpMarker("enter the path to your copy of imagetopaa.exe\n");
#ifdef _DEBUG
	ImGui::SameLine();
	clicked = false;
	static bool path_error_imagetopaa = false;
	if (ImGui::Button("Set##IMAGETOPAA"))
		clicked = true;
	if (clicked)
	{
		if (rvmatGen::isValidImagetopaaExe(imagetopaa_path))
		{
			path_error_imagetopaa = false;
			rvmatGen::Config::set_imagetopaa_path(imagetopaa_path);
		}
		else
			path_error_imagetopaa = true;
	}
	if (path_error_imagetopaa)
		ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "***IMAGETOPAA_PATH_ERROR*** path does not exist.");
#endif
	{
		
		ImGui::InputText("Scan Prefix", scan_prefix, IM_ARRAYSIZE(scan_prefix));
		ImGui::SameLine(); rvmatGen::GUI::HelpMarker("leave empty to scan all files in source dir\n");
#ifdef _DEBUG
		ImGui::SameLine();
		bool clicked = false;
		if (ImGui::Button("Set##SCANPREFIX"))
			clicked = true;
		if (clicked)
		{
			rvmatGen::Config::set_scan_prefix(scan_prefix);
		}
#endif
	}
	ImGui::End();//end config window
	return true;
}