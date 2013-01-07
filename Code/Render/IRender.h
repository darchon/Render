/******************************
* IRender.h
******************************/
#ifndef _IRENDER_H_
#define _IRENDER_H_

// Includes
#include <Windows.h>

// Globals
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class __declspec(novtable) IRender //novtable stops vtable from being created
{
public:
	virtual ~IRender() {}

	virtual bool Initialize(int screenWidth, int screenHeight, bool fullscreen,HWND hwnd) = 0;
	virtual void Shutdown() = 0;
	virtual bool Frame() = 0;

};

#endif