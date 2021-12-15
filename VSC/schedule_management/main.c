#include "sched.h"

int main(int argc, char *argv[])
{
    HANDLE hando = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hando, &csbi);
    SetConsoleTitle("日程管理 @LHX  2021-2022");
    hide_cursor(hando);
    printf("%s\n", welcome);
    jindu(hando);
    //Sleep(2000);
    system("cls");
    init_draw(hando);
    while (1)
    {
        //keyboard event
        getdate(hando);
        Sleep(60000);
    }
    CloseHandle(hando);
    return 0;
}