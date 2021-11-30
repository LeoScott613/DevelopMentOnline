#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int_64;
int main()
{
    int_64 num(1), sum(0), midsum(1);
    for (int i(1); i <= 20; i++)
    {
        for (int j(1); j <= i; j++)
            midsum *= j;
        cout << i << "!=" << midsum << endl;
        sum += midsum;
        midsum = 1;
    }
    cout << "1!+2!+3!...+20!=" << sum << endl;
    system("pause");
    return 0;
}