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
    SetConsoleTextAttribute(hand, attrib);
    printf("-------------\n");
    COORD curpos;
    // draw manual list
    curpos.X = 0;
    curpos.Y = 0;
    SetConsoleCursorPosition(hand, curpos);
    attrib = csbi.wAttributes;
    SetConsoleTextAttribute(hand, attrib);
    printf("-------------");

    curpos.X = 1;
    curpos.Y++;
    SetConsoleCursorPosition(hand, curpos);
    printf("手册\n|m选择日期\n|选择后n新建\n|esc返回");

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
    system("date /t>date");
    FILE *p;
    p = fopen("date", "r");
    int year = 2022, mo = 1;
    char date[30];
    fscanf(p, "%s", date); // read date from file
    fclose(p);
    year = (*(date) - '0') * 1000 + (*(date + 1) - '0') * 100 + (*(date + 2) - '0') * 10 + (*(date + 3) - '0');
    mo = (*(date + 5) - '0') * 10 + (*(date + 6) - '0');

    printf("December");

    month_pos.X = 20; // definition of month_pos
    month_pos.Y = 11; // definition of month_pos
    SetConsoleCursorPosition(hand, month_pos);
    printf("Mon Tue Wed Thu Fri Sat Sun");
    // curpos.X = month_pos.X + 9, curpos.Y = month_pos.Y + 1; // the position of '1'
    curpos = current_month(year, mo);
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

COORD current_month(int year, int month) // calculate the position of the 1st of the month
{
    COORD  cr;
    cr.X = 20 + 9;
    cr.Y = 11 + 1; // start of Dec 1st,2021
    int dism = 0;
    while (year > 2021)
    {
        int ty = year, tm = month;
        dism++, tm--;
        if (tm == 0)
            tm = 12, ty--;
        if (tm == 12 && ty == 2021)
            break;
    }
    while (year < 2021 || (year == 2021 && month < 12))
    {
        int ty = year, tm = month;
        dism--, tm++;
        if (tm == 13 && ty != 2021)
        {
            ty++;
            tm = 1;
        }
        if (tm == 12 && ty == 2021)
            break;
    }

    int monthlength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, *pml = monthlength + 11;

    if (dism < 0) // when current month is before Dec 2021
        while (dism)
        {
            if (*pml == 31)
            {
                int i = 0;
                for (; i < 3; i++) // regulation
                {
                    if (cr.X == 21) // 21 is position of monday
                        cr.X = 45;  // 45 is 21+24, which is the position of sunday
                    else
                        cr.X -= 4;
                }
            }
            else if (*pml == 30)
            {
                int i = 0;
                for (; i < 2; i++) // regulation
                {
                    if (cr.X == 21) // 21 is position of monday
                        cr.X = 45;  // 45 is 21+24, which is the position of sunday
                    else
                        cr.X -= 4;
                }
            }
            else if (*pml == 28)
                ;

            dism++;
            if (pml == monthlength)
                pml = monthlength + 11;
            else
                pml--;
        }
    else if (dism > 0) // when current month is after Dec 2021
        while (dism)
        {
            if (*pml == 31)
            {
                int i = 0;
                for (; i < 3; i++) // regulation
                {
                    if (cr.X == 45) // 45 is 21+24, which is the position of sunday
                        cr.X = 21;  // 21 is position of monday
                    else
                        cr.X += 4;
                }
            }
            else if (*pml == 30)
            {
                int i = 0;
                for (; i < 2; i++) // regulation
                {
                    if (cr.X == 45) // 45 is 21+24, which is the position of sunday
                        cr.X = 21;  // 21 is position of monday
                    else
                        cr.X += 4;
                }
            }
            else if (*pml == 28)
                ;

            if (pml == monthlength + 11)
                pml = monthlength;
            else
                pml++;
            dism--;
        }
    return cr;
}
