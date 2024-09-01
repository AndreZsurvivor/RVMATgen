// Utilities.cpp
#include "RVMATgen.h"

namespace rvmatGen
{
    bool pathIsValid(const std::string& path)
    {
        std::filesystem::path fsPath(path);
        return std::filesystem::exists(fsPath) && std::filesystem::is_directory(fsPath);
    }
    
}