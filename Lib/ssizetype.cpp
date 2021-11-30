#include <string>
#include <iostream>
int main()
{
    std::string abc;
    std::cin >> abc;
    if (abc.empty())
        return 0;
    std::string::size_type sizabc = abc.size();
    std::cout << sizabc << std::endl;
    return 0;
}