#include <string>
#include <iostream>
using namespace std;
const string test("test, succeed!");
string add(string a,string b)
{
    if(a.length()<b.length())
        while(a.length()<b.length())
            a='0'+a;
    else if(a.length()>b.length())
        while(a.length()>b.length())
            b='0'+b;
    string::iterator ia(a.begin()),ib(b.begin());
    for(;ia!=a.end();ia++)
        *ia-='0';
    for(;ib!=b.end();ib++)
        *ib-='0';
    string result;
    for(ia=a.end()-1,ib=b.end()-1;ia!=a.begin();ia--,ib--)
        result=(char)(*ia+*ib)+result;
    result=(char)(*ia+*ib)+result;
    string::iterator ri(result.end()-1);
    for(;ri!=result.begin();ri--)
        if(*ri>9)
        {
            *(ri-1)=*ri/10;
            *ri%=10;
        }
    char shouwei;
    if(*ri>9)
    {
        shouwei=*ri/10;
        *ri%=10;
        result=shouwei+result;
    }
    for(ri=result.begin();ri!=result.end();ri++)
        *ri+='0';
    return result;
}
int main()
{
    cout<<add("0","00")<<endl;
    return 0;
}