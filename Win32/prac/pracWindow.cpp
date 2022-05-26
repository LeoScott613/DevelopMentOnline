#include <windows.h>
#include <tchar.h>
#include <commctrl.h>
typedef INITCOMMONCONTROLSEX commctrlex;
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow) {

    WNDCLASS forWindow={};    

    forWindow.lpfnWndProc=WindowProc;
    forWindow.lpszClassName=_T("pracWindow");   //_T() is defined in tchar.h
    forWindow.hInstance=hInstance; //the parameter of WinMain

    RegisterClass(&forWindow);  //register require its address

    HWND hand=CreateWindowEx(
        0,
        _T("pracWindow"),
        _T("Title"),
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,

        //size, position; use default
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,
        NULL,
        hInstance,
        NULL
    );    
    if(hand==NULL)
        return -1;
    
    //ShowWindow(hand,nCmdShow);
    //You don't have to use ShowWindow once you use WX_VISIBLE style

    
    //to load certain control from DLL
    
    commctrlex myctrl;
    myctrl.dwICC=ICC_STANDARD_CLASSES;
    myctrl.dwSize=sizeof(myctrl);//don't know why
    InitCommonControlsEx(&myctrl);
    HWND button=CreateWindowExA(
        0,
        "BUTTON",
        "name",
        WS_VISIBLE,
        80,80,50,50,
        hand,
        NULL,
        hInstance,
        NULL
    );
    //ShowWindow(button,nCmdShow);

    MSG m;
    while(GetMessage(&m,NULL,0,0)>0) {
        TranslateMessage(&m);
        DispatchMessage(&m);
    }

    return 0;
}
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        MessageBox(
            NULL,
            _T("You can't close the window!"),
            _T("WARN from author"),
            MB_OK
        );
        PostQuitMessage(0);
        return 0;//LRESULT

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}