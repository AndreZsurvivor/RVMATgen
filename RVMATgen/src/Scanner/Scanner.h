#pragma once
#include <algorithm>
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
		std::vector<std::string> scan_texkeys_for_texsets(std::vector<std::string>& texture_keys);

	private:

	};
}