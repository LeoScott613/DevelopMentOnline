#include <iostream>
using namespace std;
int main()
{
    int n,pieces;
    cin>>n>>pieces;
    const int nn=n;
    int wood[nn],allup(0),i;
    for(i=0;i<nn;i++)
        cin>>wood[i];
    for(i=0;i<nn;i++)
        allup+=wood[i];
    cout<<allup/pieces<<endl;
    return 0;
}