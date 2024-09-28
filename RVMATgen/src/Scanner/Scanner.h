#pragma once
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#include <regex>
#include <filesystem>

#include "Config/Config.h"
#include "structs.h"
#include "constants.h"

namespace rvmatGen
{
	class Scanner
	{
	public:
		Scanner();
		std::map<std::string, std::string> scan_directory_for_textures(const std::string& directory_path);
		std::vector<std::string> scan_texkeys_for_texsets(std::vector<std::string>& texture_keys);

		ScanningPattern GetScanningPattern() { return m_scanningPattern; }
		bool SetScanningPattern(ScanningPattern scanningPattern) { m_scanningPattern = scanningPattern; return true; }

	private:
		ScanningPattern m_scanningPattern = rvmatGen::patterns[0];

	};
}