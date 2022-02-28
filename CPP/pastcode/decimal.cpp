#include <iostream>
#include <iomanip>
int main()
{
    double a,b;
    int c;
    while(1)
    {
        std::cin>>a>>b>>c;
        if(a==0&&b==0&&c==0)
        break;
        std::cout<<std::fixed<<std::setprecision(c)<<a/b<<std::endl;
    }
    return 0;
}