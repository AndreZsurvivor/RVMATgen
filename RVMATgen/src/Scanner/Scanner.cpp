#include "Scanner.h"

namespace rvmatGen
{
    Scanner::Scanner()
    {
    }


    std::map<std::string, std::string> Scanner::scan_directory_for_textures(const std::string& directory_path)
    {
        std::map<std::string, std::string> texture_files;
        std::regex udim_pattern(R"(azw_(\w+)(\d{4})_(co|nohq|smdi|as)\.(png|paa))");

        for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
            if (entry.is_regular_file()) {
                std::string filename = entry.path().filename().string();
                std::smatch match;

                if (std::regex_match(filename, match, udim_pattern)) {
                    std::string texture_set = match[1];
                    std::string udim = match[2];
                    std::string texture_type = match[3];
                    std::string file_ext = match[4];

                    std::string key = texture_set + udim + "_" + texture_type;
                    std::string file_path = entry.path().string();

                    texture_files[key] = file_path;

                    std::cout << "Processed texture: " << filename
                        << " for key: " << key << std::endl;
                }
            }
        }

        return texture_files;
    }

    std::vector<std::string> Scanner::scan_texkeys_for_texsets(std::vector<std::string>& texture_keys)
    {
        std::vector<std::string> texture_sets;
        std::regex texset_pattern(R"((\w+)(\d{4})_(co|nohq|smdi|as))");
        
        for (const auto& key : texture_keys)
        {
            std::smatch match;

            if (std::regex_match(key, match, texset_pattern)) {
                std::string texture_set = match[1];
                std::string udim = match[2];
                std::string texture_type = match[3];


                std::string newTexSet = texture_set + udim;
                int count = std::count(texture_sets.begin(), texture_sets.end(), newTexSet);
                if (!count)
                    texture_sets.push_back(newTexSet);


            }
        }

        return texture_sets;
    }



}
