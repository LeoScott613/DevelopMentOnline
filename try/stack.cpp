#include <iostream>
#include <stack>
#include <set>
using namespace std;
int input()
{
    int x;
    cin >> x;
    return x;
}
int main()
{
    set<int> est,ste;
    stack<set<int> > ss;
    for (int i(0); i < 3; i++)
        est.insert(input());
    for(int i(0);i<3;i++)
        ste.insert(input());
    ss.push(est);
    ss.push(ste);
    cout<<*(ss.top().begin())<<endl;
    ss.pop();
    cout<<*(ss.top().begin())<<endl;
    return 0;
}