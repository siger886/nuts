#pragma once

#include "core.h"
#include"spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
namespace nuts {
	class NUTS_API Log
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
//Core log macros
#define NT_CORE_TRACE(...)		::nuts::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NT_CORE_INFO(...)			::nuts::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NT_CORE_WARN(...)		::nuts::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NT_CORE_ERROR(...)		::nuts::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NT_CORE_FATAL(...)		::nuts::Log::GetCoreLogger()->fatal(__VA_ARGS__)


//Client log macros
#define NT_TRACE(...)					::nuts::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NT_INFO(...)					::nuts::Log::GetClientLogger()->info(__VA_ARGS__)
#define NT_WARN(...)					::nuts::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NT_ERROR(...)					::nuts::Log::GetClientLogger()->error(__VA_ARGS__)
#define NT_FATAL(...)	                ::nuts::Log::GetClientLogger()->fatal(__VA_ARGS__)