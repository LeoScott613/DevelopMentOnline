#include <iostream>
#include <set>
using namespace std;
typedef set<int>::iterator sti;
int main()
{
    set<char> kid;
    string child="helloworld";
    string::iterator ic=child.begin();
    for(;ic!=child.end();ic++)
        kid.insert(*ic);
    cout<<*(kid.begin())<<endl;
    return 0;
}