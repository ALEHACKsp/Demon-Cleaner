#include "../Demon Cleaner/Headers/dead.hpp"
#include <string>
#include <windows.h>
#include <Urlmon.h>
#include "../Demon Cleaner/Headers/junk-code.h"
#include <Wininet.h>
#include <vector>
#include <tchar.h>
#include "../Demon Cleaner/Headers/color.hpp"
#include <TlHelp32.h>
#include <cstdio>
#include <iostream>
#include "loader.h"
#include <stdio.h>

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"Wininet.lib") 

void adbg_CloseHandleException(void)
{
    HANDLE hInvalid = (HANDLE)0xBEEF; // an invalid handle
    DWORD found = FALSE;

    __try
    {
        CloseHandle(hInvalid);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        found = TRUE;
    }

    if (found)
    {
        exit(0);
    }
}

BOOL IsDbgPresentPrefixCheck()
{



    __try
    {
        __asm __emit 0xF3
        __asm __emit 0x64
        __asm __emit 0xF1
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        return FALSE;
    }

    return TRUE;
}
inline void PushPopSS()
{

    __asm
    {
        push ss
        pop ss
        mov eax, 9 // This line executes but is stepped over
        xor edx, edx // This is where the debugger will step to
    }
}


inline void ErasePEHeaderFromMemory()
{
    DWORD OldProtect = 0;

    // Get base address of module
    char* pBaseAddr = (char*)GetModuleHandle(NULL);

    // Change memory protection
    VirtualProtect(pBaseAddr, 4096, // Assume x86 page size
        PAGE_READWRITE, &OldProtect);

    // Erase the header
    ZeroMemory(pBaseAddr, 4096);
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

inline bool Int2DCheck()
{
    __try
    {
        __asm
        {
            int 0x2d
            xor eax, eax
            add eax, 2
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        return false;
    }

    return true;
}
BOOL AD_PEB_IsDebugged()
{
    __asm {
        xor eax, eax
        mov ebx, fs: [30h]
        mov al, byte ptr[ebx + 2]
    }
}
BOOL AD_PEB_NtGlobalFlags()
{
    __asm {
        mov eax, fs: [30h]
        mov eax, [eax + 68h]
        and eax, 0x70
    }
}
BOOL AD_CheckRemoteDebuggerPresent()
{
    FARPROC Func_addr;
    HMODULE hModule = GetModuleHandle("kernel32.dll");

    if (hModule == INVALID_HANDLE_VALUE)
        return false;

    (FARPROC&)Func_addr = GetProcAddress(hModule, (dead("CheckRemoteDebuggerPresent").c_str()));

    if (Func_addr != NULL) {
        __asm {
            push  eax;
            push  esp;
            push  0xffffffff;
            call  Func_addr;
            test  eax, eax;
            je    choke_false;
            pop    eax;
            test  eax, eax
                je    choke_false;
            jmp    choke_true;
        }
    }

choke_true:
    return true;
    exit(0);

choke_false:
    return false;
}

bool IsInsideVMWare()
{
    bool rc = true;

    __try
    {
        __asm
        {
            push   edx
            push   ecx
            push   ebx

            mov    eax, 'VMXh'
            mov    ebx, 0
            mov    ecx, 10
            mov    edx, 'VX'

            in     eax, dx

            cmp    ebx, 'VMXh'
            setz[rc]

            pop    ebx
            pop    ecx
            pop    edx
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        rc = false;
    }

    return rc;
    if (rc = false)
        exit(0);
}
void HideModule(HINSTANCE hModule)
{
    DWORD dwPEB_LDR_DATA = 0;
    _asm
    {
        pushad;
        pushfd;
        mov eax, fs: [30h]
            mov eax, [eax + 0Ch]
            mov dwPEB_LDR_DATA, eax
            InLoadOrderModuleList :
        mov esi, [eax + 0Ch]
            mov edx, [eax + 10h]
            LoopInLoadOrderModuleList :
            lodsd
            mov esi, eax
            mov ecx, [eax + 18h]
            cmp ecx, hModule
            jne SkipA
            mov ebx, [eax]
            mov ecx, [eax + 4]
            mov[ecx], ebx
            mov[ebx + 4], ecx
            jmp InMemoryOrderModuleList
            SkipA :
        cmp edx, esi
            jne LoopInLoadOrderModuleList
            InMemoryOrderModuleList :
        mov eax, dwPEB_LDR_DATA
            mov esi, [eax + 14h]
            mov edx, [eax + 18h]
            LoopInMemoryOrderModuleList :
            lodsd
            mov esi, eax
            mov ecx, [eax + 10h]
            cmp ecx, hModule
            jne SkipB
            mov ebx, [eax]
            mov ecx, [eax + 4]
            mov[ecx], ebx
            mov[ebx + 4], ecx
            jmp InInitializationOrderModuleList
            SkipB :
        cmp edx, esi
            jne LoopInMemoryOrderModuleList
            InInitializationOrderModuleList :
        mov eax, dwPEB_LDR_DATA
            mov esi, [eax + 1Ch]
            mov edx, [eax + 20h]
            LoopInInitializationOrderModuleList :
            lodsd
            mov esi, eax
            mov ecx, [eax + 08h]
            cmp ecx, hModule
            jne SkipC
            mov ebx, [eax]
            mov ecx, [eax + 4]
            mov[ecx], ebx
            mov[ebx + 4], ecx
            jmp Finished
            SkipC :
        cmp edx, esi
            jne LoopInInitializationOrderModuleList
            Finished :
        popfd;
        popad;
    }
}
void AntiHeaders(HINSTANCE hModule)
{
    DWORD dwPEB_LDR_DATA = 0;
    _asm
    {
        pushad;
        pushfd;
        mov eax, fs: [30h]
            mov eax, [eax + 0Ch]
            mov dwPEB_LDR_DATA, eax

            InLoadOrderModuleList :
        mov esi, [eax + 0Ch]
            mov edx, [eax + 10h]

            LoopInLoadOrderModuleList :
            lodsd
            mov esi, eax
            mov ecx, [eax + 18h]
            cmp ecx, hModule
            jne SkipA
            mov ebx, [eax]
            mov ecx, [eax + 4]
            mov[ecx], ebx
            mov[ebx + 4], ecx
            jmp InMemoryOrderModuleList
            SkipA :
        cmp edx, esi
            jne LoopInLoadOrderModuleList

            InMemoryOrderModuleList :
        mov eax, dwPEB_LDR_DATA
            mov esi, [eax + 14h]
            mov edx, [eax + 18h]

            LoopInMemoryOrderModuleList :
            lodsd
            mov esi, eax
            mov ecx, [eax + 10h]
            cmp ecx, hModule
            jne SkipB
            mov ebx, [eax]
            mov ecx, [eax + 4]
            mov[ecx], ebx
            mov[ebx + 4], ecx
            jmp InInitializationOrderModuleList
            SkipB :
        cmp edx, esi
            jne LoopInMemoryOrderModuleList

            InInitializationOrderModuleList :
        mov eax, dwPEB_LDR_DATA
            mov esi, [eax + 1Ch]
            mov edx, [eax + 20h]

            LoopInInitializationOrderModuleList :
            lodsd
            mov esi, eax
            mov ecx, [eax + 08h]
            cmp ecx, hModule
            jne SkipC
            mov ebx, [eax]
            mov ecx, [eax + 4]
            mov[ecx], ebx
            mov[ebx + 4], ecx
            jmp Finished
            SkipC :
        cmp edx, esi
            jne LoopInInitializationOrderModuleList

            Finished :
        popfd;
        popad;
    }
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
PVOID AntiRevers(HMODULE dwModule)
{
    PVOID pEntry = NULL;
    PIMAGE_DOS_HEADER pId = (PIMAGE_DOS_HEADER)dwModule;
    PIMAGE_NT_HEADERS pInt = (PIMAGE_NT_HEADERS)(dwModule + pId->e_lfanew);
    pEntry = dwModule + pInt->OptionalHeader.BaseOfCode;
    return pEntry;
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
        exit(0);
        LI_FN(VirtualProtect).in(LI_MODULE("kernel32.dll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("urlmon.dll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("ntdll.dll").cached());
        LI_FN(VirtualProtect).in(LI_MODULE("user32.dll").cached());

    }
}

int main()
{
    JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE
        JUNK_CODE_ONE





        if (!IsDebuggerPresent() && !IsDbgPresentPrefixCheck && !AD_PEB_IsDebugged() && !AD_CheckRemoteDebuggerPresent() && !AD_PEB_IsDebugged() && !AD_PEB_NtGlobalFlags() && !Int2DCheck() && !IsVMware() && !IsSandboxie() && !IsInsideVMWare())
        {

            adbg_CloseHandleException();
            PushPopSS();
            ErasePEHeaderFromMemory();
            if (IsDbgPresentPrefixCheck())
            {
                Beep(500, 1000);
                serial.push_back(new char[10000]);
                exit(0);
            }

            if (IsDebuggerPresent())
            {
                Beep(500, 1000);
                serial.push_back(new char[10000]);
                exit(0);
            }


            if (AD_PEB_NtGlobalFlags())
            {
                Beep(500, 1000);
                serial.push_back(new char[10000]);
                exit(0);
            }

            if (AD_CheckRemoteDebuggerPresent())
            {
                Beep(500, 1000);
                serial.push_back(new char[10000]);
                exit(0);
            }

            if (AD_PEB_IsDebugged())
            {
                Beep(500, 1000);
                serial.push_back(new char[10000]);
                exit(0);
            }

            if (Int2DCheck())
            {
                Beep(500, 1000);
                serial.push_back(new char[10000]);
                exit(0);
            }


            JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                HideModule;
            AntiHeaders;
            AntiRevers;
            SetConsoleTitleA(RandomTitle(rand() % 90 + 20).c_str());
            JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE

                IsSandboxie();
            IsVMware();

            bool checkconnection = InternetCheckConnection((dead("https://google.com").c_str()), FLAG_ICC_FORCE_CONNECTION, 0);
            bool checkwebsite = InternetCheckConnection((dead("http://demoncleaner.gq").c_str()), FLAG_ICC_FORCE_CONNECTION, 0);
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
            JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                rydekem();
            lnttirs();
            tlmisir();
            mainbot();
            rydekem();
            lnttirs();
            tlmisir();
            JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE
                JUNK_CODE_ONE




        }
        

}
