////////////////////////////////////////////////////////////////////////////////
// Filename: main.cpp
////////////////////////////////////////////////////////////////////////////////
#include "System\system.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	bool result;

	// Initialize and run the system object.
	result = System::Instance()->Initialize();
	if(result) {
		System::Instance()->Run();
	}

	// Shutdown and release the system object.
	System::Instance()->Shutdown();

	return 0;
}