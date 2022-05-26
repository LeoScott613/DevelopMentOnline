#include <windows.h>
#include <tchar.h>
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int nCmdShow) {
    WNDCLASS wc = {};       //the {} is nessary with its initialization

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = _T("hello");

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
    0,                              // Optional window styles.
    _T("hello"),                     // Window class
    _T("First Windows Program"),    // Window text   //title
    WS_OVERLAPPEDWINDOW,            // Window style

    // Size and position
    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

    NULL,       // Parent window    
    NULL,       // Menu
    hInstance,  // Instance handle
    NULL        // Additional application data
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd,nCmdShow);//显示出窗口

    MSG m;
    while(GetMessage(&m,NULL,0,0)>0) {
        TranslateMessage(&m);//窗口能移动和使用三个按键
        DispatchMessage(&m);

        MessageBox(
            NULL,
            _T("Stuck you"),
            _T("Stuck you"),
            MB_OK
        );
    }

    return 0;
}
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);   //发送一个WM_QUIT消息到窗口线程的消息队列中，GetMessage接收到，返回的值就是0，主函数的消息循环就会退出，之后就会退出应用程序
        return 0;

    case WM_PAINT://这里只是用纯色绘制工作区
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}