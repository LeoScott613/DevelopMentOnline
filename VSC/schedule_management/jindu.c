#include "sched.h"
void jindu(HANDLE hamdle)
{
    COORD jindu, po;
    WORD jindutiao,defaul;
    jindutiao=BACKGROUND_INTENSITY;
    defaul=csbi.wAttributes;
    po.X = 102;
    po.Y = 7;
    jindu.X = 0;
    jindu.Y = 7;
    int num = 0;
    Sleep(1000);
    for (num = 1; num <= 100; num++)
    {
        SetConsoleCursorPosition(hamdle, po);
        SetConsoleTextAttribute(hamdle,defaul);
        printf("%d%%", num);

        SetConsoleCursorPosition(hamdle, jindu);
        SetConsoleTextAttribute(hamdle,jindutiao);
        printf(" ");
        jindu.X++;
        Sleep(50);
    }
    SetConsoleTextAttribute(hamdle,defaul);
}