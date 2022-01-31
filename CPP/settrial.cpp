#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int main()
{
    string s;
    set<string> se;    
    while(true)
    {
        cin>>s;
        if(s=="exit") break;
        se.insert(s);
    }
    for(set<string>::iterator is(se.begin());is!=se.end();is++)
        cout<<*is<<' ';
    cout<<endl;
    return 0;
}