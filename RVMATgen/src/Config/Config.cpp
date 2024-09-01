#include "Config/Config.h"

namespace rvmatGen
{
    // Initialize static members
    std::string Config::s_mod_data_dir;
    std::string Config::s_texture_dir;
    std::string Config::s_output_dir;
    std::string Config::s_imagetopaa_path;
    float Config::s_specular_power = 50.0f;  // Default value
    float Config::s_specular_rgb = 0.1f;     // Default value
}