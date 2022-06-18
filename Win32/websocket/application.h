#ifndef LHXAPP
#define LHXAPP
#pragma comment(lib,"comctl32.lib")  //for loading the lib
#pragma comment(lib,"ws2_32.lib")  //using windows socket 2 for network programming
#pragma comment(lib,"gdi32.lib")
#include <windows.h>
#include <tchar.h>
#include <commctrl.h>
#include <windowsx.h>
#include <stdio.h>
typedef struct pos {
    int x;
    int y;
    int width;
    int height;
}pos;
LRESULT CALLBACK procit(HWND hand,UINT msg,WPARAM wp,LPARAM lp);
#endif