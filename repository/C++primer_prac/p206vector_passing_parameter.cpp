#include <iostream>
#include <vector>
using namespace std;
int main()
{
    bool sear(vector<int>::const_iterator,vector<int>::const_iterator,int);
    vector<int> line;
    int x;
    while(1)
    {
        cin>>x;
        if(x!=0)
            line.push_back(x);
        else break;
    }
    cin>>x;
    bool ef=sear(line.begin(),line.end(),x);
    if(ef)
        cout<<"existed"<<endl;
    else
        cout<<"not here"<<endl;
    return 0;
}
bool sear(vector<int>::const_iterator v,vector<int>::const_iterator e,int what)
{
    while(*v!=what)
    {
        v++;
        if(v==e)
            return false;
    }
    return true;
}