#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Cylinder {
	
	class CYLINDER_API Log
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

//Core Log Macros
#define CYL_CORE_TRACE(...)     ::Cylinder::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CYL_CORE_INFO(...)      ::Cylinder::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CYL_CORE_WARN(...)      ::Cylinder::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CYL_CORE_ERROR(...)     ::Cylinder::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CYL_CORE_FATAL(...)     ::Cylinder::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define CYL_TRACE(...)          ::Cylinder::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CYL_INFO(...)           ::Cylinder::Log::GetClientLogger()->info(__VA_ARGS__)
#define CYL_WARN(...)           ::Cylinder::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CYL_ERROR(...)          ::Cylinder::Log::GetClientLogger()->error(__VA_ARGS__)
#define CYL_FATAL(...)          ::Cylinder::Log::GetClientLogger()->fatal(__VA_ARGS__)