#include <cstdio>
int main()
{
    char dig;
    int i,ans(0);
    for(i=0;i<8;i++)
    {
        dig = getchar();
        if(dig=='1')
            ans++;
    }
    putchar(ans+48);
    return 0;
}