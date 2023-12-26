#pragma once

#if defined(_DEBUG) && !defined(RDS_DEBUG)
	#define RDS_DEBUG
#elif defined(NDEBUG) && !defined(RDS_RELEASE)
	#define RDS_RELEASE
#endif

#ifdef _WIN32
	#define RDS_BREAKPOINT() __debugbreak()
#elif defined(__linux__)
	#define RDS_PLATFORM_LINUX
	#define RDS_BREAKPOINT() __builtin_trap()
#elif defined(__APPLE__)
	#define RDS_PLATFORM_APPLE
	#define RDS_BREAKPOINT() __builtin_trap()
#elif defined(__ANDROID__)
	#define RDS_PLATFORM_ANDROID
	#define RDS_BREAKPOINT() __builtin_trap()
#else
	#error Unsupported platform
#endif