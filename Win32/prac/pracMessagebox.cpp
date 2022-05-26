#include <windows.h>
#include <tchar.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow) {
    MessageBox(
        NULL,
        _T("A practice"),
        _T("A practice's title"),
        MB_OKCANCEL
    );
    return 0;
}