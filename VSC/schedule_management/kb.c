#include "sched.h"
void kbevent(HANDLE hand) // it needs a std input handle
{
    INPUT_RECORD inre;
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD back;          //用来接受成功读取记录数
    static COORD target; // used to transmit the coordinate to processor()
    static int entermlist = 0;
    ReadConsoleInput(hand, &inre, 1, &back);
    static int currentmonth = 1, currentyear = 2022;
    COORD start_of_current_month = current_month(currentyear, currentmonth);

    if (inre.Event.KeyEvent.wVirtualKeyCode == 'M' && inre.Event.KeyEvent.bKeyDown) // month::enter
    {
        target = current_month(currentyear, currentmonth);
        processor(target, &target, &currentyear, &currentmonth);
        resetpro(target, &target, &currentyear, &currentmonth);
        processor(target, &target, &currentyear, &currentmonth); //用三次是因为要重画日程栏
        entermlist = 1;
    }
    if (entermlist && inre.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT && inre.Event.KeyEvent.bKeyDown) // month::right
    {
        resetpro(target, &target, &currentyear, &currentmonth);
        if (target.X == month_pos.X + 25)
        {
            target.X = month_pos.X + 1;
            target.Y += 2;
        }
        else
            target.X += 4;
        processor(target, &target, &currentyear, &currentmonth);
    }
    else if (entermlist && inre.Event.KeyEvent.wVirtualKeyCode == VK_LEFT && inre.Event.KeyEvent.bKeyDown) // month::left
    {
        resetpro(target, &target, &currentyear, &currentmonth);
        if (target.X != start_of_current_month.X || target.Y != start_of_current_month.Y)
        {
            if (target.X == month_pos.X + 1)
            {
                target.X = month_pos.X + 25;
                target.Y -= 2;
            }
            else
                target.X -= 4;
        }
        else //再按一次左键就会超界的情况
        {
            currentmonth--;
            int i;

            if (currentmonth == 0)
            {
                currentmonth = 12;
                currentyear--;
            }

            // 先把画出来的日期清除
            target = month_pos;
            target.X++;
            target.Y++;
            for (i = 1; i <= 60; i++)
            {
                SetConsoleCursorPosition(hout, target);
                // printf("%2d", i);
                printf("  "); //清除专用
                if (target.X == month_pos.X + 25)
                {
                    target.X = month_pos.X + 1;
                    target.Y += 2;
                }
                else
                    target.X += 4;
            }
            //然后画出月份
            target.X = 29;
            target.Y = 9;
            SetConsoleCursorPosition(hout, target);
            printf("           ");
            SetConsoleCursorPosition(hout, target);
            printf("%d年%d月", currentyear, currentmonth);

            //开始画日期
            target = current_month(currentyear, currentmonth);
            SetConsoleCursorPosition(hout, target);
            int monthlength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, *pml = monthlength + currentmonth - 1;
            for (i = 1; i <= *pml; i++)
            {
                printf("%2d", i);
                if (target.X == month_pos.X + 25)
                {
                    target.X = month_pos.X + 1;
                    target.Y += 2;
                }
                else
                    target.X += 4;
                SetConsoleCursorPosition(hout, target);
            }
            if (target.X == month_pos.X + 1) //最后一次绘制日期时target会向后移，所以要移回来
            {
                target.X = month_pos.X + 25;
                target.Y -= 2;
            }
            else
                target.X -= 4;
            SetConsoleCursorPosition(hout, target);
        }
        processor(target, &target, &currentyear, &currentmonth);
    }
    else if (entermlist && inre.Event.KeyEvent.wVirtualKeyCode == 'N' && inre.Event.KeyEvent.bKeyDown) // month::new
    {
        newevent(target, currentyear, currentmonth);
        // lhxResetEvent();
    }
    else if (entermlist && inre.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE && inre.Event.KeyEvent.bKeyDown) // month::exit
    {
        COORD tar; // temp usage
        resetpro(target, &target, &currentyear, &currentmonth);
        entermlist = 0;

        // next: draw all event
        FILE *readcontent;
        readcontent = fopen("data.t", "r");
        // the position of 日程 drawing
        tar.X = 60;
        tar.Y = 0;
        while (!feof(readcontent))
        {
            int day = -1, hour = -1, min = -1, year, monthh;
            char content[200];
            SetConsoleCursorPosition(hout, tar);
            fscanf(readcontent, "%04d.%02d.%03d.%02d:%02d:\"%s\"", &year, &monthh, &day, &hour, &min, content);
            if (hour != -1 && min != -1) //针对的是文件的最后一行空白
                printf("时间 %04d/%02d/%02d %02d:%02d      内容 \"%s", year, monthh, day, hour, min, content);
            tar.Y++;
            tar.X = 60;
        }
        fclose(readcontent); //使用完文件指针一定要关闭
    }
}
void processor(COORD tar, COORD *ptar, int *currentyear, int *currentmonth) // a drawing unit corresponding to kbevent
{
    HANDLE hando = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD attrib;
    int i = 1;
    COORD distance = tar;
    COORD start_of_current_month = current_month(*currentyear, *currentmonth);
    int month_day_[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while (distance.X != start_of_current_month.X || distance.Y != start_of_current_month.Y) // for finding the i
    {
        if (distance.X == month_pos.X + 1)
        {
            distance.X = month_pos.X + 25;
            distance.Y -= 2;
        }
        else
            distance.X -= 4;
        i++;
    }

    if (i > *(month_day_ + *currentmonth - 1))
    //右键超界之后的操作放在这个分支里了
    {
        (*currentmonth)++; //千万注意后自增运算符的优先级最高，最好能记得所有运算符的运算次序
        if (*currentmonth == 13)
        {
            (*currentyear)++;
            *currentmonth = 1;
        }
        int ii;

        // 先把画出来的日期清除
        *ptar = month_pos;
        ptar->X++;
        ptar->Y++;
        for (ii = 1; ii <= 60; ii++)
        {
            SetConsoleCursorPosition(hando, *ptar);
            // printf("%2d", i);
            printf("  "); //清除专用
            if (ptar->X == month_pos.X + 25)
            {
                ptar->X = month_pos.X + 1;
                ptar->Y += 2;
            }
            else
                ptar->X += 4;
        }

        //然后画出月份
        ptar->X = 29;
        ptar->Y = 9;
        SetConsoleCursorPosition(hando, *ptar);
        printf("               ");
        SetConsoleCursorPosition(hando, *ptar);
        printf("%d年%d月", *currentyear, *currentmonth);

        //开始画日期
        *ptar = current_month(*currentyear, *currentmonth);
        SetConsoleCursorPosition(hando, *ptar);
        int monthlength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, *pml = monthlength + *currentmonth - 1;
        for (ii = 1; ii <= *pml; ii++)
        {
            printf("%2d", ii);
            if (ptar->X == month_pos.X + 25)
            {
                ptar->X = month_pos.X + 1;
                ptar->Y += 2;
            }
            else
                ptar->X += 4;
            SetConsoleCursorPosition(hando, *ptar);
        }
        if (ptar->X == month_pos.X + 1) //最后一次绘制日期时target会向后移，所以要移回来
        {
            ptar->X = month_pos.X + 25;
            ptar->Y -= 2;
        }
        else
            ptar->X -= 4;
        SetConsoleCursorPosition(hando, *ptar);
        i = 1;
        *ptar = current_month(*currentyear, *currentmonth);
    }

    SetConsoleCursorPosition(hando, *ptar);
    attrib = BACKGROUND_INTENSITY;
    SetConsoleTextAttribute(hando, attrib);
    printf("%2d", i);

    SetConsoleTextAttribute(hando, csbi.wAttributes); // reset text attribute, necessary

    FILE *readcontent;
    readcontent = fopen("data.t", "r");
    // the position of 日程 drawing
    tar.X = 60;
    tar.Y = 0;
    while (!feof(readcontent))
    {
        int day = -1, hour = 0, min = 0, year, monthh;
        char content[200];
        SetConsoleCursorPosition(hando, tar);
        fscanf(readcontent, "%04d.%02d.%03d.%02d:%02d:\"%s\"", &year, &monthh, &day, &hour, &min, content);
        if (day == i && year == *currentyear && monthh == *currentmonth)
        {
            printf("时间 %02d:%02d      内容 \"%s", hour, min, content);
            tar.Y++;
            tar.X = 60;
        }
    }
    fclose(readcontent); //使用完文件指针一定要关闭
}
void resetpro(COORD tar, COORD *ptar, int *currentyear, int *currentmonth)
{
    HANDLE hando = GetStdHandle(STD_OUTPUT_HANDLE);
    int i = 1;
    COORD distance = tar;
    COORD start_of_current_month = current_month(*currentyear, *currentmonth);               // in fact, useless, but I don't want to change it
    while (distance.X != start_of_current_month.X || distance.Y != start_of_current_month.Y) // for finding the i
    {
        if (distance.X == month_pos.X + 1)
        {
            distance.X = month_pos.X + 25;
            distance.Y -= 2;
        }
        else
            distance.X -= 4;
        i++;
    }

    SetConsoleCursorPosition(hando, tar);
    printf("%2d", i); // reset number intensity

    // reset list
    tar.X = 60;
    tar.Y = 0;
    int j = 1;
    char *newline = "                                                            ";
    for (; j < 30; j++)
    {
        SetConsoleCursorPosition(hando, tar);
        printf("%s", newline);
        tar.Y += 1;
        tar.X = 60;
    }
}
void newevent(COORD tar, int currentyear, int currentmonth)
{

    int i = 1, h = 0, min = 0;
    char content[50];
    HANDLE hando;
    COORD curpos;
    FILE *content_out;
    content_out = fopen("data.t", "a");
    COORD start_of_current_month = current_month(currentyear, currentmonth);

    while (tar.X != start_of_current_month.X || tar.Y != start_of_current_month.Y) // for finding the i
    {
        if (tar.X == month_pos.X + 1)
        {
            tar.X = month_pos.X + 25;
            tar.Y -= 2;
        }
        else
            tar.X -= 4;
        i++;
    }
    if (i > 31) // in order not to break the endline
        return;
    hando = GetStdHandle(STD_OUTPUT_HANDLE);

    // clear list drawing
    curpos.X = 60;
    curpos.Y = 0;
    int j = 1;
    char *newline = "                                                ";
    for (; j < 30; j++)
    {
        SetConsoleCursorPosition(hando, curpos);
        printf("%s", newline);
        curpos.Y += 1;
        curpos.X = 60;
    }

    curpos.X = 60;
    curpos.Y = 0;
    show_cursor(); // show the cursor in order to indicate the position to the user
    SetConsoleCursorPosition(hando, curpos);
    printf("Time(hous:minute):");
    scanf("%d:%d", &h, &min);

    curpos.Y += 2;
    SetConsoleCursorPosition(hando, curpos);
    printf("Content:");
    scanf("%s", &content);

    fprintf(content_out, "%04d.%02d.%03d.%02d:%02d:\"%s\"\n", currentyear, currentmonth, i, h, min, &content);
    fclose(content_out);

    // clear list drawing
    curpos.X = 60;
    curpos.Y = 0;
    for (j = 1; j < 30; j++)
    {
        SetConsoleCursorPosition(hando, curpos);
        printf("%s", newline);
        curpos.Y += 1;
        curpos.X = 60;
    }
    hide_cursor(hando); // re-hide the cursor
}
/* Due to the principle of being precise, I disable this function on 29th Dec.
void lhxResetEvent() // conflicting name
{//clear drawing after new an event
    HANDLE hando;
    COORD curpos;
    char *newline = "                                                            ";
    hando = GetStdHandle(STD_OUTPUT_HANDLE);
    curpos.X = 60;
    curpos.Y = 0;
    hide_cursor(hando);
    SetConsoleCursorPosition(hando, curpos);
    printf("%s", &newline);
    curpos.Y += 2;
    SetConsoleCursorPosition(hando, curpos);
    printf("%s", &newline);
}
*/