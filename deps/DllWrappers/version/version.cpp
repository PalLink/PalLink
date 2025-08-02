#include "DllMain.hpp"

extern "C" uintptr_t dll_procs[17] = {};

bool DLL::Initialize()
{
    Dll_GetAddress(0, "GetFileVersionInfoA");
    Dll_GetAddress(1, "GetFileVersionInfoByHandle");
    Dll_GetAddress(2, "GetFileVersionInfoExA");
    Dll_GetAddress(3, "GetFileVersionInfoExW");
    Dll_GetAddress(4, "GetFileVersionInfoSizeA");
    Dll_GetAddress(5, "GetFileVersionInfoSizeExA");
    Dll_GetAddress(6, "GetFileVersionInfoSizeExW");
    Dll_GetAddress(7, "GetFileVersionInfoSizeW");
    Dll_GetAddress(8, "GetFileVersionInfoW");
    Dll_GetAddress(9, "VerFindFileA");
    Dll_GetAddress(10, "VerFindFileW");
    Dll_GetAddress(11, "VerInstallFileA");
    Dll_GetAddress(12, "VerInstallFileW");
    Dll_GetAddress(13, "VerLanguageNameA");
    Dll_GetAddress(14, "VerLanguageNameW");
    Dll_GetAddress(15, "VerQueryValueA");
    Dll_GetAddress(16, "VerQueryValueW");

    return true;
}
