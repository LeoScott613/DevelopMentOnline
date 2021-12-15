#include "sched.h"
int main(int argc, char *argv[])
{
    HANDLE hando = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hando, &csbi);
    SetConsoleTitle("日程管理 @LHX  2021-2022");
    printf("%s",welcome);
    Sleep(2000);
    system("cls");
    hide_cursor(hando);
    init_draw(hando);
    getch();
    CloseHandle(hando);
    return 0;
}