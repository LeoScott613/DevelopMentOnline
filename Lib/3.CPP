#include <iostream>
int main()
{
    int b(1),c(1),a;
    a=b+++(++c);
    std::cout<<a<<std::endl;
    return 0;
}