#include "sched.h"
void kbevent(HANDLE hand) // it needs a std input handle
{
    INPUT_RECORD inre;
    DWORD back;          //用来接受成功读取记录数
    static COORD target; // used to transmit the coordinate to processor()
    static int entermlist = 0;
    ReadConsoleInput(hand, &inre, 1, &back);
    // if(inre.EventType==KEY_EVENT)
    // printf("great");
    if (inre.Event.KeyEvent.wVirtualKeyCode == 'M' && inre.Event.KeyEvent.bKeyDown) // month::enter
    {
        target.X = month_pos.X + 9;
        target.Y = month_pos.Y + 1;
        processor(target);
        entermlist = 1;
    }
    if (entermlist && inre.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT && inre.Event.KeyEvent.bKeyDown) // month::right
    {
        resetpro(target);
        if (target.X == month_pos.X + 25)
        {
            target.X = month_pos.X + 1;
            target.Y += 2;
        }
        else
            target.X += 4;
        processor(target);
    }
    else if (entermlist && inre.Event.KeyEvent.wVirtualKeyCode == VK_LEFT && inre.Event.KeyEvent.bKeyDown) // month::left
    {
        resetpro(target);
        if (target.X == month_pos.X + 1)
        {
            target.X = month_pos.X + 25;
            target.Y -= 2;
        }
        else
            target.X -= 4;
        processor(target);
    }
    else if (entermlist && inre.Event.KeyEvent.wVirtualKeyCode == 'N' && inre.Event.KeyEvent.bKeyDown) // month::new
    {
        newevent(target);
        lhxResetEvent();
    }
    else if (entermlist && inre.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE && inre.Event.KeyEvent.bKeyDown) // month::exit
    {
        resetpro(target);
        entermlist = 0;
    }
}
void processor(COORD tar) // a drawing unit corresponding to kbevent
{
    HANDLE hando = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD attrib;
    int i = 1;
    COORD distance = tar;
    while (distance.X != month_pos.X + 9 || distance.Y != month_pos.Y + 1) // for finding the i
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
    while (i > 31) // not to break the end of the month
    {
        if (tar.X == month_pos.X + 1)
        {
            tar.X = month_pos.X + 25;
            tar.Y -= 2;
        }
        else
            tar.X -= 4;
        i--;
    }
    SetConsoleCursorPosition(hando, tar);
    attrib = BACKGROUND_INTENSITY;
    SetConsoleTextAttribute(hando, attrib);
    printf("%2d", i);

    SetConsoleTextAttribute(hando, csbi.wAttributes); // reset text attribute, necessary

    FILE *readcontent;
    readcontent = fopen("data.t", "r");
    tar.X = 1;
    tar.Y = 2;
    while (!feof(readcontent))
    {
        int day = -1, hour = 0, min = 0;
        char *content;
        SetConsoleCursorPosition(hando, tar);
        fscanf(readcontent, "%03d.%02d:%02d:\"%s\"", &day, &hour, &min, &content);
        if (day == i)
        {
            printf("%02d:%02d\"%s", hour, min, &content);
            tar.Y++;
            tar.X = 1;
        }
    }
}

void resetpro(COORD tar)
{
    CONSOLE_CURSOR_INFO tempcci;
    HANDLE hando = GetStdHandle(STD_OUTPUT_HANDLE);
    int i = 1;
    COORD distance = tar;
    while (distance.X != month_pos.X + 9 || distance.Y != month_pos.Y + 1) // for finding the i
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
    while (i > 31) // not to break the end of the month
    {
        if (tar.X == month_pos.X + 1)
        {
            tar.X = month_pos.X + 25;
            tar.Y -= 2;
        }
        else
            tar.X -= 4;
        i--;
    }
    SetConsoleCursorPosition(hando, tar);
    printf("%2d", i); // reset number intensity

    // reset list
    tar.X = 1;
    tar.Y = 2;
    int j = 1;
    char *newline = "           |";
    for (; j < 20; j++)
    {
        SetConsoleCursorPosition(hando, tar);
        printf("%s", newline);
        tar.Y += 1;
        tar.X = 1;
    }
}
void newevent(COORD tar)
{
    int i = 1, h = 0, min = 0;
    char content[50];
    HANDLE hando;
    COORD curpos;
    FILE *content_out;
    content_out = fopen("data.t", "a");

    while (tar.X != month_pos.X + 9 || tar.Y != month_pos.Y + 1) // for finding the i
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
    curpos.X = 60;
    curpos.Y = 0;
    /*SetConsoleCursorPosition(hando, curpos);
    printf("Day:");
    scanf("%d", &i);

    curpos.Y += 2;*/
    show_cursor();
    SetConsoleCursorPosition(hando, curpos);
    printf("Time(hous:minute):");
    scanf("%d:%d", &h, &min);

    curpos.Y += 2;
    SetConsoleCursorPosition(hando, curpos);
    printf("Content:");
    scanf("%s", &content);

    fprintf(content_out, "%03d.%02d:%02d:\"%s\"\n", i, h, min, &content);

    curpos.Y = 3; // not really, should read file
    curpos.X = 1;

    fclose(content_out);
}
void lhxResetEvent() // conflicting name
{
    HANDLE hando;
    COORD curpos;
    char *newline = "                                                            ";
    hando = GetStdHandle(STD_OUTPUT_HANDLE);
    curpos.X = 60;
    curpos.Y = 0;
    /*SetConsoleCursorPosition(hando, curpos);
    printf("    ");
    curpos.Y += 2;*/
    hide_cursor(hando);
    SetConsoleCursorPosition(hando, curpos);
    printf("%s", &newline);
    curpos.Y += 2;
    SetConsoleCursorPosition(hando, curpos);
    printf("%s", &newline);
}