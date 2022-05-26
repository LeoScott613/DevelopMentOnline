主函数  
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)  
显示一个提示框用MessageBox(1，2，3，4)函数，参数分别是：窗口句柄，消息内容，标题内容，用MB_xx定义的按钮  
MB_xx有  
* MB_OK                ok
* MB_OKCANCEL          ok和取消
* MB_ABORTRETRYIGNORE  中止、重试和取消
* MB_YESNOCANCEL       yes/no/取消
* MB_YESNO             yes和no
* MB_RETRYCANCEL       重试和取消

## 创建一个完整的windows窗口
步骤
* 定义```LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);```
* 创建一个WNDCLASS类型的变量
* 给变量做必要的初始化
* 将WNDCLASS类型的变量用RegisterClass函数注册，*注意传入的是其地址*
* 用CreateWindowEx创建窗口，用HWND类型变量接收句柄
* 显示窗口和执行消息循环
* 结束

具体参见firstWindows.h  

tchar.h中的_T("")宏，功能是识别编译器字符串格式并转换，避免cannot convert 'const wchar_t*' to 'LPCSTR {aka const char*}这种错误  