#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    HANDLE hando = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hando,&csbi);
    printf("cursor x:%d, y:%d \n",csbi.dwSize.X,csbi.dwSize.Y);
    SMALL_RECT smar = {1, 1, 1, 2};
    CHAR_INFO chfill;
    chfill.Char.AsciiChar=' ';
    chfill.Attributes=csbi.wAttributes;
    COORD pos = {3, 3};
    puts("00000000");
    puts("00000000");
    puts("00000000");
    Sleep(300);
    ScrollConsoleScreenBuffer(hando, &smar, NULL, pos, &chfill);
    Sleep(5000);
    return 0;
}