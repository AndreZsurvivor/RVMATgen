#pragma once
#include <string>
#include <map>
#include <filesystem>

//Walnut
#include "Walnut/Application.h"
#include "Walnut/Image.h"

#include "Scanner/Scanner.h"
#include "Config/Config.h"
#include "TextureManager/TextureManager.h"


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

	void createWindow_Config();
	void createWindow_TextureList();

};



//Utility function declarations
namespace rvmatGen
{
    bool pathIsValid(const std::string& path);
}