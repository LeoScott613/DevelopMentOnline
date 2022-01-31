#include <set>
#include <vector>
#include <iostream>
using namespace std;
//non-repeaty sort by using set
int input()
{
    int x;
    cin>>x;
    return x;
}
int main()
{
    int x(0);
    set<int> s;
    while(true)
    {
        x=input();
        if(x==-1) break;
        s.insert(x);
    }
    for(set<int>::iterator is(s.begin());is!=s.end();is++)
        cout<<*is<<' ';
    cout<<endl;
    return 0;
}