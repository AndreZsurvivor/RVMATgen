#pragma once
#include <string>

namespace rvmatGen
{
    class Config
    {
    public:
        // Static setters
        static void set_mod_data_dir(const std::string& dir) { s_output_dir = dir; }
        static void set_texture_dir(const std::string& dir) { s_texture_dir = dir; }
        static void set_output_dir(const std::string& dir) { s_output_dir = dir; }
        static void set_imagetopaa_path(const std::string& path) { s_imagetopaa_path = path; }
        static void set_specular_power(float power) { s_specular_power = power; }
        static void set_specular_rgb(float rgb) { s_specular_rgb = rgb; }

        // Static getters
        static const std::string& get_mod_data_dir() { return s_output_dir; }
        static const std::string& get_texture_dir() { return s_texture_dir; }
        static const std::string& get_output_dir() { return s_output_dir; }
        static const std::string& get_imagetopaa_path() { return s_imagetopaa_path; }
        static float get_specular_power() { return s_specular_power; }
        static float get_specular_rgb() { return s_specular_rgb; }

    private:
        static std::string s_texture_dir;
        static std::string s_output_dir;
        static std::string s_imagetopaa_path;
        static float s_specular_power;
        static float s_specular_rgb;

        // Private constructor to prevent instantiation
        Config() = delete;
    };
}