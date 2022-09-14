#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // Add your code here
    int a[10];
    int n = 10;
    long level = 1;
    for (int i(1); i <= n; i++)
    {
        level *= i;
        long res = level * pow(2, i);
        if(res>2100000000)
            return -1;
        a[i - 1] = res;
    }
    for(int i(0);i<n;i++)
        cout<<a[i]<<endl;;
    return 0;
}