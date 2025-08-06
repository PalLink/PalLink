#include "PalLink.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <polyhook2/IHook.hpp>
#include <polyhook2/Detour/NatDetour.hpp>

#include <crow.h>

namespace
{
	static PLH::NatDetour* g_hook = nullptr;
}

#include <cstdarg>
#include <cstdio>

uint64_t hookPrintfTramp = NULL;
NOINLINE int __cdecl h_hookPrintf(const char* format, ...) {
	char buffer[1024];
	va_list args;
	va_start(args, format);
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	return PLH::FnCast(hookPrintfTramp, &printf)("INTERCEPTED YO:%s", buffer);
}

DWORD WINAPI test(LPVOID lpThreadParameter)
{
	crow::SimpleApp app;

	CROW_ROUTE(app, "/")([]() {
		return "Hello world";
		});

	app.port(17993).multithreaded().run();
	return 0;
}

void startup()
{
	spdlog::info("PalLink loaded!");

	g_hook = new PLH::NatDetour((uint64_t)&printf, (uint64_t)h_hookPrintf, &hookPrintfTramp);
	g_hook->hook();

	printf("%s %s %f\n", "hello", "world!", 0.5f);
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
				CreateThread(NULL, NULL, test, nullptr, NULL, NULL);
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