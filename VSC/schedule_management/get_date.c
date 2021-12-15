#include "sched.h"
void getdate(HANDLE hand)
{
    system("date /t>date.t");
    FILE *p;
    p=fopen("date.t","r");
    char date[20],nowtime[20];
    fscanf(p,"%s",date);//read date from file
    system("time /t>date.t");
    p=fopen("date.t","r");
    fscanf(p,"%s",nowtime);//read time from file
    time_pos.X = 29;
    time_pos.Y = 2;
    SetConsoleCursorPosition(hand, time_pos);
    printf("%s  %s",date,nowtime);
    fclose(p);
}