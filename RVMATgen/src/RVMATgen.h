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


void createWindow_Config();
void createWindow_TextureList();

namespace rvmatGen
{
    bool pathIsValid(const std::string& path);
}