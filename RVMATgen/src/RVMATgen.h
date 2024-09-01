#pragma once
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <filesystem>
//Walnut
#include "Walnut/Application.h"
#include "Walnut/Image.h"
//RVMATgen
#include "Scanner/Scanner.h"
#include "Config/Config.h"
#include "TextureManager/TextureManager.h"


class RVMATgenLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override
	{
		createWindow_Debug();
		createWindow_Config();
		createWindow_TextureList();

		ImGui::ShowDemoWindow();
	}
private:
	rvmatGen::TextureManager m_texture_manager;
	rvmatGen::Scanner m_scanner;

	void createWindow_Debug();
	void createWindow_Config();
	void createWindow_TextureList();
	
};

//Utility function declarations
namespace rvmatGen
{
    bool pathIsValid(const std::string& path);
	bool isValidImagetopaaExe(const std::string& path);
	std::string quoteString(const std::string& str);
	std::vector<const char*> findAndCopyStrings(const std::vector<std::string>& input, const std::string& token);
	int runImageToPAA(const std::string& exePath, const std::string& source, const std::string& destination = "", int size = -1);
}