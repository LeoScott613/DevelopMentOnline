#include <iostream>
#include <string>
using namespace std;
int main()
{
    string ufo,group;
    cin>>ufo>>group;
    string::iterator iu,ig;
    int u(1),g(1);
    for(iu=ufo.begin();iu!=ufo.end();iu++)
        u*=*iu-'A'+1;
    for(ig=group.begin();ig!=group.end();ig++)
        g*=*ig-'A'+1;
    u%=47;
    g%=47;
    if(u==g)
        cout<<"GO";
    else cout<<"STAY";
    return 0;
}
