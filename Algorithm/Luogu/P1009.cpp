#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    string musum("1");
    vector<string> multi;
    for(int i(1);i<=n;i++)//multiply
    {    //musum*=i;
        string stri;
        int eat_i(i);
        while(eat_i)
        {
            stri=(char)(eat_i%10+'0')+stri;
            eat_i/=10;
        }
        //musum*=stri;
        vector<int> a,b,c;
        for(string::iterator is(musum.begin());is!=musum.end();is++)
            a.push_back(*is-'0');
        for(string::iterator is(stri.begin());is!=stri.end();is++)
            b.push_back(*is-'0');
        c.push_back(0);
        vector<int>::difference_type imove(0);
        for(vector<int>::iterator ia(a.end()-1),ic(c.begin());ia>=a.begin();ia--)
        {
            for(vector<int>::iterator ib(b.end()-1);ib>=b.begin();ib--)
            {
                *ic+=*ia**ib;
                if(ic==c.end()-1)
                {
                    c.push_back(0);
                    ic=c.end()-1;
                }
                else ic++;
            }
            imove++;
            ic=c.begin()+imove;
        }
        if(*(c.end()-1)==0&&c.end()!=c.begin()+1) 
            c.erase(c.end()-1);
        for(vector<int>::iterator ic(c.begin());ic!=c.end()-1;ic++)
            if(*ic>9)
            {
                *(ic+1)+=*ic/10;
                *ic%=10;
            }
        //musum=c;
        musum.clear();
        for(vector<int>::iterator ic(c.end()-1);ic>=c.begin();ic--)
        {
            if(*ic>9)
            {
                int ixi(*ic);
                *ic%=10;
                while(ixi)
                {
                    ixi/=10;
                    c.push_back(ixi%10);
                }
                ic=c.end()-1;
            }
            else musum.push_back(*ic+'0');
        }
        //cout<<musum<<' ';
        multi.push_back(musum);
    }
    //1!,2!,...,n! completed
    //1!+...+n!;
    string final,result("1");
    for(int i(1);i<n;i++)//addition
    {
        vector<string>::iterator imul(multi.begin()+i);
        //result+*imul;
        vector<int> a,b,t,m,c;
        vector<int>::iterator it,im,ic;
        for(string::iterator is((*imul).end()-1);is>=(*imul).begin();is--)
            a.push_back(*is-'0');
        for(string::iterator is(result.end()-1);is>=result.begin();is--)
            b.push_back(*is-'0');
        t=(a.size()<b.size())?a:b;
        m=(a.size()<b.size())?b:a;
        while(t.size()<m.size())
            t.push_back(0);
        for(it=t.begin(),im=m.begin();it!=t.end();it++,im++)
            c.push_back(*it+*im);
        for(ic=c.begin();ic!=c.end()-1;ic++)
            if(*ic>9)
            {
                *(ic+1)+=*ic/10;
                *ic%=10;
            }
        if(*ic>9)
        {
            c.push_back(*ic/10);
            *(c.end()-2)%=10;
        }
        result.clear();
        for(ic=c.end()-1;ic>=c.begin();ic--)
            result.push_back(*ic+'0');
    }
    cout<<result<<endl;
    return 0;
}