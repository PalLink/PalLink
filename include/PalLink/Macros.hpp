#pragma once

// Platform detection
#if defined(_WIN32)
    #define PALLINK_WINDOWS
#elif defined(__linux__)
    #define PALLINK_LINUX
#endif

// Export macro
#if defined(PALLINK_WINDOWS)
    #ifdef PALLINK_BUILD_DLL
        #define PALLINK_API __declspec(dllexport)
    #else
        #define PALLINK_API __declspec(dllimport)
    #endif
#else
    #define PALLINK_API __attribute__((visibility("default")))
#endif
