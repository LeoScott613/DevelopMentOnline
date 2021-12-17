#include <stdio.h>
#include <windows.h>
int main()
{
    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE); //获得标准输入设备句柄
    INPUT_RECORD keyrec;                               //定义输入事件结构体
    DWORD res;                                         //定义返回记录
    for (;;)
    {
        ReadConsoleInput(handle_in, &keyrec, 1, &res); //读取输入事件
        if (keyrec.EventType == KEY_EVENT&&keyrec.Event.KeyEvent.bKeyDown)             //如果当前事件是键盘事件
        {
            //if (keyrec.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) //当前事件的虚拟键为Esc键
            //{
                printf("Esc ");
            //}
        }
    }
    return 0;
}