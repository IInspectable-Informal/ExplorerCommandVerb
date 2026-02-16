#include "pch.h"
#include "dllmain.h"

HMODULE g_DllHandle = nullptr;
wchar_t g_DllPath[MAX_PATH];

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        g_DllHandle = hModule;
        GetModuleFileNameW(hModule, g_DllPath, MAX_PATH);
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

LPCWSTR GetDllPath()
{
    return g_DllPath;
}

uint64_t g_DllRefCount = 0;

void DllAddRef()
{
    InterlockedIncrement(&g_DllRefCount);
}

void DllRelease()
{
    InterlockedDecrement(&g_DllRefCount);
}

STDAPI DllCanUnloadNow()
{
    //h_DllRefCount is not 0 : DLL cannot be released
    //g_DllRefCount is 0 : DLL can be released
    return g_DllRefCount != 0 ? S_FALSE : S_OK;
}
