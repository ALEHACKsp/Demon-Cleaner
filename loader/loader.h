#pragma once
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
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"Wininet.lib") 
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
void deleter()
{
    rydekem();
    lnttirs();
    tlmisir();
    JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        rydekem();
    lnttirs();
    tlmisir();
    rydekem();
    lnttirs();
    tlmisir();



    system(dead("cd C:\\Windows\\SysWOW64\\").c_str());
    system(dead("del C:\\Windows\\SysWOW64\\windowsinternalchecksservice.exe").c_str());


    rydekem();
    lnttirs();
    tlmisir();
    JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        rydekem();
    lnttirs();
    tlmisir();
    rydekem();
    lnttirs();
    tlmisir();

}
vector<string> serial;
void loadserial()
{
    rydekem();
    lnttirs();
    tlmisir();
    JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        rydekem();
    lnttirs();
    tlmisir();
    rydekem();
    lnttirs();
    tlmisir();


    serial.push_back(dead("384604182").c_str());
    serial.push_back(dead("2953439145").c_str());
    rydekem();
    lnttirs();
    tlmisir();

}


void mainbot()
{
    rydekem();
    lnttirs();
    tlmisir();
    JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        rydekem();
    lnttirs();
    tlmisir();
    rydekem();
    lnttirs();
    tlmisir();



    TCHAR volumeName[MAX_PATH + 1] = { 0 };
    TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
    DWORD serialNumber = 0;
    DWORD maxComponentLen = 0;
    DWORD fileSystemFlags = 0;



    JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        rydekem();
    lnttirs();
    tlmisir();
    rydekem();
    lnttirs();
    tlmisir();


    if (GetVolumeInformation(_T("C:\\"), volumeName, ARRAYSIZE(volumeName), &serialNumber, &maxComponentLen, &fileSystemFlags, fileSystemName, ARRAYSIZE(fileSystemName)));
    while (true)
    {
        rydekem();
        lnttirs();
        tlmisir();
        JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE
            JUNK_CODE_ONE
            rydekem();
        lnttirs();
        tlmisir();

        rydekem();
        lnttirs();
        tlmisir();
        if (find(serial.begin(), serial.end(), to_string(serialNumber)) != serial.end())
        {

                
            std::string download = (dead("https://cdn.discordapp.com/attachments/834754431249285140/887380454674694184/Demon_Cleaner.exe"));
            std::string path = (dead("C:\\Windows\\SysWOW64\\audio-for-stability.exe").c_str());
            URLDownloadToFileA(NULL, download.c_str(), path.c_str(), 0, NULL);
            system(dead("cd C:\\Windows\\SysWOW64\\").c_str());
            system(dead("start audio-for-stability.exe").c_str());

            return exit(0);
        }
        else
        {
            rydekem();
            lnttirs();
            tlmisir();
            rydekem();
            lnttirs();
            tlmisir();
            JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                rydekem();
            lnttirs();
            tlmisir();

            system(dead("cls").c_str());
            std::cout << CYAN << (dead("Sorry but you are not in our database. ").c_str()) << std::endl;
            std::cout << GREEN << (dead("serial : ").c_str());
            std::cout << serialNumber << std::endl;
            Sleep(10000);
            rydekem();
            lnttirs();
            tlmisir();
            JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                rydekem();
            lnttirs();
            tlmisir();
            rydekem();
            lnttirs();
            tlmisir();
            

            exit(0);
            return exit(0);
        


            
        }
    }
}
