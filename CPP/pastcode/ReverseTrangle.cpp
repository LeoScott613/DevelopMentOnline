#include <iostream>
using namespace std;
int main()
{
    int n,i,j,space(0);
    cin>>n;
    int star=2*n-1;
    for(i=n;i>0;i--)
    {
        for(j=0;j<space;j++)
        cout<<' ';
        for(j=0;j<star;j++)
        cout<<'#';
        cout<<endl;
        space++;
        star-=2;
    }
    return 0;
}