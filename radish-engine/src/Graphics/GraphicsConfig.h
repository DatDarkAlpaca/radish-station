#pragma once
#include <numeric>

namespace rds
{
	struct GraphicsConfig
	{
		uint32_t apiVersionMajor;
		uint32_t apiVersionMinor;

		uint32_t enableDoubleBuffering = 1;
		uint16_t depthBits = 24;
		uint16_t stencilBits = 8;
	};
}