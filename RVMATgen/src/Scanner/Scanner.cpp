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

}
