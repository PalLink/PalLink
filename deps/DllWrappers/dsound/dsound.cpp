#include "DllMain.hpp"

extern "C" uintptr_t dll_procs[12] = {};

bool DLL::Initialize()
{
	Dll_GetAddress(0, "DirectSoundCreate");
	Dll_GetAddress(1, "DirectSoundCreate8");
	Dll_GetAddress(2, "DirectSoundEnumerateA");
	Dll_GetAddress(3, "DirectSoundEnumerateW");
	Dll_GetAddress(4, "DirectSoundFullDuplexCreate");
	Dll_GetAddress(5, "DllCanUnloadNow");
	Dll_GetAddress(6, "DllGetClassObject");
	Dll_GetAddress(7, "GetDeviceID");
	Dll_GetAddress(8, "DirectSoundCaptureCreate");
	Dll_GetAddress(9, "DirectSoundCaptureCreate8");
	Dll_GetAddress(10, "DirectSoundCaptureEnumerateA");
	Dll_GetAddress(11, "DirectSoundCaptureEnumerateW");
	return true;
}
