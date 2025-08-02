#include "PalLink.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <Windows.h>

/* Just quick test, the logger setup is just temporary. */
#define FOREGROUND_WHITE  (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
#define FOREGROUND_YELLOW (FOREGROUND_RED | FOREGROUND_GREEN)
#define FOREGROUND_CYAN   (FOREGROUND_GREEN | FOREGROUND_BLUE)
void SetupLogger()
{
	auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	stdout_sink->set_color(spdlog::level::trace, FOREGROUND_CYAN | FOREGROUND_INTENSITY);
	stdout_sink->set_color(spdlog::level::debug, FOREGROUND_CYAN);
	stdout_sink->set_color(spdlog::level::info, FOREGROUND_GREEN);
	stdout_sink->set_color(spdlog::level::warn, FOREGROUND_YELLOW | FOREGROUND_INTENSITY);
	stdout_sink->set_color(spdlog::level::err, FOREGROUND_RED | FOREGROUND_INTENSITY);
	stdout_sink->set_color(spdlog::level::critical, FOREGROUND_WHITE | BACKGROUND_RED | FOREGROUND_INTENSITY);
	stdout_sink->set_pattern("[%T][%^%l%$] %v");

#ifdef _DEBUG
	stdout_sink->set_level(spdlog::level::trace);
#else
	stdout_sink->set_level(spdlog::level::info);
#endif

	auto logger = std::make_shared<spdlog::logger>("PalLink", stdout_sink);

#ifdef _DEBUG
	logger->set_level(spdlog::level::trace);
	spdlog::flush_on(spdlog::level::trace);
#else
	logger->set_level(spdlog::level::info);
	spdlog::flush_on(spdlog::level::info);
#endif
	spdlog::set_default_logger(logger);
}
#undef FOREGROUND_WHITE
#undef FOREGROUND_YELLOW
#undef FOREGROUND_CYAN

static DWORD WINAPI main_thread(LPVOID lpParameter)
{
	HMODULE module = static_cast<HMODULE>(lpParameter);

	SetupLogger();

	spdlog::info(L"Hello World!");

	return ERROR_SUCCESS;
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
	{
		DisableThreadLibraryCalls(module);

		HANDLE thread = CreateThread(0, 0, main_thread, static_cast<LPVOID>(module), 0, 0);
		if (thread)
		{
			CloseHandle(thread);
			return TRUE;
		}

		return FALSE;
	}
	case DLL_PROCESS_DETACH:
	{
		return TRUE;
	}
	}

	return TRUE;
}