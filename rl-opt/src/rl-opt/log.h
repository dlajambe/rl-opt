#pragma once
#include <memory>
#include <string>

#include "spdlog/spdlog.h"

namespace rl_opt
{
	class Log
	{
	public:
		static std::shared_ptr<spdlog::logger> MakeLogger(const std::string filename);
		static inline std::shared_ptr<spdlog::logger>& GetCoreLogger() { return core_logger; };
		static inline std::shared_ptr<spdlog::logger>& GetClientLogger() { return client_logger; };

	private:
		static inline std::shared_ptr<spdlog::logger> core_logger = MakeLogger("rl_opt.txt");
		static inline std::shared_ptr<spdlog::logger> client_logger = MakeLogger("app.txt");
	};
}

// Core logging macros
#define RL_OPT_CORE_TRACE(...)    ::rl_opt::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RL_OPT_CORE_INFO(...)     ::rl_opt::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RL_OPT_CORE_WARN(...)     ::rl_opt::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RL_OPT_CORE_ERROR(...)    ::rl_opt::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RL_OPT_CORE_CRITICAL(...) ::rl_opt::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define RL_OPT_CORE_DEBUG(...)    ::rl_opt::Log::GetCoreLogger()->debug(__VA_ARGS__)

// Client application logging macros
#define RL_OPT_CLIENT_TRACE(...)    ::rl_opt::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RL_OPT_CLIENT_INFO(...)     ::rl_opt::Log::GetClientLogger()->info(__VA_ARGS__)
#define RL_OPT_CLIENT_WARN(...)     ::rl_opt::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RL_OPT_CLIENT_ERROR(...)    ::rl_opt::Log::GetClientLogger()->error(__VA_ARGS__)
#define RL_OPT_CLIENT_CRITICAL(...) ::rl_opt::Log::GetClientLogger()->critical(__VA_ARGS__)
#define RL_OPT_CLIENT_DEBUG(...)    ::rl_opt::Log::GetClientLogger()->debug(__VA_ARGS__)