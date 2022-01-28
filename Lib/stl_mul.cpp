#include <string>
#include <vector>
#include <iostream>
using namespace std;
const string test("succeed!");
int main()
{
    ios::sync_with_stdio(false);
    string m1,m2;
    cin>>m1>>m2;
    string::iterator i1(m1.begin()),i2(m2.begin());
    vector<int> mul1,mul2,result;
    result.push_back(0);
    for(;i1!=m1.end();i1++)
        mul1.push_back(*i1-'0');
    for(;i2!=m2.end();i2++)
        mul2.push_back(*i2-'0');
    vector<int>::iterator imul1(mul1.end()-1),imul2(mul2.end()-1),ir(result.begin());
    vector<int>::difference_type i(0);
    for(;imul1>=mul1.begin();imul1--)
    {
        for(imul2=mul2.end()-1;imul2>=mul2.begin();imul2--)
        {
            *ir+=*imul1**imul2;
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
    cout<<endl;
    return 0;
}