#pragma once
#include "imgui.h"

namespace rvmatGen
{
	struct RVMATparameters
	{
		std::string texture_set;
		ImVec4 ambientRGBA;
		ImVec4 diffuseRGBA;
		ImVec4 forcedDiffuseRGBA;
		ImVec4 emmisiveRGBA;
		ImVec4 specularRGBA;
		int specularPower = 0;
		ImVec2 fresnel;

	};
}