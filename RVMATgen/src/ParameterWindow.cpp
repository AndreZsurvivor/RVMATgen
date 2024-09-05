#include "RVMATgen.h"
#include "structs.h"

bool RVMATgenLayer::createWindow_Parameter()
{
	ImGui::Begin("RVMAT Parameters");//begin config window


	const auto& texture_sets = m_texture_manager.get_texture_sets();
	if (texture_sets.empty())
	{
		ImGui::Text("No textures found. Use the 'Scan' button in the Configuration window to load textures.");
		ImGui::End();
		return false;
	}

	ImGui::Text("Mod Texture Directory");
	static char mod_data_dir[256] = "mymod\\data";
	ImGui::InputText("##MOD_TEXTURE_DIR", mod_data_dir, IM_ARRAYSIZE(mod_data_dir));
	ImGui::SameLine(); rvmatGen::GUI::HelpMarker("enter the relative  path to your texture folder in the mod\n");

	static float textWidth = 500.0f;
	static float floatWidth = 100.0f;
	static float intWidth = 125.0f;

	ImGui::NewLine();	ImGui::Text("Ambient");
	static ImVec4 ambientRGBA = { 1.0f, 1.0f, 1.0f, 1.0f };
						ImGui::Text("R"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##AMBIENT_R", &ambientRGBA.x, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("G"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##AMBIENT_G", &ambientRGBA.y, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("B"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##AMBIENT_B", &ambientRGBA.z, 0.01f, 1.0f, "%.2f");
	rvmatGen::GUI::PlusMinusRGB("AMBIENT", ambientRGBA);
	ImGui::SameLine();	ImGui::Text("     A"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##AMBIENT_A", &ambientRGBA.w, 0.01f, 1.0f, "%.2f");

	ImGui::NewLine();	ImGui::Text("Diffuse");
	static ImVec4 diffuseRGBA = { 0.5f, 0.5f, 0.5f, 1.0f };
						ImGui::Text("R"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##DIFFUSE_R", &diffuseRGBA.x, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("G"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##DIFFUSE_G", &diffuseRGBA.y, 0.01f, 1.0f, "%.2f");
	ImGui::SameLine();	ImGui::Text("B"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##DIFFUSE_B", &diffuseRGBA.z, 0.01f, 1.0f, "%.2f");
	rvmatGen::GUI::PlusMinusRGB("DIFFUSE", diffuseRGBA);
	ImGui::SameLine();	ImGui::Text("     A"); ImGui::SetNextItemWidth(floatWidth);
	ImGui::SameLine();	ImGui::InputFloat("##DIFFUSE_A", &diffuseRGBA.w, 0.01f, 1.0f, "%.2f");

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

	ImGui::NewLine(); ImGui::Text("Specular Power");
	static int specularPower = 50;
	ImGui::SameLine();	ImGui::SetNextItemWidth(intWidth); ImGui::InputInt("##SPECULAR_POWER", &specularPower, 1, 10);






	{
		bool clicked = false;
		if (ImGui::Button("create RVMAT Files"))
			clicked = true;
		if (clicked)
		{
			const std::string& prefix = rvmatGen::Config::get_modder_prefix();
			rvmatGen::Config::set_mod_data_dir(mod_data_dir);
			rvmatGen::RVMATparameters parameters;
			parameters.ambientRGBA = ambientRGBA;
			parameters.diffuseRGBA = diffuseRGBA;
			parameters.emmisiveRGBA = emmisiveRGBA;
			parameters.forcedDiffuseRGBA = forcedDiffuseRGBA;
			parameters.specularPower = specularPower;
			parameters.specularRGBA = specularRGBA;

			auto texture_sets = m_texture_manager.get_texture_sets();
			for (const auto& textureSet : texture_sets)
			{
				parameters.texture_set = textureSet;
				bool success = m_rvmatCreator.createRVMAT(parameters, prefix);
			}
		}
	}
	ImGui::End();//end config window
	return true;
}