#include "sched.h"
void getdate(HANDLE hand)
{
    system("date /t>date");
    FILE *p;
    p=fopen("date","r");
    char date[20],nowtime[20];
    fscanf(p,"%s",date);//read date from file
    system("time /t>date");
    p=fopen("date","r");
    fscanf(p,"%s",nowtime);//read time from file
    time_pos.X = 29;
    time_pos.Y = 2;
    SetConsoleCursorPosition(hand, time_pos);
    printf("%s  %s ",date,nowtime);
    fclose(p);
}