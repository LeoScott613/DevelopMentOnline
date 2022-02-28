#include <iostream>
#include <cmath>
int main()
{
    int number;
    std::cin >> number;
    bool prime_ = true;
    for (int i(2); i <= sqrt(number); i++)
    {
        if (!(number % i))
            prime_ = false;
    }
    if (prime_)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    return 0;
}