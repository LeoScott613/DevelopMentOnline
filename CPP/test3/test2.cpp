#include <iostream>
#include <string>
using namespace std;
char const addsig = '+', equalsig='=';
int recursion(int num)
{
    /*static*/ int sum;
    if (num >= 1)
        sum = num + recursion(num - 1);
    int i(1);
    for (; i < num; i++)
        cout << i << addsig;
    cout << i << equalsig << sum << endl;
    //cout << sum << endl;
    return sum;
}
int main()
{
    int n;
    cin >> n;
    recursion(n);
    return 0;
}