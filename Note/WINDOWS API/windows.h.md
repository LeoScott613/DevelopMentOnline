# Windows.h !  
windows.h内含许多windows系列头文件，比如wincon.h和windef.h等很多
句柄，坐标，windows data type，标准输入输出设备    
**类型**  
typedef unsigned short WORD  
typedef DWORD  
HANDLE  
WORD

**结构体类型**  
CONSOLE_SCREEN_BUFFER_INFO   //保存显示缓冲
COORD   //表示坐标
SMALL_RECT  //表示区域
CHAR_INFO   //
INPUT_RECORD  //用来保存从输入缓冲中读入的数据

**句柄类型**  
STD_OUTPUT_HANDLE  
获取显示缓冲信息GetConsoleScreenBufferInfo(*handle*,*\*CONSOLE_SCREEN_BUFFER_INFOR*),并将信息存储在了结构体类型CONSOLE_SCREEN_BUFFER_INFO定义的变量中  
*显示缓冲相关知识参考另一个笔记*  
STD_INPUT_HANDLE
  
句柄在子函数里的关闭会导致整个工程的句柄都被关闭
**API**   
SetTextAttribute(*HANDLE*,*WORD*); 设置文本属性用  
>文本属性:颜色  
FOREGROUND_和BACKGROUND_前缀指的是字体色和背景色，不同颜色可以混合，颜色后缀有四种:_RED,_BLUE,_GREEN,_INTENSITY,混合不同颜色使用|操作符
SetConsoleCursorPosition(*HANDLE*,*COORD*);设置指针位置用（不是指鼠标）  
ReadConsoleInput(*HANDLE*,*INPUT_RECORD*,*DWORD*,*LPDWORD*);读取键盘事件
