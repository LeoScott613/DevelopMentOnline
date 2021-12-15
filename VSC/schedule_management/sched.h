#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#ifndef SCHED_L
#define SCHED_L
CONSOLE_CURSOR_INFO cci;
CONSOLE_SCREEN_BUFFER_INFO csbi;
COORD pos;
SMALL_RECT sr;

void init_draw(HANDLE);
void getdate();
void hide_cursor(HANDLE);
static const char *welcome="  ___     ___    ___    __                              ___     ___    ___    ___  \n |__ \\   / _ \\  |__ \\  /_ |                            |__ \\   / _ \\  |__ \\  |__ \\ \n    ) | | | | |    ) |  | |  ______   ______   ______     ) | | | | |    ) |    ) |\n   / /  | | | |   / /   | | |______| |______| |______|   / /  | | | |   / /    / / \n  / /_  | |_| |  / /_   | |                             / /_  | |_| |  / /_   / /_ \n |____|  \\___/  |____|  |_|                            |____|  \\___/  |____| |____|\n";

//更新用的位置信息
COORD month_pos[31];
COORD list_pos[10];
COORD manual_pos[5];
COORD time_pos;
#endif
//" ____  ____  ____  _                    ____  ____  ____  ____ \n/_   \\/  _ \\/_   \\/ \\                  /_   \\/  _ \\/_   \\/_   \\ \n /   /| / \\| /   /| |_____ _____ _____  /   /| / \\| /   / /   /\n/   /_| \\_/|/   /_| |\\____\\____\\____\\/   /_| \\_/|/   /_/   /_\n\\____/\\____/\\____/\\_/                  \\____/\\____/\\____/\\____/";