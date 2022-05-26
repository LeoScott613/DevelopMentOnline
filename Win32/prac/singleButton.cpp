#include <windows.h>
#include <commctrl.h>
#include <tchar.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow) {
    HWND butt=CreateWindowExA(
        0,
        (LPCSTR)WC_BUTTON,
        "Name of the button",
        WS_VISIBLE,
        100,100,
        70,70,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    MSG m;
    while(GetMessage(&m,NULL,0,0)>0) {
        TranslateMessage(&m);
        DispatchMessageA(&m);//nothing happens without window procedure
    }
    return 0;
}