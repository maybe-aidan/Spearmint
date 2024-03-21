#ifndef LOG_H
#define LOG_H

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Spearmint {
	class SPEARMINT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core Log Macros

#define SM_CORE_FATAL(...)     ::Spearmint::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define SM_CORE_ERROR(...)     ::Spearmint::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SM_CORE_WARN(...)      ::Spearmint::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SM_CORE_INFO(...)      ::Spearmint::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SM_CORE_TRACE(...)     ::Spearmint::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client Log Macros

#define SM_FATAL(...)          ::Spearmint::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define SM_ERROR(...)          ::Spearmint::Log::GetClientLogger()->error(__VA_ARGS__)
#define SM_WARN(...)           ::Spearmint::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SM_INFO(...)           ::Spearmint::Log::GetClientLogger()->info(__VA_ARGS__)
#define SM_TRACE(...)          ::Spearmint::Log::GetClientLogger()->trace(__VA_ARGS__)


#endif // LOG_H
