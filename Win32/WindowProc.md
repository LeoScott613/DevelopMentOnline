The window procedure defines most of the behavior of the window, including reacting to the message. The window procedure is application-defined function, whose address must be included in the WNDCLASS of the window. As the target of message, it is called by DispatchMessage().  
## structure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);  

parameters:
* hwnd is a handle to the window.
* uMsg is the message code; for example, the WM_SIZE message indicates the window was resized.
* wParam and lParam contain additional data that pertains to the message. The exact meaning depends on the message code.

**LRESULT** is an integer value that your program returns to Windows. It contains your program's response to a particular message. The meaning of this value depends on the message code.   

**CALLBACK** is the calling convention for the function.  

## Illustation
Typically in window procedure, use switch-case statement to react to different messages. *If I have a more efficient way, I can also implement it.*  