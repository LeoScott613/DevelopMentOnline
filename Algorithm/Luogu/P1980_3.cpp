#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    int n;
    char search;
    cin>>n>>search;
    stringstream livestr;
    for(int i(1);i<=n;i++)
        livestr<<i;
    string line(livestr.str());
    cout<<count(line.begin(),line.end(),search)<<endl;
    return 0;
}