#include <time.h>
#include <windows.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    HANDLE hando = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hando, &csbi);
    // const clock_t delay = CLOCKS_PER_SEC;
    COORD pos;
    pos.X = 0;
    pos.Y = 0;
    int now = 1;
    SMALL_RECT sr;
    sr.Left = sr.Right = sr.Bottom = sr.Top = 0;
    CHAR_INFO chfill;
    chfill.Char.AsciiChar = ' ';
    chfill.Attributes = csbi.wAttributes;
    static CONSOLE_CURSOR_INFO ci;
    ci.bVisible = 0;
    ci.dwSize = 1;

    /*
    while (1)
    {
        printf("%d", now);
        now++;
        // ScrollConsoleScreenBuffer(hando,&sr,NULL,pos,&chfill);
        SetConsoleCursorPosition(hando, pos);
        SetConsoleCursorInfo(hando, &ci);
        // sr.Left++,sr.Right++;
        Sleep(1000);
    }
    */

    SetConsoleCursorInfo(hando, &ci);
    printf("Diming...");
    COORD posi;
    posi.X = 10;
    posi.Y = 0;
    int i = 0;
    for (; i < 15; i++)
    {
        Sleep(500);
        SetConsoleCursorPosition(hando, posi);
        printf(" ");
        if (posi.X)
            posi.X--;
        else break;
    }
    CloseHandle(hando);
    return 0;
}