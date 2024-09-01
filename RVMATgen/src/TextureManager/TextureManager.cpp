#include "TextureManager/TextureManager.h"
namespace rvmatGen
{

    void TextureManager::scan_and_update(const std::string& directory_path) {
        auto scanned_textures = m_scanner.scan_directory_for_textures(directory_path);
        update_textures(scanned_textures);
    }

    void TextureManager::update_textures(const std::map<std::string, std::string>& new_textures)
    {
        m_texture_files = new_textures;

        std::cout << "TextureManager::update_textures - Updated with " << new_textures.size() << " textures" << std::endl;

        // Optional: Print out all textures for debugging
        for (const auto& [key, path] : m_texture_files)
        {
            std::cout << "Texture: " << key << " -> " << path << std::endl;
        }
    }

    void TextureManager::set_texture_files(const std::map<std::string, std::string>& files)
    {
        m_texture_files = files;
    }

    void TextureManager::add_texture_file(const std::string& key, const std::string& path)
    {
        m_texture_files[key] = path;
    }

    const std::map<std::string, std::string>& TextureManager::get_texture_files() const
    {
        return m_texture_files;
    }

    std::string TextureManager::get_texture_path(const std::string& key) const
    {
        auto it = m_texture_files.find(key);
        if (it != m_texture_files.end())
        {
            return it->second;
        }
        return "";
    }

    bool TextureManager::texture_exists(const std::string& key) const
    {
        return m_texture_files.find(key) != m_texture_files.end();
    }

    std::vector<std::string> TextureManager::get_texture_keys() const
    {
        std::vector<std::string> keys;
        keys.reserve(m_texture_files.size());
        for (const auto& pair : m_texture_files)
        {
            keys.push_back(pair.first);
        }
        return keys;
    }

    void TextureManager::clear_texture_files()
    {
        m_texture_files.clear();
    }

    size_t TextureManager::get_texture_count() const
    {
        return m_texture_files.size();
    }
}