#include <cstring>
#include <iostream>
char a1[10001],b1[10001];
int a[10001],b[10001],c[10001],len;
using namespace std;
int main()
{
    cin>>a1>>b1;
    a[0]=strlen(a1);
    b[0]=strlen(b1);
    for(int i(1);i<=a[0];i++)
        a[i]=a1[a[0]-i]-'0';
    for(int i(1);i<=b[0];i++)
        b[i]=b1[b[0]-i]-'0';
    for(int i(1);i<=a[0];i++)
        for(int j(1);j<=b[0];j++)
            c[i+j-1]+=a[i]*b[j];
    len=a[0]+b[0];
    for(int i(1);i<len;i++)
        if(c[i]>9)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    while(c[len]==0&&len>1)
        len--;
    for(int i(len);i>=1;i--)
        cout<<c[i];
    return 0;
}