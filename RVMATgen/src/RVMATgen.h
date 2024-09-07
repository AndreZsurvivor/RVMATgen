#pragma once
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <filesystem>
#include <thread>
#include <mutex>
#include <queue>
//Walnut
#include "Walnut/Application.h"
#include "Walnut/Image.h"
//RVMATgen
#include "Scanner/Scanner.h"
#include "Config/Config.h"
#include "TextureManager/TextureManager.h"
#include "RVMATcreator/RVMATcreator.h"


class RVMATgenLayer : public Walnut::Layer
{
	friend class RVMATcreator;
public:
	virtual void OnUIRender() override
	{
		createWindow_Config();
		createWindow_Parameter();
		createWindow_TextureList();
#ifdef _DEBUG
		createWindow_Debug();
		ImGui::ShowDemoWindow();
#endif
	}
	static rvmatGen::TextureManager& get_TextureManager() { return m_texture_manager; }

private:
	static rvmatGen::TextureManager m_texture_manager;
	rvmatGen::Scanner m_scanner;
	rvmatGen::RVMATcreator m_rvmatCreator;

	bool createWindow_Config();
	bool createWindow_Parameter();
	bool createWindow_TextureList();
#ifdef _DEBUG
	bool createWindow_Debug();
#endif
};

//Utility function declarations
namespace rvmatGen
{
	namespace GUI
	{
		void HelpMarker(const char* desc);
		void PlusMinusRGB(std::string name, ImVec4& rgba_vector);
	}
	
	bool pathIsValid(const std::string& path);
	bool isValidImagetopaaExe(const std::string& path);
	std::string quoteString(const std::string& str);
	std::vector<const char*> findAndCopyStrings(const std::vector<std::string>& input, const std::string& token);
	int runImageToPAA(const std::string& exePath, const std::string& source, const std::string& destination = "", int size = -1);
	void convertImage(const std::string& exePath, const std::filesystem::path& inputFile, const std::filesystem::path& outputDir);
	void convertImagesInParallel(const std::string& exePath, const std::string& inputDir, const std::string& outputDir);
}