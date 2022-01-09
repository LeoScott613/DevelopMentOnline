// compile information:  gcc main.c jindu.c init.c get_date.c kb.c fbuffer.c
#include <stdio.h>
#include <windows.h>
#include <string.h>
#ifndef SCHED_L
#define SCHED_L

typedef struct _event
{
    int year;
    int month;
    int day;
    int hour;
    int min;
    char content[50];
    char place[50];
    struct _event *next;
} event_st;

CONSOLE_CURSOR_INFO cci;
CONSOLE_SCREEN_BUFFER_INFO csbi;
COORD pos;
SMALL_RECT sr;

//更新用的位置信息
COORD month_pos;
COORD list_pos[10];
COORD manual_pos;
COORD time_pos;

void init_draw(HANDLE);
void getdate();
void hide_cursor();
void show_cursor();
void jindu(HANDLE);
void kbevent();
void resetpro(COORD, COORD *, int *, int *);
void processor(COORD, COORD *, int *, int *); // the first time I try not passing the handle..
void newevent(COORD, int, int);
void lhxResetEvent();
COORD current_month();
event_st *buff();
static const char *welcome = "         ___     ___    ___    __                              ___     ___    ___    ___  \n        |__ \\   / _ \\  |__ \\  /_ |                            |__ \\   / _ \\  |__ \\  |__ \\ \n           ) | | | | |    ) |  | |  ______   ______   ______     ) | | | | |    ) |    ) |\n          / /  | | | |   / /   | | |______| |______| |______|   / /  | | | |   / /    / / \n         / /_  | |_| |  / /_   | |                             / /_  | |_| |  / /_   / /_ \n        |____|  \\___/  |____|  |_|                            |____|  \\___/  |____| |____|\n";

long int runtime;

#endif

/*
base64:
6L+Z5Lu96K++56iL6K6+6K6h5rqQ56CB5YWs5byA5ZyoaHR0cHM6Ly9naXRodWIuY29t
L0xlb1Njb3R0NjEzL0RldmVsb3BNZW50T25saW5lL3RyZWUvbWFzdGVyL1ZTQy9zY2hl
ZHVsZV9tYW5hZ2VtZW5044CC6K+05a6e6K+d77yM5ZyoY29uc29sZeWBmuS4gOS4qnVp
5pi+5b6X57Sv6LWY5LiU5LiN576O6KeC44CC54S26ICM5a+55LqO5aSn5LiA5paw55Sf
5p2l6K+077yM5YGa5LiA5Liq6L+Z56eN5LyqdWnnmoTnoa7mmK/nrKblkIjmiJHku6zn
moTog73lipvojIPlm7TjgILomb3nhLblvojlpJrmioDmnK/pg73msqHmnInkvb/nlKjl
iLDvvIzlvojlpJrnjrDlnKjnmoTmioDmnK/lnKjlrp7pmYXlt6XkvZzkuK3mmK/kvY7m
lYjnmoTlgZrms5XvvIzlroPku43nhLbmmK/miYDmnIljc+Wkp+S4gOaWsOeUn+eahOS4
gOS4que+juWlveeahOS9nOWTgeWQp+OAguavleern+Wug+WNoOeUqOS6huaIkeS7rOmC
o+S5iOWkmuaXtumXtO+8jOS4lOesrOS4gOasoeiuqeaIkeS7rOaOpeinpuWIsOS6huW3
peeoi+eahOeuoeeQhuWSjOaAnee7tA==
*/