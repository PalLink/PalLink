#include "DllMain.hpp"

extern "C" uintptr_t dll_procs[12] = {};

bool DLL::Initialize()
{
	Dll_GetAddress(0, "DllMain");
	Dll_GetAddress(1, "XInputEnable");
	Dll_GetAddress(2, "XInputGetBatteryInformation");
	Dll_GetAddress(3, "XInputGetCapabilities");
	Dll_GetAddress(4, "XInputGetDSoundAudioDeviceGuids");
	Dll_GetAddress(5, "XInputGetKeystroke");
	Dll_GetAddress(6, "XInputGetState");
	Dll_GetAddress(7, "XInputSetState");
	Dll_GetAddress(8, MAKEINTRESOURCEA(100));
	Dll_GetAddress(9, MAKEINTRESOURCEA(101));
	Dll_GetAddress(10, MAKEINTRESOURCEA(102));
	Dll_GetAddress(11, MAKEINTRESOURCEA(103));
	return true;
}
