#pragma once

namespace rds
{
	enum class BufferMask
	{
		COLOR_BUFFER		= 0,
		DEPTH_BUFFER		= 1 << 0,
		STENCIL_BUFFER		= 1 << 1
	};
}