#include <iostream>
using namespace std;
int recursion(int num)
{
    /*static*/ int sum;
    if (num >= 1)
        sum = num + recursion(num - 1);
    // cout<<sum<<' ';
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << recursion(n);
    return 0;
}