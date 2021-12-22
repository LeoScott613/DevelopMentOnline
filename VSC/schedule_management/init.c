#include "sched.h"
void hide_cursor(HANDLE hand) // hide cursor
{
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hand, &cci);
}
void show_cursor() // show cursor
{
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
    cci.bVisible = 1;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hand, &cci);
}
void init_draw(HANDLE hand) // initial draw
{
    WORD attrib;
    attrib = csbi.wAttributes;
    SetConsoleTextAttribute(hand, attrib);
    int i = 1;
    const int sche_bot = 24; // the lowest
    for (i = 1; i < sche_bot; i++)
        printf("|           |\n");
    // attrib = FOREGROUND_BLUE;
    SetConsoleTextAttribute(hand, attrib);
    printf("-------------\n");
    COORD curpos;
    // draw schedule list
    curpos.X = 0;
    curpos.Y = 0;
    SetConsoleCursorPosition(hand, curpos);
    attrib = csbi.wAttributes;
    SetConsoleTextAttribute(hand, attrib);
    printf("-------------");

    curpos.X = 1;
    curpos.Y++;
    SetConsoleCursorPosition(hand, curpos);
    printf("代办");

    /*
        FILE *ctin;
        ctin=fopen("data.t","r");
        int day,hour,minute;
        while(ctin->_flag!=EOF)
        {
            char *content;
            fprintf(ctin,"%03d.%02d:%02d%%%s", day, hour, minute,content);
            curpos.Y++;
            curpos.X=1;
            SetConsoleCursorPosition(hand,curpos);
            printf("%03d.%02d:%02d%%%s",day,hour,minute,content);
        }
    */
   
    //-------------------
    // draw copyright
    char line[] = "|                                   |";
    char wel_line[] = "|日程管理                           |";
    curpos.X = 15;
    curpos.Y = 0;
    // attrib = FOREGROUND_BLUE;
    SetConsoleTextAttribute(hand, attrib);
    SetConsoleCursorPosition(hand, curpos);
    printf("-------------------------------------");
    curpos.Y++;

    attrib = csbi.wAttributes;
    SetConsoleTextAttribute(hand, attrib);
    SetConsoleCursorPosition(hand, curpos);
    for (i = 1; i < sche_bot / 4; i++)
    {
        if (curpos.Y == 2)
            printf("%s", wel_line);
        else
            printf("%s", line);
        curpos.Y++;
        SetConsoleCursorPosition(hand, curpos);
    }
    // attrib = FOREGROUND_BLUE;
    SetConsoleTextAttribute(hand, attrib);
    for (i = 1; i <= strlen(line); i++)
        printf("-");
    //---------------------
    // draw Month
    curpos.Y += 2;
    attrib = csbi.wAttributes;
    SetConsoleTextAttribute(hand, attrib);
    SetConsoleCursorPosition(hand, curpos);
    for (i = 1; i <= strlen(line); i++)
        printf("-");

    curpos.X += 14;
    curpos.Y++;
    SetConsoleCursorPosition(hand, curpos);
    printf("December");

    month_pos.X = 20; // definition of month_pos
    month_pos.Y = 11; // definition of month_pos
    SetConsoleCursorPosition(hand, month_pos);
    printf("Mon Tue Wed Thu Fri Sat Sun");
    curpos.X = month_pos.X + 9, curpos.Y = month_pos.Y + 1; // the position of '1'
    SetConsoleCursorPosition(hand, curpos);
    for (i = 1; i <= 31; i++)
    {
        printf("%2d", i);
        if (curpos.X == month_pos.X + 25)
        {
            curpos.X = month_pos.X + 1;
            curpos.Y += 2;
        }
        else
            curpos.X += 4;
        SetConsoleCursorPosition(hand, curpos);
    }
    //----------
}