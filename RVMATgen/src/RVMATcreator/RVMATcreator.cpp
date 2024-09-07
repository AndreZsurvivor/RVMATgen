#include "RVMATcreator/RVMATcreator.h"

namespace rvmatGen
{
    std::string quoteString(const std::string& str);

    bool RVMATcreator::writeRVMATFile(const std::string& texture_set, const std::string& content, const std::string& prefix)
    {
        std::string filename;
        if (prefix.empty())
            filename = texture_set + ".rvmat";
        else
            filename = prefix + "_" + texture_set + ".rvmat";

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
        catch (const std::exception& e)
        {
            std::cout << "ERROR: writing file failed";
            return false;
        }
    }
    std::string RVMATcreator::generateRVMATContent(const rvmatGen::RVMATparameters& parameters)
    {
        const std::string& prefix = rvmatGen::Config::get_scan_prefix();
        std::stringstream rvmat_content_ss;
        rvmat_content_ss << "////FILE CREATED WITH RVMATGEN3000 v0.1 (wow you are brave, i <3 u)////\n\n#define _ARMA_\n\n"
            << "ambient[] = {" << parameters.ambientRGBA.x << "," << parameters.ambientRGBA.y << "," << parameters.ambientRGBA.z << "," << parameters.ambientRGBA.w << "};\n"
            << "diffuse[] = {" << parameters.diffuseRGBA.x << "," << parameters.diffuseRGBA.y << "," << parameters.diffuseRGBA.z << "," << parameters.diffuseRGBA.w << "};\n"
            << "forcedDiffuse[] = {" << parameters.forcedDiffuseRGBA.x << "," << parameters.forcedDiffuseRGBA.y << "," << parameters.forcedDiffuseRGBA.z << "," << parameters.forcedDiffuseRGBA.w << "};\n"
            << "emmisive[] = {" << parameters.emmisiveRGBA.x << "," << parameters.emmisiveRGBA.y << "," << parameters.emmisiveRGBA.z << "," << parameters.emmisiveRGBA.w << "};\n"
            << "specular[] = {" << parameters.specularRGBA.x << "," << parameters.specularRGBA.y << "," << parameters.specularRGBA.z << "," << parameters.specularRGBA.w << "};\n"
            << "specularPower = " << parameters.specularPower << ";\n"
            << "PixelShaderID = \"Super\";\n"
            << "VertexShaderID = \"Super\";\n";

        // Function to add a stage to the stringstream
        auto addStage = [&rvmat_content_ss](int stageNum, const std::string& texturePath, bool useWorldEnvMap = false) {
            rvmat_content_ss << "class Stage" << stageNum << "\n"
                << "{\n"
                << "    texture = \"" << texturePath << "\";\n"
                << "    uvSource = \"tex\";\n";

            if (useWorldEnvMap) {
                rvmat_content_ss << "    useWorldEnvMap = \"true\";\n";
            }

            rvmat_content_ss << "    class uvTransform\n"
                << "    {\n"
                << "        aside[] = {1,0,0};\n"
                << "        up[] = {0,1,0};\n"
                << "        dir[] = {0,0,0};\n"
                << "        pos[] = {0,0,0};\n"
                << "    };\n"
                << "};\n";
            };

        // Add stages
        addStage(1, getTexturePath(parameters.texture_set, "nohq", prefix));
        addStage(2, "#(argb,8,8,3)color(0.5,0.5,0.5,1,DT)");
        addStage(3, getTexturePath(parameters.texture_set, "co", prefix));
        addStage(4, getTexturePath(parameters.texture_set, "as", prefix));
        addStage(5, getTexturePath(parameters.texture_set, "smdi", prefix));
        const float& fres_N = parameters.fresnel.x;
        const float& fres_K = parameters.fresnel.y;
        std::stringstream fresnel_values_ss;
        fresnel_values_ss << std::fixed << std::setprecision(2) << fres_N << "," << fres_K;
        std::string fresnel_value_string = "#(ai,64,64,1)fresnel(" + fresnel_values_ss.str() + ")";
        addStage(6, fresnel_value_string);
        addStage(7, "dz\\data\\data\\env_land_co.paa", true);

        return rvmat_content_ss.str();
    }
    std::string RVMATcreator::getTexturePath(const std::string& textureSet, const std::string& type, const std::string& prefix)
    {
        std::string source_filename;
        std::string output_filename;
        if (prefix.empty())
        {
            source_filename = textureSet + "_" + type + ".png";
            output_filename = textureSet + "_" + type + ".paa";
        }
        else
        {
            source_filename = prefix + "_" + textureSet + "_" + type + ".png";
            output_filename = prefix + "_" + textureSet + "_" + type + ".paa";
        }

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

