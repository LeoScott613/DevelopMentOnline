#include <iostream>
int main()
{
    int a, b, c; //3 5 7
    std::cin >> a >> b >> c;
    int i;
    for (i = 10; i <= 100; i++)//pre-processing
        if (i % 3 == a && i % 5 == b && i % 7 == c)
            {
                std::cout<<i;
                return 0;
            }
    std::cout<<"No answer";
    return 0;
}