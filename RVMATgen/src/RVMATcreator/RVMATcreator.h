#pragma once
#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "Config/Config.h"
#include "structs.h"

namespace rvmatGen
{
    class RVMATcreator
    {
    public:
        RVMATcreator() = default;

        bool createRVMAT(const rvmatGen::RVMATparameters& parameters, const std::string& prefix)
        {
            std::string rvmatContent = generateRVMATContent(parameters);
            return writeRVMATFile(parameters.texture_set, rvmatContent, prefix);
        }

    private:

        bool writeRVMATFile(const std::string& texture_set, const std::string& content, const std::string& prefix);
        std::string generateRVMATContent(const rvmatGen::RVMATparameters& parameters);
        std::string getTexturePath(const std::string& textureSet, const std::string& type, const std::string& prefix);

        std::unordered_map<std::string, std::string> m_defaultTextures =
        {
            {"co", "#(argb,8,8,3)color(0,0,0,1,CO)"},
            {"nohq", "#(argb,8,8,3)color(0.5,0.5,1,1,NOHQ)"},
            {"smdi", "#(argb,8,8,3)color(1,1,1,1,SMDI)"},
            {"as", "#(argb,8,8,3)color(1,1,1,1,AS)"}
        };
    };
}
