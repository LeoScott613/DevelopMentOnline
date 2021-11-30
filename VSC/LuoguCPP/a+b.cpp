#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int addition(string str1,string str2)
{
    string::iterator fo1(str1.begin()),fo2(str2.begin());
    string sumup;
    while(fo1!=str1.end()||fo2!=str2.end())
    {
        *fo1+*fo2;
    }
}
int main()
{
    string ad1,ad2,sum;
    cin>>ad1>>ad2;


}