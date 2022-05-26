#include "application.h"
LRESULT CALLBACK procit(HWND hand,UINT msg,WPARAM wp,LPARAM lp) {
    switch(msg) {
        case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

        case WM_PAINT: {//important
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hand, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW));

            EndPaint(hand, &ps);
        }
        return 0;
    }
    return DefWindowProc(hand, msg, wp, lp);
}