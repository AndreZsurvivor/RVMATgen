#pragma once
#include <map>
#include <string>
#include <vector>

#include "Scanner/Scanner.h"

namespace rvmatGen
{
    class TextureManager
    {

    public:
        TextureManager() : m_scanner() {}

        TextureManager getTextureManager() { return *this; }

        void scan_and_update(const std::string& path);

        // Set all texture files
        void set_texture_files(const std::map<std::string, std::string>& files);

        // Add a single texture file
        void add_texture_file(const std::string& key, const std::string& path);

        // Get all texture files
        const std::map<std::string, std::string>& get_texture_files() const;

        // Get a specific texture file path
        std::string get_texture_path(const std::string& key) const;

        // Check if a texture exists
        bool texture_exists(const std::string& key) const;

        // Get all texture keys
        std::vector<std::string> get_texture_keys() const;

        // Get all texture sets
        std::vector<std::string> get_texture_sets() const;

        // Clear all texture files
        void clear_texture_files();

        // Get count of texture files
        size_t get_texture_count() const;

    private:
        Scanner m_scanner;
        std::map<std::string, std::string> m_texture_files;
        std::vector<std::string> m_texture_sets;
    };
}