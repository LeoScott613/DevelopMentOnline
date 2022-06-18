# WinApi编程
## 前言
有一些api需要额外链接库文件，这时候有两种方式可以选择，一种是```#pragma comment(lib,"comctl32.lib")```，另一种是gcc编译时使用-l编译参数链接库文件```gcc loginPage.c callback.c -lcomctl32```

## 机制
消息机制
绘制机制
控件

## 遇到的Bug汇总
* WNDCLASS变量定义之后没有紧跟={ }  
这会导致没有初始化这个结构体（*或者是类？*），导致注册window class失败
* WM_PAINT消息的响应中没有PostQuitMessage  
导致控制台没有关掉
* 按钮或窗口的的WS STYLE没有添加WS_VISIBLE属性  
导致没有显示出来
* gcc编译时没有使用-l参数链接必要的库  
<del>我tm杀了微软</del>