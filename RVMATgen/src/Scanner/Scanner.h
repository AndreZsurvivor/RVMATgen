#pragma once
#include <string>
#include <map>
#include <iostream>
#include <regex>
#include <filesystem>

#include "Config/Config.h"

namespace rvmatGen
{
	class Scanner
	{
	public:
		Scanner();
		std::map<std::string, std::string> scan_directory_for_textures(const std::string& directory_path);

	private:

	};
}