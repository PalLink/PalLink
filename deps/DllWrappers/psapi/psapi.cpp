#include "DllMain.hpp"

extern "C" uintptr_t dll_procs[27] = {};

bool DLL::Initialize()
{
    Dll_GetAddress(0, "EmptyWorkingSet");
    Dll_GetAddress(1, "EnumDeviceDrivers");
    Dll_GetAddress(2, "EnumPageFilesA");
    Dll_GetAddress(3, "EnumPageFilesW");
    Dll_GetAddress(4, "EnumProcessModules");
    Dll_GetAddress(5, "EnumProcessModulesEx");
    Dll_GetAddress(6, "EnumProcesses");
    Dll_GetAddress(7, "GetDeviceDriverBaseNameA");
    Dll_GetAddress(8, "GetDeviceDriverBaseNameW");
    Dll_GetAddress(9, "GetDeviceDriverFileNameA");
    Dll_GetAddress(10, "GetDeviceDriverFileNameW");
    Dll_GetAddress(11, "GetMappedFileNameA");
    Dll_GetAddress(12, "GetMappedFileNameW");
    Dll_GetAddress(13, "GetModuleBaseNameA");
    Dll_GetAddress(14, "GetModuleBaseNameW");
    Dll_GetAddress(15, "GetModuleFileNameExA");
    Dll_GetAddress(16, "GetModuleFileNameExW");
    Dll_GetAddress(17, "GetModuleInformation");
    Dll_GetAddress(18, "GetPerformanceInfo");
    Dll_GetAddress(19, "GetProcessImageFileNameA");
    Dll_GetAddress(20, "GetProcessImageFileNameW");
    Dll_GetAddress(21, "GetProcessMemoryInfo");
    Dll_GetAddress(22, "GetWsChanges");
    Dll_GetAddress(23, "GetWsChangesEx");
    Dll_GetAddress(24, "InitializeProcessForWsWatch");
    Dll_GetAddress(25, "QueryWorkingSet");
    Dll_GetAddress(26, "QueryWorkingSetEx");

    return true;
}
