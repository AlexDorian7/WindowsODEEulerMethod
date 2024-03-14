#pragma once

#ifndef _ODE_H_
#define _ODE_H_

#include <Windows.h>

class ODE
{
private:
	HWND ODEWnd;
	HWND TableWnd;
	HWND GraphWnd;
	WCHAR name[256];

public:
	ODE(WCHAR[256]);
};

#endif