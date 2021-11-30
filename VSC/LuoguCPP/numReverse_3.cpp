#include <iostream>
int main()
{
    int n, sgn=1;
    std::cin >> n;
    if (n < 0)
    {
        sgn = -1;
        n *= sgn;
    }
    int reverse(0),d;
    //core---
    while(n>0){
        d=n%10;
        reverse=reverse*10+d;
        n/=10;
    }
    //core---
    reverse*=sgn;
    std::cout<<reverse;
    return 0;
}