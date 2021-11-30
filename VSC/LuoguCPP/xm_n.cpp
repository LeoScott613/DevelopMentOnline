#include <cmath>
#include <iostream>
int main()
{
    int m,n;
    std::cin>>n>>m;
    int i;
    for(i=1;pow(i,m)<=n;i++);
    std::cout<<i-1<<std::endl;
    return 0;
}