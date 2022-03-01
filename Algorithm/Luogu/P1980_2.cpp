#include <iostream>
using namespace std;
int main()
{
    int backup(0);
    int n, search,count(0);
    cin>>n>>search;
    for(int i(1);i<=n;i++)
    {
        backup=i;
        while(backup>0)
        {
            int drag=backup%10;
            if(drag==search)
                count++;
            backup/=10;
        }
    }
    cout<<count<<endl;
    return 0;
}