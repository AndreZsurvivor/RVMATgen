#include "RVMATcreator/RVMATcreator.h"
namespace rvmatGen
{
    std::string quoteString(const std::string& str);

    bool RVMATcreator::writeRVMATFile(const std::string& texture_set, const std::string& content)
    {
        
        std::string filename = "azw_" + texture_set + ".rvmat";
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
    std::string RVMATcreator::generateRVMATContent(const rvmatGen::RVMATparameters& parameters)
    {
        std::stringstream ss;
        ss << "ambient[] = {" << parameters.ambientRGBA.x << "," << parameters.ambientRGBA.y << "," << parameters.ambientRGBA.z << "," << parameters.ambientRGBA.w << "};\n"
            << "diffuse[] = {" << parameters.diffuseRGBA.x << "," << parameters.diffuseRGBA.y << "," << parameters.diffuseRGBA.z << "," << parameters.diffuseRGBA.w << "};\n"
            << "forcedDiffuse[] = {" << parameters.forcedDiffuseRGBA.x << "," << parameters.forcedDiffuseRGBA.y << "," << parameters.forcedDiffuseRGBA.z << "," << parameters.forcedDiffuseRGBA.w << "};\n"
            << "emmisive[] = {" << parameters.emmisiveRGBA.x << "," << parameters.emmisiveRGBA.y << "," << parameters.emmisiveRGBA.z << "," << parameters.emmisiveRGBA.w << "};\n"
            << "specular[] = {" << parameters.specularRGBA.x << "," << parameters.specularRGBA.y << "," << parameters.specularRGBA.z << "," << parameters.specularRGBA.w << "};\n"
            << "specularPower = " << parameters.specularPower << ";\n"
            << "PixelShaderID = \"Super\";\n"
            << "VertexShaderID = \"Super\";\n"
            << "class Stage1\n"
            << "{\n"
            << "    texture = \"" << getTexturePath(parameters.texture_set, "nohq") << "\";\n"
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
    std::string RVMATcreator::getTexturePath(const std::string& textureSet, const std::string& type)
    {
        const std::string& source_filename = "azw_" + textureSet + "_" + type + ".png";
        const std::string& output_filename = "azw_" + textureSet + "_" + type + ".paa";


        const std::string& sourceDir = rvmatGen::Config::get_texture_dir();
        const std::string& fullSourcePath = (std::filesystem::path(sourceDir) / source_filename).string();

        const std::string& modDir = rvmatGen::Config::get_mod_data_dir();
        const std::string& fullRVMATPath = (std::filesystem::path(modDir) / output_filename).string();

        if (std::filesystem::exists(fullSourcePath))
        {
            return fullRVMATPath;
        }
        return m_defaultTextures[type];
    }
}

