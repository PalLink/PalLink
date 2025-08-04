#include "DllMain.hpp"
#include <string>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace DLL
{
	HINSTANCE g_dll = 0;

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
		stdout_sink->set_pattern("[%T][%n][%^%l%$] %v");

#ifdef _DEBUG
		stdout_sink->set_level(spdlog::level::trace);
#else
		stdout_sink->set_level(spdlog::level::info);
#endif

		auto logger = std::make_shared<spdlog::logger>(DLL_NAME, stdout_sink);

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

	bool Startup()
	{
		SetupLogger();

		TCHAR path[MAX_PATH];
		GetSystemDirectory(path, MAX_PATH);
		std::string dll_path = std::string(path) + "/" DLL_NAME ".dll";

		g_dll = LoadLibrary(dll_path.c_str());
		if (!g_dll)
		{
			spdlog::critical("Failed to load original dll at \"{}\".", dll_path);
			return false;
		}

		return true;
	}



	bool Shutdown()
	{
		return FreeLibrary(g_dll) == TRUE;
	}



	bool GetProcAddress(uintptr_t& out_address, LPCSTR lpProcName)
	{
		out_address = (uintptr_t)GetProcAddress(g_dll, lpProcName);
		return out_address != 0;
	}
}



BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			if (!DLL::Startup())
			{
				spdlog::critical("Failed to setup wrapper.", DLL_NAME);
				return FALSE;
			}

			if (!DLL::Initialize())
			{
				spdlog::critical("Failed to initialize wrapper.", DLL_NAME);
				return FALSE;
			}

			spdlog::debug("Initialized.");

			HMODULE pallink = GetModuleHandle("PalLink.dll");
			if (pallink)
			{
				spdlog::warn("PalLink.dll already loaded.", DLL_NAME);
				return TRUE;
			}

			pallink = LoadLibrary("PalLink.dll");
			if (!pallink)
			{
				spdlog::critical("Failed to load PalLink.dll.", DLL_NAME);
				return FALSE;
			}

			spdlog::debug("Loaded PalLink.dll!");

			return TRUE;
		}
		case DLL_PROCESS_DETACH:
		{
			DLL::Shutdown();
			return TRUE;
		}
	}

	return TRUE;
}
