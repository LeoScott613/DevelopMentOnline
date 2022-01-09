#include "sched.h"
void kbevent() // it needs a std input handle
{
    static INPUT_RECORD inre;
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hand = GetStdHandle(STD_INPUT_HANDLE);
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
        event_st *eventbuffer = buff();
        // the position of 日程 drawing
        tar.X = 60;
        tar.Y = 0;
        do
        {
            SetConsoleCursorPosition(hout, tar);
            printf("时间 %04d/%02d/%02d %02d:%02d  内容 %s 地点 %s", eventbuffer->year, eventbuffer->month, eventbuffer->day, eventbuffer->hour, eventbuffer->min, eventbuffer->content, eventbuffer->place);
            tar.Y++;
            tar.X = 60;
            eventbuffer = eventbuffer->next;
        } while (eventbuffer != NULL);
    }
    WORD vkc = inre.Event.KeyEvent.wVirtualKeyCode;
    if ((vkc == 'R' || vkc == 'D' || vkc == 'E') && inre.Event.KeyEvent.bKeyDown) // event list menu
    {
        while (1)
        {
            int exit_st = management();
            if (exit_st)
                break;
        }
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

    //在右侧画出日程清单
    event_st *p = buff();
    // the position of 日程 drawing
    tar.X = 60;
    tar.Y = 0;
    while (p != NULL)
    {
        SetConsoleCursorPosition(hando, tar);
        if (p->day == i && p->year == *currentyear && p->month == *currentmonth)
        {
            printf("时间 %02d:%02d  内容 %s 地点\"%s\"", p->hour, p->min, p->content, p->place);
            tar.Y++;
            tar.X = 60;
        }
        p = p->next;
    }
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
    char content[50], place[50];
    HANDLE hando;
    COORD curpos;
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

    // start to input data of a new event
    curpos.X = 60;
    curpos.Y = 0;
    show_cursor(); // show the cursor in order to indicate the position to the user
    SetConsoleCursorPosition(hando, curpos);
    printf("Time(hous:minute):");
    scanf("%d:%d", &h, &min);

    curpos.Y += 2;
    SetConsoleCursorPosition(hando, curpos);
    printf("Content:");
    getchar(); //吃掉一个回车
    gets(content);

    curpos.Y += 2;
    SetConsoleCursorPosition(hando, curpos);
    printf("Place:");
    gets(place);

    event_st *head = buff();
    event_st *p = head, *new;
    while (p->next != NULL)
        p = p->next;
    new = (event_st *)malloc(sizeof(event_st));
    p->next = new;
    p = p->next;
    p->next = NULL;
    p->year = currentyear;
    p->month = currentmonth;
    p->day = i;
    p->hour = h;
    p->min = min;
    strcpy(p->content, content);
    strcpy(p->place, place);
    buff(); // renew file from buffer

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
int management() // have no choice to write this
{
    int exit_status = 0;

    system("cls");
    COORD curpos;
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE), hand = GetStdHandle(STD_INPUT_HANDLE);
    curpos.X = 0;
    curpos.Y = 0;
    SetConsoleCursorPosition(hout, curpos);
    WORD attrib = BACKGROUND_INTENSITY;
    event_st *p1 = buff();
    printf("p(^_^)q :Welcome!\n\n---这里是管理界面---\n\n可以使用上下键选择一个日程\n按下D删除\n按下E编辑\n按下ESC退出\n\n");
    int bufferlength = 0;
    while (p1 != NULL)
    {
        printf(":-> 时间 %04d/%02d/%02d %02d:%02d  内容 %s 地点\"%s\"", p1->year, p1->month, p1->day, p1->hour, p1->min, p1->content, p1->place);
        putchar('\n');
        p1 = p1->next;
        bufferlength++; //记录缓冲链表的长度以备后续使用
    }
    putchar('\n');
    //以上，把界面重画了
    curpos.X = 0;
    curpos.Y = 9;
    SetConsoleCursorPosition(hout, curpos);
    SetConsoleTextAttribute(hout, attrib);
    printf(":->");
    SetConsoleTextAttribute(hout, csbi.wAttributes);
    //以上是画一个深色箭头
    int indicator = 1;
    INPUT_RECORD inre;
    DWORD back;
    while (1)
    {
        ReadConsoleInput(hand, &inre, 1, &back);
        WORD key = inre.Event.KeyEvent.wVirtualKeyCode;
        if (indicator > 1 && key == VK_UP && inre.Event.KeyEvent.bKeyDown)
        {
            curpos.X = 0;
            SetConsoleCursorPosition(hout, curpos);
            printf(":->");
            SetConsoleTextAttribute(hout, attrib);
            curpos.X = 0;
            curpos.Y--;
            SetConsoleCursorPosition(hout, curpos);
            printf(":->");
            SetConsoleTextAttribute(hout, csbi.wAttributes);
            indicator--;
        }
        else if (indicator < bufferlength && key == VK_DOWN && inre.Event.KeyEvent.bKeyDown)
        {
            curpos.X = 0;
            SetConsoleCursorPosition(hout, curpos);
            printf(":->");
            SetConsoleTextAttribute(hout, attrib);
            curpos.X = 0;
            curpos.Y++;
            SetConsoleCursorPosition(hout, curpos);
            printf(":->");
            SetConsoleTextAttribute(hout, csbi.wAttributes);
            indicator++;
        }
        else if (key == 'D' && inre.Event.KeyEvent.bKeyDown)
        {
            int i = indicator - 1;
            event_st *head = buff(), *p = head, *pahead = p;

            for (; i > 0; i--)
                p = p->next;
            while (pahead->next != p && pahead != p) //防止它们在开头相遇
            {
                pahead = pahead->next;
            }
            if (pahead->next == p) //删除的不是头节点
            {
                pahead->next = p->next;
            }
            else if (p == head && bufferlength != 1) //删除的是头节点
            {
                // head = head->next;  无效的做法
                char requirement[50] = "6K+35aS05oyH6ZKI5L2N56e7"; // base64: 请buff函数改变头指针
                strcpy(head->content, requirement);
            }
            if (bufferlength != 1)
                free(p);
            else
                SetConsoleTitle("警告！！！至少要保留一个日程！！！");
            buff();
            return exit_status;
        }
        else if (key == VK_ESCAPE && inre.Event.KeyEvent.bKeyDown)
        {
            system("cls");
            init_draw(hout);
            return !(exit_status);
        }
    }
}