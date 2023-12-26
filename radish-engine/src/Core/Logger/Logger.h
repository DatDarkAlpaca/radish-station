#pragma once
#include "Core/Defines.h"
#include "Core/NonCopyable.h"

#pragma warning(push, 0)
	#include <spdlog/spdlog.h>
	#include <spdlog/sinks/stdout_color_sinks.h>
	#include <spdlog/sinks/basic_file_sink.h>
#pragma warning(pop)

namespace rds
{
	class LoggerSystem : public Singleton<LoggerSystem>
	{
	public:
		void Initialize();

	public:
		inline rds_shared<spdlog::logger>& GetLogger() { return m_Logger; }
		inline rds_shared<spdlog::logger>& GetInfoLogger() { return m_InfoLogger; }

	private:
		rds_shared<spdlog::logger> m_Logger;
		rds_shared<spdlog::logger> m_InfoLogger;
	};
}

#ifdef RDS_DEBUG
	#define RDS_LOG_CRITICAL(...)	{ ::rds::LoggerSystem::Get().GetLogger()->critical(__VA_ARGS__); RDS_BREAKPOINT(); }
	#define RDS_LOG_ERROR(...)		::rds::LoggerSystem::Get().GetLogger()->error(__VA_ARGS__)
	#define RDS_LOG_WARN(...)		::rds::LoggerSystem::Get().GetLogger()->warn(__VA_ARGS__)
	#define RDS_LOG_TRACE(...)		::rds::LoggerSystem::Get().GetInfoLogger()->trace(__VA_ARGS__)
	#define RDS_LOG_DEBUG(...)		::rds::LoggerSystem::Get().GetLogger()->debug(__VA_ARGS__)
	#define RDS_LOG_INFO(...)		::rds::LoggerSystem::Get().GetInfoLogger()->info(__VA_ARGS__)

#else
	#define RDS_LOG_CRITICAL(...)	{ ::rds::LoggerSystem::Get().GetLogger()->critical(__VA_ARGS__); RDS_BREAKPOINT(); }
	#define RDS_LOG_ERROR(...)		::rds::LoggerSystem::Get().GetLogger()->error(__VA_ARGS__)
	#define RDS_LOG_WARN(...)		{ }
	#define RDS_LOG_DEBUG(...)		{ }
	#define RDS_LOG_TRACE(...)		{ }
	#define RDS_LOG_INFO(...)		{ }
#endif