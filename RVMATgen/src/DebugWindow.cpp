#include "RVMATgen.h"

void RVMATgenLayer::createWindow_Debug()
{
	ImGui::Begin("***DEBUG***");//begin config window
	{
		bool clicked = false;
		if (ImGui::Button("ImageToPAA"))
			clicked = true;
		if (clicked)
		{
			std::string source = rvmatGen::Config::get_texture_dir();
			std::string destination = rvmatGen::Config::get_output_dir();
			std::string exepath = rvmatGen::Config::get_imagetopaa_path();
			rvmatGen::convertImagesInParallel(exepath, source, destination);
		}
	}
	ImGui::End();//end config window
}
