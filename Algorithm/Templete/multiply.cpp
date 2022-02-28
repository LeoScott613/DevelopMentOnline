#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    string s1,s2;
    vector<int> mul1,mul2,result;
    vector<int>::iterator i1,i2;
    string::iterator is;
    cin>>s1>>s2;
    for(is=s1.begin();is!=s1.end();is++)
        mul1.push_back(*is-'0');
    for(is=s2.begin();is!=s2.end();is++)
        mul2.push_back(*is-'0');
    i1=mul1.end()-1;
    i2=mul2.end()-1;
    result.push_back(0);
    vector<int>::iterator ir(result.begin());
    for(vector<int>::difference_type i(0);i1>=mul1.begin();i1--)
    {
        for(i2=mul2.end()-1;i2>=mul2.begin();i2--)
        {
            *ir+=*i1**i2;
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
    for(ir=result.end()-1;*ir==0&&ir!=result.begin();ir--)
        ir=result.erase(ir);
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
