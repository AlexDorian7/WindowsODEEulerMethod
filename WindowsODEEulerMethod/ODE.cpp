#include "ODE.h"

void ODE::createWindows(HWND parent)
{

    RECT parentRect;
    GetClientRect(parent, &parentRect);

    _TabWnd = CreateWindow(WC_TABCONTROL, L"Tabs", WS_CHILD | WS_VISIBLE, parentRect.left, parentRect.top, parentRect.right - parentRect.left, parentRect.bottom - parentRect.top, parent, nullptr, hInstance, nullptr);

    TCITEM tie = { 0 };
    tie.mask = TCIF_TEXT;
    TCHAR TabTitle[16];
    LoadString(hInstance, IDS_EQUATION_TAB_TITLE, TabTitle, 16);
    tie.pszText = TabTitle;
    TabCtrl_InsertItem(_TabWnd, 0, &tie);
    LoadString(hInstance, IDS_TABLE_TAB_TITLE, TabTitle, 16);
    tie.pszText = TabTitle;
    TabCtrl_InsertItem(_TabWnd, 1, &tie);
    LoadString(hInstance, IDS_GRAPH_TAB_TITLE, TabTitle, 16);
    tie.pszText = TabTitle;
    TabCtrl_InsertItem(_TabWnd, 2, &tie);

    RECT tabRect;
    GetClientRect(_TabWnd, &tabRect);

    SendMessage(_TabWnd, TCM_ADJUSTRECT, FALSE, (LPARAM)&tabRect);

    _ODEWnd = CreateWindowW(L"STATIC", L"ODE Window", WS_CHILD | WS_VISIBLE, tabRect.left, tabRect.top, tabRect.right-tabRect.left, tabRect.bottom-tabRect.top, _TabWnd, nullptr, hInstance, nullptr);
    _TableWnd = CreateWindowW(L"STATIC", L"Table Window", WS_CHILD, tabRect.left, tabRect.top, tabRect.right - tabRect.left, tabRect.bottom - tabRect.top, _TabWnd, nullptr, hInstance, nullptr);
    _GraphWnd = CreateWindowW(L"STATIC", L"Graph Window", WS_CHILD, tabRect.left, tabRect.top, tabRect.right - tabRect.left, tabRect.bottom - tabRect.top, _TabWnd, nullptr, hInstance, nullptr);
    CreateWindowW(L"STATIC", L"DEBUG", WS_CHILD | WS_VISIBLE, 0, 20, 100, 20, _ODEWnd, nullptr, hInstance, nullptr);

    UpdateWindow(_ODEWnd);

    UpdateWindow(parent); // update the parent
    //RedrawWindow(parent, NULL, NULL, RDW_INVALIDATE | RDW_ERASE); // FORCE redraw the window parent (Not needed)
}

void ODE::registerWindows(HINSTANCE hInstance)
{
}


ODE::ODE(WCHAR name[256], HINSTANCE hInst, HWND parent)
{
    hInstance = hInst;
    for (int i = 0; i < 256; i++)
    {
        _name[i] = name[i];
    }
    _ODEStr = (WCHAR*) malloc(sizeof(WCHAR) * 256);
    _Parent = parent;
    createWindows(parent);
}

ODE::~ODE()
{
    DestroyWindow(_ODEWnd);
    DestroyWindow(_TableWnd);
    DestroyWindow(_GraphWnd);
    DestroyWindow(_TabWnd);
    free(_ODEStr);
}

void ODE::setTab(int selected)
{
    switch (selected)
    {
    case 0:
        ShowWindow(_ODEWnd, SW_SHOW);
        ShowWindow(_TableWnd, SW_HIDE);
        ShowWindow(_GraphWnd, SW_HIDE);
        break;
    case 1:
        ShowWindow(_ODEWnd, SW_HIDE);
        ShowWindow(_TableWnd, SW_SHOW);
        ShowWindow(_GraphWnd, SW_HIDE);
        break;
    case 2:
        ShowWindow(_ODEWnd, SW_HIDE);
        ShowWindow(_TableWnd, SW_HIDE);
        ShowWindow(_GraphWnd, SW_SHOW);
        break;
    }

    UpdateWindow(_TabWnd);
}