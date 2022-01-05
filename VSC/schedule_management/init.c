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
    printf("手册\n|按M选择日期\n|按N新建日程\n|ESC返回\n|~~~~~~~~~~~\n|按R选择日程\n|按D删除\n|按E编辑");

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

    printf("January");

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
    // draw all event
    FILE *readcontent;
    readcontent = fopen("data.t", "r");
    // the position of 日程 drawing
    curpos.X = 60;
    curpos.Y = 0;
    while (!feof(readcontent))
    {
        int day = -1, hour = -1, min = -1, year, monthh;
        char content[200];
        SetConsoleCursorPosition(hand, curpos);
        fscanf(readcontent, "%04d.%02d.%03d.%02d:%02d:\"%s\"", &year, &monthh, &day, &hour, &min, content);
        if (hour != -1 && min != -1) //针对的是文件的最后一行空白
            printf("时间 %04d/%02d/%02d %02d:%02d      内容 \"%s", year, monthh, day, hour, min, content);
        curpos.Y++;
        curpos.X = 60;
    }
    fclose(readcontent); //使用完文件指针一定要关闭
}

COORD current_month(int year, int month) // calculate the position of the 1st of the month
{
    COORD cr;
    cr.X = 20 + 9;
    cr.Y = 11 + 1; // start of Dec 1st,2021
    int dism = 0;
    int ty = year, tm = month;
    while (year > 2021)
    {
        dism++, tm--;
        if (tm == 0)
            tm = 12, ty--;
        if (tm == 12 && ty == 2021)
            break;
    }
    ty = year, tm = month;
    while (year < 2021 || (year == 2021 && tm < 12))
    {
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
            dism++;
            if (pml == monthlength)
                pml = monthlength + 11;
            else
                pml--;
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
