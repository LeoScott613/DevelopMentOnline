#include <windows.h>
#include <tchar.h>
#include <commctrl.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pstr, int ncmdshow) {
    HWND edit=CreateWindowExA(
        0,
        WC_EDIT,
        _T("这个小时"),
        WS_VISIBLE,
        220,320,
        800,50,
        NULL,NULL,
        hInstance,NULL
    );

    MSG m;
    while(GetMessage(&m,NULL,0,0)>0) {
        TranslateMessage(&m);
        DispatchMessageA(&m);
    }
    return 0;
}