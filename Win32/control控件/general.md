The appearance, properties and so on of a common control are defined in window procedure and window class.  
## Init
To ensure include the necessary lib of certain control, use InitCommonControlsEx function in commctrl.h  
InitCommonControlsEx(*param*)  
the param: pointer to a **INITCOMMONCONTROLSEX** type varible  

```cpp
typedef struct tagINITCOMMONCONTROLSEX {
  DWORD dwSize;    //sizeof(itself)就好了
  DWORD dwICC;     //flags that indicate which common control classes will be loaded from the DLL
} INITCOMMONCONTROLSEX, *LPINITCOMMONCONTROLSEX;
```

## Create control
Use CreatWindowExA function to create controls (*controls are child window in essence*)  
```cpp
HWND CreateWindowExA(
  [in]           DWORD     dwExStyle,
  [in, optional] LPCSTR    lpClassName,
  [in, optional] LPCSTR    lpWindowName,
  [in]           DWORD     dwStyle,
  [in]           int       X,
  [in]           int       Y,
  [in]           int       nWidth,
  [in]           int       nHeight,
  [in, optional] HWND      hWndParent,
  [in, optional] HMENU     hMenu,
  [in, optional] HINSTANCE hInstance,
  [in, optional] LPVOID    lpParam
);
```
the "lpClassName" needs a window class of the control you want to create, which is predefined.  
|control|window class|
|---|---|
|button|WS_BUTTON|
|edit|WS_EDIT|
|combo box|WC_COMBOBOX|

## detail
创建一个控件的时候，如果指定了父句柄，那么坐标就是在父句柄中的相对坐标  