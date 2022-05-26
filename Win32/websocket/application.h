#ifndef LHXAPP
#define LHXAPP
#include <windows.h>
#include <tchar.h>
#include <commctrl.h>
typedef struct pos {
    int x;
    int y;
    int width;
    int height;
}pos;
LRESULT CALLBACK procit(HWND hand,UINT msg,WPARAM wp,LPARAM lp);
#endif