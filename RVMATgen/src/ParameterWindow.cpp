#include "RVMATgen.h"

void RVMATgenLayer::createWindow_Parameter()
{
	ImGui::Begin("RVMAT Parameters");//begin config window

	ImGui::Text("Mod Texture Directory");
	static char mod_texture_dir[128] = "mymod\\data";
	ImGui::InputText("##MOD_TEXTURE_DIR", mod_texture_dir, IM_ARRAYSIZE(mod_texture_dir));
	ImGui::SameLine(); rvmatGen::GUI::HelpMarker("enter the relative  path to your texture folder in the mod\n");

	static float textWidth = 500.0f;
	static float floatWidth = 100.0f;

	ImGui::NewLine();	ImGui::Text("Ambient");
	static ImVec4 AmbientRGBA = { 1.0f, 1.0f, 1.0f, 1.0f };
						ImGui::Text("R"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##AMBIENT_R", &AmbientRGBA.x, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("G"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##AMBIENT_G", &AmbientRGBA.y, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("B"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##AMBIENT_B", &AmbientRGBA.z, 0.01f, 1.0f, "%.2f");
	rvmatGen::GUI::PlusMinusRGB("AMBIENT", AmbientRGBA);
	ImGui::SameLine();	ImGui::Text("     A"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##AMBIENT_A", &AmbientRGBA.w, 0.01f, 1.0f, "%.2f");

	ImGui::NewLine();	ImGui::Text("Diffuse");
	static ImVec4 DiffuseRGBA = { 0.5f, 0.5f, 0.5f, 1.0f };
						ImGui::Text("R"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##DIFFUSE_R", &DiffuseRGBA.x, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("G"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##DIFFUSE_G", &DiffuseRGBA.y, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("B"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##DIFFUSE_B", &DiffuseRGBA.z, 0.01f, 1.0f, "%.2f");
	rvmatGen::GUI::PlusMinusRGB("DIFFUSE", DiffuseRGBA);
	ImGui::SameLine();	ImGui::Text("     A"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##DIFFUSE_A", &DiffuseRGBA.w, 0.01f, 1.0f, "%.2f");

	ImGui::NewLine(); 	ImGui::Text("Forced Diffuse");
	static ImVec4 forcedDiffuseRGBA = { 0.0f, 0.0f, 0.0f, 0.0f };
						ImGui::Text("R"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##FORCED_DIFFUSE_R", &forcedDiffuseRGBA.x, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("G"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##FORCED_DIFFUSE_G", &forcedDiffuseRGBA.y, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("B"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##FORCED_DIFFUSE_B", &forcedDiffuseRGBA.z, 0.01f, 1.0f, "%.2f");
	rvmatGen::GUI::PlusMinusRGB("FORCED_DIFFUSE", forcedDiffuseRGBA);
	ImGui::SameLine();	ImGui::Text("     A"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##FORCED_DIFFUSE_A", &forcedDiffuseRGBA.w, 0.01f, 1.0f, "%.2f");

	ImGui::NewLine(); 	ImGui::Text("Emmisive");
	static ImVec4 emmisiveRGBA = { 0.0f, 0.0f, 0.0f, 1.0f };
						ImGui::Text("R"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##EMMISIVE_R", &emmisiveRGBA.x, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("G"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##EMMISIVE_G", &emmisiveRGBA.y, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("B"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##EMMISIVE_B", &emmisiveRGBA.z, 0.01f, 1.0f, "%.2f");
	rvmatGen::GUI::PlusMinusRGB("EMMISIVE", emmisiveRGBA);
	ImGui::SameLine();	ImGui::Text("     A"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##EMMISIVE_A", &emmisiveRGBA.w, 0.01f, 1.0f, "%.2f");

	ImGui::NewLine(); 	ImGui::Text("Specular");
	static ImVec4 specularRGBA = { 0.1f, 0.1f, 0.1f, 1.0f };
	ImGui::Text("R"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##SPECULAR_R", &specularRGBA.x, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("G"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##SPECULAR_G", &specularRGBA.y, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("B"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##SPECULAR_B", &specularRGBA.z, 0.01f, 1.0f, "%.2f");
	rvmatGen::GUI::PlusMinusRGB("SPECULAR", specularRGBA);
	ImGui::SameLine();	ImGui::Text("     A"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##SPECULAR_A", &specularRGBA.w, 0.01f, 1.0f, "%.2f");





	{
		bool clicked = false;
		if (ImGui::Button("create RVMAT Files"))
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