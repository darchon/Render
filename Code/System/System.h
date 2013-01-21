////////////////////////////////////////////////////////////////////////////////
// Filename: System.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

///////////////////////////////
// PRE-PROCESSING DIRECTIVES //
///////////////////////////////
#define WIN32_LEAN_AND_MEAN

//////////////
// INCLUDES //
//////////////
#include <windows.h>

#include "MessageLogger.h"
#include "..\Input\Input.h"
#include "..\Render\IRender.h"

/////////////////////////
// FUNCTION PROTOTYPES //
/////////////////////////
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

class System
{
public:
	static System* Instance();

	bool Initialize();
	void Shutdown();
	void Run();

	//Helpers
	HWND GetWindowsHandle() const;

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	System();
	System(const System&);
	System& operator= (System const&);
	~System();

	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

private:
	static System*	m_inst;

	LPCWSTR			m_applicationName;
	HINSTANCE		m_hinstance;
	HWND			m_hwnd;

	InputClass*		m_Input;
	IRender*		m_Graphics;
	MessageLogger*	m_Logger;
};

/////////////
// GLOBALS //
/////////////
//static System* ApplicationHandle = 0;

#endif