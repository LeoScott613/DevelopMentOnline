#include <iostream>
#include <cmath>
int main()
{
    int n, d, i;
    std::cin >> n >> d;
    int *p = new int[n];
    for (i = 0; i < n; i++)
        std::cin >> p[i];
    for (i = n - 1; i >= 0; i--)
        for (int j = 0; j < i; j++)
            if (p[j] > p[j + 1])
                std::swap(p[j], p[j + 1]);
    int pair = 0;
    for (i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (abs(p[i] - p[j]) <= d)
                pair++;
    std::cout << pair << std::endl;
    delete[] p;
    return 0;
}