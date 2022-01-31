#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<int> a,b,c;
    for(string::iterator is(s1.begin());is!=s1.end();is++)
        a.push_back(*is-'0');
    for(string::iterator is(s2.begin());is!=s2.end();is++)
        b.push_back(*is-'0');
    c.push_back(0);
    vector<int>::iterator ia,ib,ic(c.begin());
    vector<int>::difference_type i(0);
    for(ia=a.end()-1;ia>=a.begin();ia--)
    {
        for(ib=b.end()-1;ib>=b.begin();ib--)
        {
            *ic+=*ia**ib;
            if(ic==c.end()-1)
            {
                c.push_back(0);
                ic=c.end()-1;
            }
            else ic++;
        }
        i++;
        ic=c.begin()+i;
    }
    for(ic=c.end()-1;*ic==0&&ic!=c.begin();ic--)
        ic=c.erase(ic);
    for(ic=c.begin();ic!=c.end()-1;ic++)
        if(*ic>9)
        {
            *(ic+1)+=*ic/10;
            *ic%=10;
        }
    for(ic=c.end()-1;ic>=c.begin();ic--)
        cout<<*ic;
    return 0;
}
