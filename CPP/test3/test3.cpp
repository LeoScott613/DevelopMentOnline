#include <iostream>
using namespace std;
char const addsig = '+', equalsig = '=';
int recursion(int num)
{
    static int sum;
    if (num >= 1)
        sum = num + recursion(num - 1);
    int i(1);
    for (; i < num; i++)
        cout << i << addsig;
    if (i > 1)
        cout << i << equalsig << sum << endl;
    return sum;
}
int main()
{
    int n;
    cin >> n;
    /*cout <<*/ recursion(n);
    return 0;
}