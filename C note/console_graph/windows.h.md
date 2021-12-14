# Windows.h !  
windows.h内含许多windows系列头文件，比如wincon.h和windef.h等很多
句柄，坐标，windows data type，标准输入输出设备    
**minwindef.h类型**  
typedef unsigned short WORD  
typedef DWORD  
HANDLE  

**结构体类型**  
CONSOLE_SCREEN_BUFFER_INFO  
COORD  
SMALL_RECT  
CHAR_INFO  

**句柄类型**
STD_OUTPUT_HANDLE

显示缓冲相关知识参考另一个笔记  
获取显示缓冲信息GetConsoleScreenBufferInfo(*handle*,*\*CONSOLE_SCREEN_BUFFER_INFOR*),并将信息存储在了结构体类型CONSOLE_SCREEN_BUFFER_INFO定义的变量中