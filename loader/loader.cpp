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
string replaceAll(string subject, const string& search,
    const string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}
string DownloadString(string URL) {
    HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
    HINTERNET urlFile;
    string rtn;
    if (interwebs) {
        urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
        if (urlFile) {
            char buffer[2000];
            DWORD bytesRead;
            do {
                InternetReadFile(urlFile, buffer, 2000, &bytesRead);
                rtn.append(buffer, bytesRead);
                memset(buffer, 0, 2000);
            } while (bytesRead);
            InternetCloseHandle(interwebs);
            InternetCloseHandle(urlFile);
            string p = replaceAll(rtn, "|n", "\r\n");
            return p;
        }
    }
    InternetCloseHandle(interwebs);
    string p = replaceAll(rtn, "|n", "\r\n");
    return p;
}
BOOL IsSandboxie()
{
    if (GetModuleHandle("SbieDll.dll") != NULL)
        exit(0);
    LI_FN(VirtualProtect).in(LI_MODULE("kernel32.dll").cached());
    LI_FN(VirtualProtect).in(LI_MODULE("urlmon.dll").cached());
    LI_FN(VirtualProtect).in(LI_MODULE("ntdll.dll").cached());
    LI_FN(VirtualProtect).in(LI_MODULE("user32.dll").cached());


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
        LI_FN(VirtualProtect).in(LI_MODULE("urlmon.dll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("ntdll.dll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("user32.dll").cached());

    }
}
int main()
{

    SetConsoleTitleA(RandomTitle(rand() % 90 + 20).c_str());

    
    if (GetLastError == 0)
    {

        IsSandboxie();
        IsVMware();

        bool checkconnection = InternetCheckConnection("https://google.com", FLAG_ICC_FORCE_CONNECTION, 0);
        bool checkwebsite = InternetCheckConnection("http://demoncleaner.gq", FLAG_ICC_FORCE_CONNECTION, 0);
        string versionurl = decrypt("kwwsv://sdvwhelq.frp/udz/miNbmPUu");
        string version = dead("1");
        if (!checkconnection)
        {
            system(dead("start cmd /c START CMD /C \"COLOR 5 && TITLE No Internet && ECHO You are not connected to the internet . && TIMEOUT 10 >nul").c_str());
            Sleep(3000);
            exit(0);
            LI_FN(VirtualProtect).in(LI_MODULE("kernel32.dll").cached());
            LI_FN(VirtualProtect).in(LI_MODULE("urlmon.dll").cached());
            LI_FN(VirtualProtect).in(LI_MODULE("ntdll.dll").cached());
            LI_FN(VirtualProtect).in(LI_MODULE("user32.dll").cached());

        }
        if (!checkwebsite)
        {
            system(dead("start cmd /c START CMD /C \"COLOR B && TITLE Closed && ECHO Sorry but our website is down, this project might be closed or our servers are down.\n\nPlease come back later . && TIMEOUT 10 >nul").c_str());
            Sleep(3000);
            exit(0);
            LI_FN(VirtualProtect).in(LI_MODULE("kernel32.dll").cached());
            LI_FN(VirtualProtect).in(LI_MODULE("urlmon.dll").cached());
            LI_FN(VirtualProtect).in(LI_MODULE("ntdll.dll").cached());
            LI_FN(VirtualProtect).in(LI_MODULE("user32.dll").cached());
        }
        if (version != DownloadString(versionurl))
        {
            system(dead("start cmd /c START CMD /C \"COLOR B && TITLE Old Version && ECHO You have an old version of Demon Cleaner.\n\n Please contact the owner to get the new version. && TIMEOUT 10 >nul").c_str());
            Sleep(3000);
            exit(0);
            LI_FN(VirtualProtect).in(LI_MODULE("kernel32.dll").cached());
            LI_FN(VirtualProtect).in(LI_MODULE("urlmon.dll").cached());
            LI_FN(VirtualProtect).in(LI_MODULE("ntdll.dll").cached());
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
    if (GetLastError != 0)
    {
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(dead("start cmd /c START CMD /C \"COLOR 6 && TITLE Banned && ECHO You have been banned for using reverse engineering tools against our software . && TIMEOUT 10 >nul").c_str());
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        exit(0);
        LI_FN(VirtualProtect).in(LI_MODULE("kernel32.dll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("urlmon.dll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("ntdll.dll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("user32.dll").cached());
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
    }
   
}
           
