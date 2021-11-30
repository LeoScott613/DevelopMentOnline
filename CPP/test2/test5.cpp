#include "graph_cus.h"//包含所有十进制数字的字符串图像原码
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
const clock_t delay(10*CLOCKS_PER_SEC);
int main()
{
    char a,b;
    cin>>a>>b;
    system("cls");
    string left,right;
    left=switch_str(a);
    right=switch_str(b);
    int i,j,k(0);
    while(k<=64)
    {
        for(i=k;i<8+k;i++)//每输出了一个数8个字符就输出另一个数的8个字符保证它们在同一行
            cout<<left[i];
        cout<<"  ";
        for(j=k;j<8+k;j++)
            cout<<right[j];
        k+=8;
        cout<<endl;
    }
    cout<<"input num:"<<a<<b<<endl;
    clock_t start(clock());
    while(clock()-start<delay);//sleep 10s
    return 0;
}