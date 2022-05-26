#include <windows.h>
#include <tchar.h>
#include <commctrl.h>
#include <strsafe.h>
LRESULT CALLBACK winproc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
// Retrieve the system error message for the last-error code
void ErrorExit(LPTSTR lpszFunction) 
{ 
    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError(); 

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );

    // Display the error message and exit the process

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, 
        (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR)); 
    StringCchPrintf((LPTSTR)lpDisplayBuf, 
        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s failed with error %d: %s"), 
        lpszFunction, dw, lpMsgBuf); 
    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK); 

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
    ExitProcess(dw); 
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow) {
    //registration
    WNDCLASS fatherwindow={};//!!! necessary
    fatherwindow.lpfnWndProc=winproc;
    fatherwindow.lpszClassName=_T("lhx");
    fatherwindow.hInstance=hInstance;

    RegisterClass(&fatherwindow);

    //main window
    HWND hand_f=CreateWindow(
        _T("lhx"),
        _T("Title"),
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100,100,
        500,500,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if(hand_f==NULL) {
        ErrorExit(_T("CreateWindow"));
    }
    
    HWND butt=CreateWindowEx(//create the button
        0,
        WC_BUTTON,
        _T("There is it"),
        WS_CHILD | WS_VISIBLE,
        30,80,
        80,25,
        hand_f,
        NULL,
        hInstance,
        NULL
    );

    HWND edit=CreateWindowExA(//create the edit
        0,
        (LPCSTR)WC_EDIT,
        NULL,
        WS_VISIBLE | WS_CHILD,
        30,30,
        80,25,
        hand_f,
        NULL,
        hInstance,
        NULL
    );

    HWND selection=CreateWindowExA(//create the window of combo box, not enough
        0,
        (LPCSTR)WC_COMBOBOX,
        "No selection",
        CBS_SIMPLE | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
        30,130,
        80,25,
        hand_f,
        NULL,
        hInstance,
        NULL
    );
    TCHAR string[]=_T("item 1");
    TCHAR item2[]=_T("item 2");
    SendMessage(selection,CB_ADDSTRING,0,(LPARAM)string);//add item to the item list
    SendMessage(selection,CB_ADDSTRING,0,(LPARAM)item2);//add item to the item list
    SendMessage(selection, CB_SETCURSEL, (WPARAM)1,0);


    //message loop
    MSG m;
    while(GetMessage(&m,NULL,0,0)>0) {
        TranslateMessage(&m);
        DispatchMessage(&m);
    }

    return 0;
}
LRESULT CALLBACK winproc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT: {//important
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW));

            EndPaint(hwnd, &ps);
        }
            return 0;
        case WM_COMMAND: {
            MessageBox(
                NULL,
                _T("you selected."),
                _T("notification"),
                MB_OK
            );
        }
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}