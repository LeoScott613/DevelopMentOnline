#include "application.h"
int butt;
LRESULT CALLBACK procit(HWND hand,UINT msg,WPARAM wp,LPARAM lp) {
    switch(msg) {
        case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

        case WM_PAINT: {//important
            HBITMAP hbm;
            BITMAP  bminfo;
            hbm =(HBITMAP)LoadImage(NULL,_T("/uwp_bg.bmp"),IMAGE_BITMAP,6016,6016,LR_LOADFROMFILE);
            GetObject(hbm, sizeof(bminfo), &bminfo);
            
            PAINTSTRUCT ps;
            HDC dc = BeginPaint(hand, &ps);
            
            HDC memdc = CreateCompatibleDC(dc);
            
            SelectObject(memdc, hbm);
            BitBlt(dc,0,0,bminfo.bmWidth,bminfo.bmHeight,memdc,0,0,SRCCOPY);
            
            DeleteDC(memdc);
            
            EndPaint(hand, &ps);
        }
        return 0;

        case WM_COMMAND: {
            int cdnc=HIWORD(wp);
            int idfier=LOWORD(wp);
            if(cdnc==BN_CLICKED) {//when clicked
                butt=114;
            }
        }
        return 0;
    }
    return DefWindowProc(hand, msg, wp, lp);
}