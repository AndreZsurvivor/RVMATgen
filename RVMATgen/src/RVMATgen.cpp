
#include "RVMATgen.h"
#include "Walnut/EntryPoint.h"



class RVMATgenLayer : public Walnut::Layer
{
public:

	virtual void OnUIRender() override
	{
		createWindow_Config();
		createWindow_TextureList();


		ImGui::ShowDemoWindow();
	}
private:
	rvmatGen::TextureManager m_texture_manager;
	rvmatGen::Scanner m_scanner;
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "RVMAT Generator 3000";

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