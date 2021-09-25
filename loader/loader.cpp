#include "../Demon Cleaner/Headers/xorstr.hpp"
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
int main()
{
    SetConsoleTitle("Demon Cleaner V1.0");
    if (IsDebuggerPresent())
    {

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(dead("start cmd /c START CMD /C \"COLOR C && TITLE Detected && ECHO Debugger Detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (GetLastError == 0)
    {
        bool checkconnection = InternetCheckConnection("https://google.com/", FLAG_ICC_FORCE_CONNECTION, 0);
        if (!checkconnection)
        {
            system(dead("start cmd /c START CMD /C \"COLOR C && TITLE No Internet && ECHO You are not connected to the internet . && TIMEOUT 10 >nul").c_str());
            Sleep(3000);
            exit(0);
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
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
    }
   
}
           
