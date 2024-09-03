#pragma once
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "Config/Config.h"

namespace rvmatGen
{
    class RVMATcreator
    {
    public:
        RVMATcreator() = default;


        void setSpecularPower(float power) { m_specularPower = power; }
        void setSpecularRGB(float r, float g, float b) {
            m_specularR = r;
            m_specularG = g;
            m_specularB = b;
        }

        bool createRVMAT(const std::string& textureSet, const std::string& udim) {
            std::string rvmatContent = generateRVMATContent(textureSet, udim);
            return writeRVMATFile(textureSet, udim, rvmatContent);
        }

    private:
        float m_specularPower = 50.0f;
        float m_specularR = 0.1f, m_specularG = 0.1f, m_specularB = 0.1f;
        float m_ambientR = 1.0f, m_ambientG = 1.0f, m_ambientB = 1.0f;
        float m_forcedDiffuseR = 0.0f, m_forcedDiffuseG = 0.0f, m_forcedDiffuseB = 0.0f;
        float m_emmisiveR = 0.0f, m_emmisiveG = 0.0f, m_emmisiveB = 0.0f;

        bool writeRVMATFile(const std::string& textureSet, const std::string& udim, const std::string& content);
        std::string generateRVMATContent(const std::string& textureSet, const std::string& udim);
        std::string getTexturePath(const std::string& textureSet, const std::string& udim, const std::string& type);

        std::unordered_map<std::string, std::string> m_defaultTextures =
        {
            {"co", "#(argb,8,8,3)color(0,0,0,1,CO)"},
            {"nohq", "#(argb,8,8,3)color(0.5,0.5,1,1,NOHQ)"},
            {"smdi", "#(argb,8,8,3)color(1,1,1,1,SMDI)"},
            {"as", "#(argb,8,8,3)color(1,1,1,1,AS)"}
        };
    };
}
