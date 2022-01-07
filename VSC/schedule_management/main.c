#include "sched.h"

int main(int argc, char *argv[])
{
    HANDLE hando = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE handin = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleScreenBufferInfo(hando, &csbi);
    SetConsoleTitle("日程管理 @LHX  2021-2022");
    hide_cursor();
    printf("%s\n", welcome);
    // jindu(hando);
    system("cls");
    init_draw(hando);
    while (1)
    {
        // keyboard event
        Sleep(45);
        getdate(hando);
        kbevent();
    }
    CloseHandle(hando);
    CloseHandle(handin);
    return 0;
}