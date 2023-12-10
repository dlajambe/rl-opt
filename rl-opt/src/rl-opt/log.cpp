#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/daily_file_sink.h"

namespace rl_opt
{
	std::shared_ptr<spdlog::logger> Log::MakeLogger(const std::string filename)
	{
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_level(spdlog::level::trace);
        console_sink->set_pattern("[%H:%M:%S][%^%l%$] %v");
        // console_sink->set_pattern("%^[%H:%M:%S]%$ %v");

        auto file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>("logs/" + filename, 0, 0);
        file_sink->set_level(spdlog::level::trace);
        file_sink->set_pattern("[%Y-%m-%d][%H:%M:%S][%L] %v");

        spdlog::logger new_logger("multi_sink", { console_sink, file_sink });
        new_logger.set_level(spdlog::level::trace);

        return std::make_shared<spdlog::logger>(new_logger);
	}
}