#include "application.h"
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE prevhinstance,PSTR pstr,int ncmdshow) {
    WNDCLASS mainwin={};
    mainwin.lpfnWndProc=procit;
    mainwin.lpszClassName=_T("mainwin");
    mainwin.hInstance=hInstance;
    RegisterClass(&mainwin);
    pos mainpos={300,300,400,270};
    pos loginbutt={130,160,100,45};
    pos password={90,100,185,22};
    pos account={90,30,185,22};

    HWND mainhand=CreateWindowExA(//main window
        0,
        mainwin.lpszClassName,
        _T("login"),
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        mainpos.x,mainpos.y,mainpos.width,mainpos.height,
        NULL,NULL,
        hInstance,
        NULL
    );
    HWND login=CreateWindowExA(
        0,
        WC_BUTTON,
        _T("login"),
        WS_VISIBLE | WS_CHILD,
        loginbutt.x,loginbutt.y,loginbutt.width,loginbutt.height,
        mainhand,
        NULL,hInstance,NULL
    );
    HWND pass=CreateWindowExA(
        0,
        WC_EDIT,
        NULL,
        WS_VISIBLE | WS_CHILD | ES_PASSWORD,
        password.x,password.y,password.width,password.height,
        mainhand,
        NULL,hInstance,NULL
    );
    HWND acc_edit=CreateWindowExA(
        0,
        WC_EDIT,
        NULL,
        WS_VISIBLE | WS_CHILD,
        account.x,account.y,account.width,account.height,
        mainhand,
        NULL,hInstance,NULL
    );


    MSG message;
    while(GetMessage(&message,NULL,0,0)>0) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return 0;
}