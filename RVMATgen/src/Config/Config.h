#pragma once
#include <string>

namespace rvmatGen
{
    class Config
    {
    public:
        // Static setters
        static void set_mod_data_dir(const std::string& dir) { s_mod_data_dir = dir; }
        static void set_texture_dir(const std::string& dir) { s_source_texture_dir = dir; }
        static void set_output_dir(const std::string& dir) { s_output_dir = dir; }
        static void set_imagetopaa_path(const std::string& path) { s_imagetopaa_path = path; }

        // Static getters
        static const std::string& get_mod_data_dir() { return s_mod_data_dir; }
        static const std::string& get_texture_dir() { return s_source_texture_dir; }
        static const std::string& get_output_dir() { return s_output_dir; }
        static const std::string& get_imagetopaa_path() { return s_imagetopaa_path; }

    private:
        static std::string s_mod_data_dir;
        static std::string s_source_texture_dir;
        static std::string s_output_dir;
        static std::string s_imagetopaa_path;



        Config() = delete;
    };
}