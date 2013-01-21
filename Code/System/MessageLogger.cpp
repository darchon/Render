/******************************
* MessageLogger.cpp
******************************/
#include "MessageLogger.h"
#include "System.h"


MessageLogger::MessageLogger()
{
}

MessageLogger::~MessageLogger()
{
}

void MessageLogger::Initialize()
{
	MessageManager::Instance()->RegisterHandler(this, DEFAULT_MSG | INFO_MSG | ERROR_MSG | DEBUG_MSG);
}

void MessageLogger::Shutdown()
{
}

bool MessageLogger::Notify(char* msg)
{
	//Once we get a notify do something with it here
	//Send msg to windows notice for testing
	size_t converted = 0;
	wchar_t widechar[128];	//128 char max
	//mbstowcs_s(widechar, msg, strlen(msg)+1,);//Plus null
	mbstowcs_s(&converted, widechar, strlen(msg) + 1, msg, _TRUNCATE);
	MessageBox(System::Instance()->GetWindowsHandle(),
		widechar,
		L"MessageLogger Error",  
		MB_OK);
	return true;
}