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

int main()
{
    loadserial();
    mainbot();
    FreeConsole();
   

}
           