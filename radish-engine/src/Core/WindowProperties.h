#pragma once
#include <glm/glm.hpp>
#include <string>

#include "Common.h"

namespace rds
{
	struct WindowProperties
	{
		glm::vec2 dimensions;
		std::string title;
		glm::vec2 position = { InvalidValue, InvalidValue };
	};
}