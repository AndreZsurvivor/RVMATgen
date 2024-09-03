#include "RVMATcreator/RVMATcreator.h"
namespace rvmatGen
{
    std::string quoteString(const std::string& str);

    bool RVMATcreator::writeRVMATFile(const std::string& textureSet, const std::string& udim, const std::string& content)
    {
        std::string filename = "azw_" + textureSet + "_" + udim + ".rvmat";
        std::string fullPath = (std::filesystem::path(rvmatGen::Config::get_output_dir()) / filename).string();

        try {
            std::ofstream file(fullPath);
            if (!file.is_open()) {
                return false;
            }
            file << content;
            file.close();
            return true;
        }
        catch (const std::exception& e) {
            // Handle or log the error
            return false;
        }
    }
    std::string RVMATcreator::generateRVMATContent(const std::string& textureSet, const std::string& udim)
    {
        std::stringstream ss;
        ss << "ambient[] = {1,1,1,1};\n"
            << "diffuse[] = {0.5,0.5,0.5,1};\n"
            << "forcedDiffuse[] = {0,0,0,0};\n"
            << "emmisive[] = {0,0,0,1};\n"
            << "specular[] = {" << m_specularR << "," << m_specularG << "," << m_specularB << ",1};\n"
            << "specularPower = " << m_specularPower << ";\n"
            << "PixelShaderID = \"Super\";\n"
            << "VertexShaderID = \"Super\";\n"
            << "class Stage1\n"
            << "{\n"
            << "    texture = \"" << getTexturePath(textureSet, udim, "nohq") << "\";\n"
            << "    uvSource = \"tex\";\n"
            << "    class uvTransform\n"
            << "    {\n"
            << "        aside[] = {1,0,0};\n"
            << "        up[] = {0,1,0};\n"
            << "        dir[] = {0,0,0};\n"
            << "        pos[] = {0,0,0};\n"
            << "    };\n"
            << "};\n"
            // ... (include other stages similarly)
            << "class Stage7\n"
            << "{\n"
            << "    texture = \"dz\\data\\data\\env_land_co.paa\";\n"
            << "    useWorldEnvMap = \"true\";\n"
            << "    uvSource = \"tex\";\n"
            << "    class uvTransform\n"
            << "    {\n"
            << "        aside[] = {1,0,0};\n"
            << "        up[] = {0,1,0};\n"
            << "        dir[] = {0,0,0};\n"
            << "        pos[] = {0,0,0};\n"
            << "    };\n"
            << "};\n";

        return ss.str();
    }
    std::string RVMATcreator::getTexturePath(const std::string& textureSet, const std::string& udim, const std::string& type)
    {
        std::string source_filename = "azw_" + textureSet + "_" + type + ".png";
        std::string output_filename = "azw_" + textureSet + "_" + type + ".paa";


        std::string sourceDir = rvmatGen::Config::get_texture_dir();
        std::string fullSourcePath = (std::filesystem::path(sourceDir) / source_filename).string();

        std::string modDir = "azw_Citaro\\data\\";
        std::string fullRVMATPath = (std::filesystem::path(modDir) / output_filename).string();

        if (std::filesystem::exists(fullSourcePath))
        {
            return fullRVMATPath;
        }
        return m_defaultTextures[type];
    }
}

