#include "PalLink.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <polyhook2/IHook.hpp>
#include <polyhook2/Detour/NatDetour.hpp>

#include <crow.h>

#include <rapidjson/document.h>     // rapidjson's DOM-style API
#include <rapidjson/prettywriter.h> // for stringify JSON
#include <rapidjson/error/en.h>

namespace
{
	static std::thread g_restapi_thread;
	static crow::SimpleApp g_restapi_app;
	static PLH::NatDetour* g_hook = nullptr;
}

#include <thread>
#include <cstdarg>
#include <cstdio>

uint64_t hookPrintfTramp = 0;
NOINLINE int __cdecl h_hookPrintf(const char* format, ...) {
	char buffer[1024];
	va_list args;
	va_start(args, format);
	int bytes_written = vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	// Strip trailing newline if present
	if (bytes_written > 0 && buffer[bytes_written - 1] == '\n')
	{
		buffer[--bytes_written] = '\0';
	}

    spdlog::info("{}", buffer);

	return bytes_written; //PLH::FnCast(hookPrintfTramp, &printf)("INTERCEPTED YO:%s", buffer);
}

inline void test_restapi()
{

	CROW_ROUTE(g_restapi_app, "/")([]() {
		return "Hello Palworld";
		});

	g_restapi_app.port(17993).multithreaded().run();
}

void startup()
{
	spdlog::info("PalLink loaded!");

	g_hook = new PLH::NatDetour((uint64_t)&printf, (uint64_t)h_hookPrintf, &hookPrintfTramp);
	g_hook->hook();

	printf("%s %s %f\n", "hello", "Palworld!", 0.5f);

	g_restapi_thread = std::thread(test_restapi);

	const char json_data[] = "{ \"japanese\": \"こんにちは\", \"chinese\" : \"你好\", \"russian\" : \"Привет\", \"english\" : \"Hello\" }";
	rapidjson::Document doc;

	if (doc.Parse(json_data).HasParseError())
	{
		spdlog::error("[JSON] parse error: {}", rapidjson::GetParseError_En(doc.GetParseError()));
		spdlog::error("[JSON]          at: {}", doc.GetErrorOffset());
	}
	else
	{
		if (doc.HasMember("japanese") && doc["japanese"].IsString())
		{
			spdlog::info("[JSON] Japanese: {}", doc["japanese"].GetString());
		}

		if (doc.HasMember("chinese") && doc["chinese"].IsString())
		{
			spdlog::info("[JSON] Chinese: {}", doc["chinese"].GetString());
		}

		if (doc.HasMember("russian") && doc["russian"].IsString())
		{
			spdlog::info("[JSON] Russian: {}", doc["russian"].GetString());
		}

		if (doc.HasMember("english") && doc["english"].IsString())
		{
			spdlog::info("[JSON] English: {}", doc["english"].GetString());
		}
	}
}

void shutdown()
{
	spdlog::info("Stopping RESTAPI!");
	g_restapi_app.stop();
	g_restapi_thread.join();
	g_hook->unHook();
	spdlog::info("RESTAPI stopped!");
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
				SetConsoleOutputCP(CP_UTF8);
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
