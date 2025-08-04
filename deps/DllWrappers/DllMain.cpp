#include "DllMain.hpp"
#include <string>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace DLL
{
	HINSTANCE g_dll = 0;

	bool Startup()
	{
		TCHAR path[MAX_PATH];
		GetSystemDirectory(path, MAX_PATH);
		std::string dll_path = std::string(path) + "/" DLL_NAME ".dll";

		g_dll = LoadLibrary(dll_path.c_str());
		if (!g_dll)
		{
			spdlog::critical("[{}] Failed to load original dll at \"{}\".", DLL_NAME, dll_path);
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
				spdlog::critical("[{}] Failed to setup wrapper.", DLL_NAME);
				return FALSE;
			}

			if (!DLL::Initialize())
			{
				spdlog::critical("[{}] Failed to initialize wrapper.", DLL_NAME);
				return FALSE;
			}

			spdlog::debug("[{}] Initialized.", DLL_NAME);

			HMODULE pallink = GetModuleHandle("PalLink.dll");
			if (pallink)
			{
				spdlog::warn("[{}] PalLink.dll already loaded.", DLL_NAME);
				return TRUE;
			}

			pallink = LoadLibrary("PalLink.dll");
			if (!pallink)
			{
				spdlog::critical("[{}] Failed to load PalLink.dll.", DLL_NAME);
				return FALSE;
			}

			spdlog::debug("[{}] Loaded PalLink.dll!", DLL_NAME);

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
