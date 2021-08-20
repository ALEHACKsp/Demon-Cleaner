#include <windows.h>
#include <debugapi.h>
namespace protection
{
	class IsDbgPresent
	{
		int main(int argc, char** argv)
		{
			//! Recall IsDebuggerPresent will return 0 if one wasn't found
			if (IsDebuggerPresent())
			{
				MessageBoxA(NULL, "There is currently a debugger attached to the process.", "Error: Debugger", MB_OK);
				exit(0);
			}
			
			return 0;
		}
	};
	
	
	

	
}