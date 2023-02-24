#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

TINY_ENGINE_NAMESPACE_BEGIN

class Logger
{
public:
	static Ref<spdlog::logger> GetLogger();
private:
	Logger() = delete;
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	static Ref<spdlog::logger> m_spLogger;
};

TINY_ENGINE_NAMESPACE_END

// 
#define LOG_DEV_ERROR(...) ::TinyEngine::Logger::GetLogger()->error(__VA_ARGS__)

// 
#define LOG_DEV_WARN(...) ::TinyEngine::Logger::GetLogger()->warn(__VA_ARGS__)

// 
#define LOG_DEV_INFO(...) ::TinyEngine::Logger::GetLogger()->info(__VA_ARGS__)

// 
#define LOG_DEV_TRACE(...) ::TinyEngine::Logger::GetLogger()->trace(__VA_ARGS__)