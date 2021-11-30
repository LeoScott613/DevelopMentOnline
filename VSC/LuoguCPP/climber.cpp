#include <iostream>
#include <cmath>
#include <iomanip>
int main()
{
    int n;
    std::cin >> n;
    const int cn = 3 * n;
    double points[cn];
    int i, j;
    for (i = 0; i < cn; i++)
        std::cin >> points[i];
    for (i = cn - 3; i > 0; i -= 3)
        for (j = 2; j < i; j += 3)
            if (points[j] > points[j + 3])
            {
                std::swap(points[j], points[j + 3]);
                std::swap(points[j - 1], points[j + 2]);
                std::swap(points[j - 2], points[j + 1]);
            }
    double sum = 0;
    for (i = 2; i < cn - 3; i += 3)
        sum += sqrt(pow(points[i - 2] - points[i + 1], 2) + pow(points[i - 1] - points[i + 2], 2) + pow(points[i] - points[i + 3], 2));
    std::cout << std::fixed<<std::setprecision(3)<<sum;
    return 0;
}