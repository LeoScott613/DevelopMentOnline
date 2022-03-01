#include <iostream>
#include <cstdio>
//using namespace std;
int main()
{
    int lowcase(0),number(0),capital(0),other(0);
    for(int i=0;i<10;i++)
    {
        char c;
        scanf("%c",&c);
        if(/*小写字母的ASCII范围*/)
            lowcase++;
        else if(/*大写字母的范围*/)
            capital++;
        else if(/*数字的*/)
            number++;
        else
            other++;
    }
    printf("/*输出就完事了*/");
    return 0;
}