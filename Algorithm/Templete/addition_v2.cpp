#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    string s1,s2;
    string::iterator is;
    vector<int> a,b,t,m,result;
    vector<int>::iterator ir,it,im;
    cin>>s1>>s2;
    for(is=s1.end()-1;is>=s1.begin();is--)
        a.push_back(*is-'0');
    for(is=s2.end()-1;is>=s2.begin();is--)
        b.push_back(*is-'0');
    t=(a.size()<b.size())?a:b;
    m=(a.size()<b.size())?b:a;
    while(t.size()<m.size())
        t.push_back(0);
    for(it=t.begin(),im=m.begin();it!=t.end();it++,im++)
        result.push_back(*it+*im);
    for(ir=result.begin();ir!=result.end()-1;ir++)
        if(*ir>9)
        {
            *(ir+1)+=*ir/10;
            *ir%=10;
        }
    if(*ir==0) result.erase(ir);
    for(ir=result.end()-1;ir>=result.begin();ir--)
        cout<<*ir;
    return 0;
}