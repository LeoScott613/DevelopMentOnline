# Windows.h !  
windows.h�ں����windowsϵ��ͷ�ļ�������wincon.h��windef.h�Ⱥܶ�
��������꣬windows data type����׼��������豸    
**����**  
typedef unsigned short WORD  
typedef DWORD  
HANDLE  
WORD

**�ṹ������**  
CONSOLE_SCREEN_BUFFER_INFO  
COORD  
SMALL_RECT  
CHAR_INFO  
INPUT_RECORD

**�������**  
STD_OUTPUT_HANDLE  
��ȡ��ʾ������ϢGetConsoleScreenBufferInfo(*handle*,*\*CONSOLE_SCREEN_BUFFER_INFOR*),������Ϣ�洢���˽ṹ������CONSOLE_SCREEN_BUFFER_INFO����ı�����  
*��ʾ�������֪ʶ�ο���һ���ʼ�*  
STD_INPUT_HANDLE
  
������Ӻ�����Ĺرջᵼ���������̵ľ�������ر�
**API**   
SetTextAttribute(*HANDLE*,*WORD*); �����ı�������  
>�ı�����:��ɫ  
FOREGROUND_��BACKGROUND_ǰ׺ָ��������ɫ�ͱ���ɫ����ͬ��ɫ���Ի�ϣ���ɫ��׺������:_RED,_BLUE,_GREEN,_INTENSITY,��ϲ�ͬ��ɫʹ��|������
SetConsoleCursorPosition(*HANDLE*,*COORD*);����ָ��λ���ã�����ָ��꣩  
ReadConsoleInput(*HANDLE*,*INPUT_RECORD*,*DWORD*,*LPDWORD*);��ȡ�����¼�
