#include "DllMain.hpp"

extern "C" uintptr_t dll_procs[32] = {};

bool DLL::Initialize()
{
    Dll_GetAddress(0, "D3DPERF_BeginEvent");
    Dll_GetAddress(1, "D3DPERF_EndEvent");
    Dll_GetAddress(2, "D3DPERF_GetStatus");
    Dll_GetAddress(3, "D3DPERF_QueryRepeatFrame");
    Dll_GetAddress(4, "D3DPERF_SetMarker");
    Dll_GetAddress(5, "D3DPERF_SetOptions");
    Dll_GetAddress(6, "D3DPERF_SetRegion");
    Dll_GetAddress(7, "DebugSetLevel");
    Dll_GetAddress(8, "DebugSetMute");
    Dll_GetAddress(9, "Direct3D9EnableMaximizedWindowedModeShim");
    Dll_GetAddress(10, "Direct3DCreate9");
    Dll_GetAddress(11, "Direct3DCreate9Ex");
    Dll_GetAddress(12, "Direct3DCreate9On12");
    Dll_GetAddress(13, "Direct3DCreate9On12Ex");
    Dll_GetAddress(14, "Direct3DShaderValidatorCreate9");
    Dll_GetAddress(15, "PSGPError");
    Dll_GetAddress(16, "PSGPSampleTexture");
    Dll_GetAddress(17, MAKEINTRESOURCEA(24));
    Dll_GetAddress(18, MAKEINTRESOURCEA(25));
    Dll_GetAddress(19, MAKEINTRESOURCEA(26));
    Dll_GetAddress(20, MAKEINTRESOURCEA(27));
    Dll_GetAddress(21, MAKEINTRESOURCEA(28));
    Dll_GetAddress(22, MAKEINTRESOURCEA(29));
    Dll_GetAddress(23, MAKEINTRESOURCEA(30));
    Dll_GetAddress(24, MAKEINTRESOURCEA(31));
    Dll_GetAddress(25, MAKEINTRESOURCEA(32));
    Dll_GetAddress(26, MAKEINTRESOURCEA(33));
    Dll_GetAddress(27, MAKEINTRESOURCEA(34));
    Dll_GetAddress(28, MAKEINTRESOURCEA(35));
    Dll_GetAddress(29, MAKEINTRESOURCEA(36));
    Dll_GetAddress(30, MAKEINTRESOURCEA(37));
    Dll_GetAddress(31, MAKEINTRESOURCEA(38));

    return true;
}
