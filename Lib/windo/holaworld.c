#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>

int main()
{
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE); //获得标准输出设备句柄
    CONSOLE_SCREEN_BUFFER_INFO csbi;                     //定义窗口缓冲区信息结构体
    SMALL_RECT scroll;                                   //定义移动区域
    COORD pos = {0, 5};                                  //移动位置
    CHAR_INFO chFill;                                    //定义填充字符
    GetConsoleScreenBufferInfo(handle_out, &csbi);       //获得窗口缓冲区信息
    //定义填充字符的各个参数及属性
    chFill.Char.AsciiChar = ' ';
    chFill.Attributes = csbi.wAttributes;
    //输出文本
    printf("00000000000000000000000000000\n");
    printf("11111111111111111111111111111\n");
    printf("22222222222222222222222222222\n");
    printf("33333333333333333333333333333\n");
    //确定区域
    scroll.Left = 1;
    scroll.Top = 1;
    scroll.Right = 10;
    scroll.Bottom = 2;
    ScrollConsoleScreenBuffer(handle_out, &scroll, NULL, pos, &chFill); //移动文本
    //Sleep(5000);
    getch();
    return 0;
}