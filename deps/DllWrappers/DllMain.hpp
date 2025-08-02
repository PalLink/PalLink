#pragma once

#include <Windows.h>
#include <cstdint>

namespace DLL
{
	bool Initialize();
	bool Startup();
	bool Shutdown();
	bool GetProcAddress(uintptr_t& out_address, LPCSTR lpProcName);
}

#define Dll_GetAddress(i, x) if (!DLL::GetProcAddress(dll_procs[i], x)) return false
