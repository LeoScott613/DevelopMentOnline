#include <stdio.h>
#include <windows.h>
int main()
{
    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE); //��ñ�׼�����豸���
    INPUT_RECORD keyrec;                               //���������¼��ṹ��
    DWORD res;                                         //���巵�ؼ�¼
    for (;;)
    {
        ReadConsoleInput(handle_in, &keyrec, 1, &res); //��ȡ�����¼�
        if (keyrec.EventType == KEY_EVENT&&keyrec.Event.KeyEvent.bKeyDown)             //�����ǰ�¼��Ǽ����¼�
        {
            //if (keyrec.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) //��ǰ�¼��������ΪEsc��
            //{
                printf("Esc ");
            //}
        }
    }
    return 0;
}