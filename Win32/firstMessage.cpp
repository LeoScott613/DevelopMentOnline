#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    MessageBox(
        NULL,
        TEXT("quote"),
        TEXT("This is a quote"),
        MB_OK
    );
    return 0;
}