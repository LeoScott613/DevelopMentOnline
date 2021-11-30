#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x[1001],n;
    cin>>n;
    int i,a;
    memset(x,0,sizeof(x));
    for(i=1;i<=n;i++)
    {
        cin>>a;
        x[a]++;
    }
    int times(0);
    for(i=1;i<=1000;i++)
        if(x[i]!=0)
            //cout<<x[i]<<' ';
            times++;
    cout<<times<<endl;
    for(i=1;i<=1000;i++)
        if(x[i]!=0)
            cout<<i<<' ';
    return 0;
}