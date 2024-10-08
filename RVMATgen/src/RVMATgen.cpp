
#include "RVMATgen.h"
#include "Walnut/EntryPoint.h"
rvmatGen::TextureManager RVMATgenLayer::m_texture_manager;

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "RVMAT Generator 3000 v0.1 by AndreZ";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<RVMATgenLayer>();
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}
