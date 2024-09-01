// Utilities.cpp
#include "RVMATgen.h"

namespace rvmatGen
{
    bool pathIsValid(const std::string& path)
    {
        std::filesystem::path fsPath(path);
        return std::filesystem::exists(fsPath) && std::filesystem::is_directory(fsPath);
    }
    bool isValidImagetopaaExe(const std::string& path)
    {
        std::filesystem::path fsPath(path);
        return std::filesystem::exists(fsPath) &&
            std::filesystem::is_regular_file(fsPath) &&
            fsPath.filename() == "ImageToPAA.exe";
    }
    std::string quoteString(const std::string& str) {
        if (str.find(' ') != std::string::npos) {
            return "\"" + str + "\"";
        }
        return str;
    }
    
    std::vector<const char*> findAndCopyStrings(const std::vector<std::string>& input, const std::string& token)
    {
        std::vector<const char*> result;

        for (const auto& str : input) {
            if (str.find(token) != std::string::npos) {
                result.push_back(str.c_str());
            }
        }

        return result;
    }

    int runImageToPAA(const std::string& exePath, const std::string& source, const std::string& destination, int size)
    {
        std::ostringstream command;
        command << rvmatGen::quoteString(exePath) << " ";

        if (size > 0) {
            command << "-size=" << size << " ";
        }

        command << rvmatGen::quoteString(source);

        if (!destination.empty()) {
            command << " " << rvmatGen::quoteString(destination);
        }

        std::cout << "Executing command: " << command.str() << std::endl;
        return std::system(command.str().c_str());
    }
}