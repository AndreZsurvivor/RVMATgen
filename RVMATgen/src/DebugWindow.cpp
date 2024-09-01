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
			std::string source = "D:\\testconvert\\input.png";
			std::string destination = "D:\\testconvert\\output.paa";
			std::string exepath = rvmatGen::Config::get_imagetopaa_path();
			rvmatGen::runImageToPAA(exepath, source, destination);
		}
	}
	ImGui::End();//end config window
}
