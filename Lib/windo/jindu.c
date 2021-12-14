#include <windows.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    SetConsoleTitle("AlwaysHasBeen");
    printf("[                    ]");
    HANDLE hando = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hando, &csbi);
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hando,&cci);
    COORD jindu, po;
    po.X = 23;
    po.Y = 0;
    jindu.X = 1;
    jindu.Y = 0;
    int num = 0;
    getch();
    for (num = 1; num <= 100; num++)
    {
        SetConsoleCursorPosition(hando, po);
        printf("%d%%", num);
        if (!(num % 5))
        {
            SetConsoleCursorPosition(hando, jindu);
            printf("-");
            jindu.X++;
        }
        Sleep(30);
    }
    jindu.X=0,jindu.Y=1;
    SetConsoleCursorPosition(hando,jindu);
    printf("Good luck forever.");
    getch();
    CloseHandle(hando);
    return 0;
}