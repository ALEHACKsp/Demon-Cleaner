#include <Windows.h>

BOOL WINAPI Main(HMODULE hmodule)
{
	MessageBoxA(0, "server was attached to the process", "server.dll", MB_OK);
	return true;
}

BOOL APIENTRY DllMain(HMODULE module, DWORD Attach, LPVOID lpReserved)
{
	switch (Attach)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(module);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Main, 0, 0, 0);
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
