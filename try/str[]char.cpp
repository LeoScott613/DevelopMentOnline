#include <iostream>
int main()
{
    while (1)
    {
        char *p[10] = {"ling ", "yi ", "er ", "san ", "si ", "wu ", "liu ", "qi ", "ba ", "jiu "};//can't be used in cpp
        int n;
        std::cin >> n;
        std::cout << p[n];
        return 0;
    }
}