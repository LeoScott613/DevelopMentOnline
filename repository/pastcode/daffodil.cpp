#include <iostream>
#include <cmath>
int dafo(int in)
{
    int x;
    x = pow(in / 100, 3) + pow((in / 10) % 10, 3) + pow(in % 10, 3); //wanna get the last num? %10!Not %100
    return x;
}
int main()
{
    //std::cout<<pow(153 / 100, 3) + pow((153 / 10) % 10, 3) /*+ pow(153 % 100, 3)*/<<std::endl;
    //std::cout << dafo(153) << std::endl;
    for (int i = 100; i <= 999; i++)
        if (i == dafo(i))
            std::cout << i << " ";
    return 0;
}