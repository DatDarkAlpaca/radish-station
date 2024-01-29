#pragma once
#include <sstream>
#include <fstream>
#include <string>

namespace rds
{
	inline std::string ReadFile(const std::string& filepath)
	{
		std::ifstream file(filepath);

		std::stringstream ss;
		ss << file.rdbuf();

		return ss.str();
	}
}