#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace TamikaEngine
{

	class TE_API Log
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

//--------CORE LOGGER------------------------------------------------------------//

#define TE_CORE_ERROR(...)		::TamikaEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TE_CORE_WARN(...)		::TamikaEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TE_CORE_INFO(...)		::TamikaEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TE_CORE_TRACE(...)		::TamikaEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TE_CORE_FATAL(...)		::TamikaEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)


//--------CLIENT LOGGER----------------------------------------------------------//

#define TE_ERROR(...)	::TamikaEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define TE_WARN(...)		::TamikaEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TE_INFO(...)		::TamikaEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define TE_TRACE(...)	::TamikaEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TE_FATAL(...)	::TamikaEngine::Log::GetClientLogger()->critical(__VA_ARGS__)

