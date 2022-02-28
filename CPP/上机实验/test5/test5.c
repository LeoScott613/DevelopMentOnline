#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
char *menu[5] = {"1.New linklist", "2.Display present linklist", "3.Search", "4.Save present linklist to file", "5.Read the file to the linklist"};
typedef struct t5
{
    char str[50];
    struct t5 *next;
} test5;

HANDLE hin, hout;
COORD curpos;
WORD attrib = BACKGROUND_INTENSITY;
CONSOLE_SCREEN_BUFFER_INFO csbi;
CONSOLE_CURSOR_INFO cci;
INPUT_RECORD ir;
DWORD c;

test5 *new (); // return the *head of the linklist
void display(test5 *);
void search(test5 *);
void save(test5 *);
void read(test5 *);
int main()
{
    SetConsoleTitle("上机实验5@LuHongXiang");
    hin = GetStdHandle(STD_INPUT_HANDLE);
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hout, &csbi);
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hout, &cci);

    printf("%s\n%s\n%s\n%s\n%s\n---\nUse direction key.\nWarning: You must create a linklist first!", menu[0], menu[1], menu[2], menu[3], menu[4]);
    curpos.X = curpos.Y = 0;
    SetConsoleCursorPosition(hout, curpos);
    SetConsoleTextAttribute(hout, attrib);
    int now = 1;
    printf("%s", menu[now - 1]);
    SetConsoleTextAttribute(hout, csbi.wAttributes);
    test5 *head = NULL;
    while (1)
    {
        while (1)
        {
            ReadConsoleInput(hin, &ir, 1, &c);
            if (ir.Event.KeyEvent.wVirtualKeyCode == VK_RETURN && ir.Event.KeyEvent.bKeyDown)
            {
                break;
            }
            else if (now > 1 && ir.Event.KeyEvent.wVirtualKeyCode == VK_UP && ir.Event.KeyEvent.bKeyDown)
            {
                curpos.X = 0;
                curpos.Y = now - 1;
                SetConsoleTextAttribute(hout, csbi.wAttributes);
                SetConsoleCursorPosition(hout, curpos);
                printf("%s", menu[now - 1]);
                now--;
                curpos.X = 0;
                curpos.Y = now - 1;
                SetConsoleCursorPosition(hout, curpos);
                SetConsoleTextAttribute(hout, attrib);
                printf("%s", menu[now - 1]);
                SetConsoleTextAttribute(hout, csbi.wAttributes); // reset color
            }
            else if (now < 5 && ir.Event.KeyEvent.wVirtualKeyCode == VK_DOWN && ir.Event.KeyEvent.bKeyDown)
            {
                curpos.X = 0;
                curpos.Y = now - 1;
                SetConsoleCursorPosition(hout, curpos);
                SetConsoleTextAttribute(hout, csbi.wAttributes);
                printf("%s", menu[now - 1]);
                now++;
                curpos.X = 0;
                curpos.Y = now - 1;
                SetConsoleCursorPosition(hout, curpos);
                SetConsoleTextAttribute(hout, attrib);
                printf("%s", menu[now - 1]);
                SetConsoleTextAttribute(hout, csbi.wAttributes); // reset color
            }
        }

        switch (now)
        {
        default:
            break;
        case 1:
            head = new ();
            break;
        case 2:
            (head == NULL) ? puts("nothing") : display(head);
            break;
        case 3:
            (head == NULL) ? "nothing" : search(head);
            break;
        case 4:
            (head == NULL) ? "nothing" : save(head);
            break;
        case 5:
            read(head);
            break;
        }
    }
    return 0;
}

test5 *new ()
{
    test5 *head = (test5 *)malloc(sizeof(test5)), *p;
    p = head;
    curpos.X = 0;
    curpos.Y = 8;
    SetConsoleCursorPosition(hout, curpos);
    int clear = 0;
    for (; clear < 20; clear++)
    {
        printf("                                                    \n");
    }
    curpos.X = 0;
    curpos.Y = 8;
    SetConsoleCursorPosition(hout, curpos);
    puts("Enter them:");
    gets(p->str);
    // p->str-=strlen(p->str)-1;//str is moved to the end of the array by input operation
    while (strcmp(p->str, ""))
    {
        test5 *new = (test5 *)malloc(sizeof(test5));
        p->next = new;
        p = p->next;
        gets(p->str);
        // p->str-=strlen(p->str)-1;//str is moved to the end of the array by input operation
    }
    p->next = NULL;
    curpos.X = 0;
    curpos.Y = 8;
    SetConsoleCursorPosition(hout, curpos);
    for (clear = 0; clear < 20; clear++)
    {
        printf("                                                    \n");
    }
    return head;
}
void display(test5 *t)
{
    curpos.X = 0;
    curpos.Y = 8;
    SetConsoleCursorPosition(hout, curpos);
    int clear = 0;
    for (; clear < 20; clear++)
    {
        printf("                                                    \n");
    }

    test5 *p = t;
    curpos.X = 0;
    curpos.Y = 8;
    SetConsoleCursorPosition(hout, curpos);
    while (p->next != NULL)
    {
        // puts("succeed");
        puts(p->str);
        p = p->next;
    }
    puts(p->str);
}
void search(test5 *t)
{
    // clear first
    curpos.X = 0;
    curpos.Y = 8;
    SetConsoleCursorPosition(hout, curpos);
    int clear = 0;
    for (; clear < 20; clear++)
    {
        printf("                                                    \n");
    }
    curpos.X = 0;
    curpos.Y = 8;
    SetConsoleCursorPosition(hout, curpos); // reset position

    test5 *p = t;
    char srch[50];
    puts("Enter the string you want to search:");
    gets(srch);
    for (; p->next != NULL; p = p->next)
    {
        if (strcmp(p->str, srch) == 0)
        {
            puts("Yes.");
            p = NULL;
            break;
        }
    }
    if (p != NULL && strcmp(p->str, srch) == 0)
        puts("Yes.");
}
void save(test5 *t)
{
    curpos.X = 0;
    curpos.Y = 8;
    SetConsoleCursorPosition(hout, curpos);
    int clear = 0;
    for (; clear < 20; clear++)
    {
        printf("                                                    \n");
    }
    curpos.X = 0;
    curpos.Y = 8;
    SetConsoleCursorPosition(hout, curpos);

    FILE *f;
    test5 *p = t;
    f = fopen("data", "w");
    for (; (p->next)->next != NULL; p = p->next)
        fprintf(f, "%s\n", p->str);
    fprintf(f, "%s", p->str); 
    //the  str of the last node is a \n
    fclose(f);
    puts("Saved.");
}
void read(test5 *t)
{
    curpos.X = 0;
    curpos.Y = 8;
    SetConsoleCursorPosition(hout, curpos);
    int clear = 0;
    for (; clear < 20; clear++)
    {
        printf("                                                    \n");
    }
    curpos.X = 0;
    curpos.Y = 8;
    SetConsoleCursorPosition(hout, curpos);

    FILE *f;
    test5 *p = t, *new;
    f = fopen("data", "r");
    for (; p->next != NULL; p = p->next)
        ;
    while (!feof(f))
    {
        new = (test5 *)malloc(sizeof(test5));
        fscanf(f, "%s", new->str);
        p->next = new;
        p = p->next; // p=new;
        puts("succeed.");
    }
    p->next=NULL;
    //puts("succeed end.");
    fclose(f);
}
