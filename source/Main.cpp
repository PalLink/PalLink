#include "PalLink.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

void startup()
{
	spdlog::trace("PalLink loaded!");
	spdlog::debug("PalLink loaded!");
	spdlog::info("PalLink loaded!");
	spdlog::warn("PalLink loaded!");
	spdlog::error("PalLink loaded!");
	spdlog::critical("PalLink loaded!");
}

void shutdown()
{
	spdlog::info("PalLink unloaded!");
}

#ifdef _WIN32
	#include <Windows.h>

	BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID)
	{
		switch (reason)
		{
			case DLL_PROCESS_ATTACH:
			{
				DisableThreadLibraryCalls(module);
				startup();
				return TRUE;
			}
			case DLL_PROCESS_DETACH:
			{
				shutdown();
				return TRUE;
			}
		}

		return TRUE;
	}

#elif defined(__linux__)
	__attribute__((constructor))
	void on_load()
	{
		startup();
	}

	__attribute__((destructor))
	void on_unload()
	{
		shutdown();
	}
#endif