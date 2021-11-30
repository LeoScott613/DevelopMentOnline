#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int cs[10],i;
    for (i = 0; i < 10; i++)
        cs[i] = 0;
    for (i = n; i <= m; i++)
    {
        int qushu = i;
        while (qushu != 0)
        {
            cs[qushu % 10] += 1;
            qushu/=10;
        }
    }
    for(i=0;i<10;i++)
        cout<<cs[i]<<' ';
    return 0;        
}