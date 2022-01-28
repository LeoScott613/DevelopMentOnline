#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string s1,s2;
    char sig;
    cout<<"line by line"<<endl;
    cin>>s1>>sig>>s2;
    string::iterator is;
    vector<int> a,b,t,m,result;
    vector<int>::iterator ir,it,im;
    for(is=s1.end()-1;is>=s1.begin();is--)
        a.push_back(*is-'0');
    for(is=s2.end()-1;is>=s2.begin();is--)
        b.push_back(*is-'0');
    if(sig=='+')
    {
        t=(a.size()<b.size())?a:b;
        m=(a.size()<b.size())?b:a;
        while(t.size()<m.size())
            t.push_back(0);
        for(it=t.begin(),im=m.begin();it!=t.end();it++,im++)
            result.push_back(*it+*im);
    }
    else if(sig=='x')
    {
        result.push_back(0);
        ir=result.begin();
        vector<int>::difference_type i(0);
        for(it=a.begin();it!=a.end();it++)
        {
            for(im=b.begin();im!=b.end();im++)
            {
                *ir+=*it**im;
                if(ir==result.end()-1)
                {
                    result.push_back(0);
                    ir=result.end()-1;
                }
                else ir++;
            }
            i++;
            ir=result.begin()+i;
        }
    }
    else 
    {
        cout<<"error"<<endl;
        return -1;
    }
    for(ir=result.end()-1;*ir==0;ir--)
        ir=result.erase(ir)-1;
    for(ir=result.begin();ir!=result.end()-1;ir++)
        if(*ir>9)
        {
            *(ir+1)+=*ir/10;
            *ir%=10;
        }
    for(ir=result.end()-1;ir>=result.begin();ir--)
        cout<<*ir;
    return 0;
}
