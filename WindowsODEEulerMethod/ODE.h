#pragma once

#ifndef _ODE_H_
#define _ODE_H_

#include "framework.h"
#include "resource.h"

class ODE
{
private:
	HINSTANCE hInstance;
	HWND _TabWnd;
	HWND _ODEWnd;
	HWND _TableWnd;
	HWND _GraphWnd;
	HWND _Parent;
	WCHAR _name[256];
	WCHAR *_ODEStr;


	void createWindows(HWND);

public:
	static void registerWindows(HINSTANCE);
	ODE(WCHAR[256], HINSTANCE, HWND);
	~ODE();
	void setTab(int);

};

#endif