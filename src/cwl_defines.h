#ifndef _CWL_DEFINES_H_
#define _CWL_DEFINES_H_

#ifdef _WIN32 // Platform is windows
    #define CWL_PLAT_WIN
#elif linux // Platform is linux
    #define CWL_PLAT_LINUX
#endif // _WIN32

#ifdef CWL_EXPORT
    #ifdef _WIN32
        #define CWL_API __declspec(dllexport)
    #elif linux
        #define CWL_API __attribute__((visibility("default")))
    #endif // _WIN32
#else
    #ifdef _WIN32
        #define CWL_API __declspec(dllimport)
    #elif linux
        #define CWL_API
    #endif // _WIN32
#endif // CWL_EXPORT

#endif // _CWL_DEFINES_H_