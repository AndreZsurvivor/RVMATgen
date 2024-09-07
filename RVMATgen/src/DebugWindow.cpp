#ifdef _DEBUG
#include "RVMATgen.h"

bool RVMATgenLayer::createWindow_Debug()
{
	ImGui::Begin("***DEBUG***");//begin config window
	{
		static bool path_error = false;
		bool clicked = false;
		if (ImGui::Button("ImageToPAA"))
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
				rvmatGen::convertImagesInParallel(exepath, source, destination);
			else
				path_error = true;
		}
		if (path_error)
			ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "***PATH_ERROR***");
	}

	ImGui::End();//end config window
	return true;
}
#endif