#include <iostream>
int main()
{
    unsigned int n;
    std::cin>>n;
    unsigned int reversed(0);
    while(n)
    {
        reversed*=10;
        reversed+=n%10;
        n/=10;
    }
    std::cout<<reversed<<std::endl;
    return 0;
}