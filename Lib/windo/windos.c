#include <stdio.h>
#include <windows.h>
#include <conio.h>
int main(int argc,char* argv[])
{
    HANDLE hando=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO sc;
    GetConsoleScreenBufferInfo(hando,&sc);
    COORD pos={3,0};
    SetConsoleTitle("LOoK here!");
    //FillConsoleOutputCharacter(hando,'L',sc.dwSize.X*sc.dwSize.Y,pos,NULL);
    getch();
    //FillConsoleOutputCharacter(hando,'?',30,pos,NULL);
    SetConsoleTextAttribute(hando,BACKGROUND_BLUE);
    puts("ok!");
    DWORD length=10;
    FillConsoleOutputCharacter(hando,'?',length,pos,NULL);
    Sleep(5000);
    

    CloseHandle(hando);
    puts("done");
    Sleep(5000);
    
    return 0;
}