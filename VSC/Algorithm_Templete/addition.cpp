#include <string>
#include <iostream>
using namespace std;
string add(string ad1, string ad2)
{
    if (ad1.length() < ad2.length())
        while (ad1.length() < ad2.length())
            ad1 = '0' + ad1;
    else
        while (ad1.length() > ad2.length())
            ad2 = '0' + ad2;
    //duiqi
    string result;
    string::iterator one(ad1.end()), two(ad2.end()), r(result.begin());
    char digit_r, next(0);
    char &dr = digit_r, &nt = next;
    for (one--, two--; one >= ad1.begin(); one--, two--)
    {
        dr = *one - '0' + *two - '0';
        result = dr + result;
    }
    for (r = result.end() - 1; r != result.begin(); r--)
    {
        if (*r > 9)
            *(r - 1) += *r / 10,
                  *r %= 10;
    }
    if (*r > 9)
    {
        char temp = *r / 10;
        *r %= 10;
        result = temp + result;
    }
    for(r=result.begin();r!=result.end();r++)
        *r+='0';
    return result;
}
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<add(a,b);
    return 0;
}