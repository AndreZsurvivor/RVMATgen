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
			std::string destination = rvmatGen::Config::get_mod_data_dir();
			std::string exepath = rvmatGen::Config::get_imagetopaa_path();
			rvmatGen::convertImagesInParallel(exepath, source, destination);
		}
	}
	{
		bool clicked = false;
		if (ImGui::Button("RVMAT"))
			clicked = true;
		if (clicked)
		{
			auto texture_sets = m_texture_manager.get_texture_sets();
			for (const auto& textureSet : texture_sets)
			{
				bool success = m_rvmatCreator.createRVMAT(textureSet, "udim");
			}
		}
	}
	ImGui::End();//end config window
}
