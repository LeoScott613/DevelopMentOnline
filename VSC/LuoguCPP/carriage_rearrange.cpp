#include <iostream>
int pre[10000], n(0);
/*int pbub() // make smallest the tail
{
    int x(0);//times
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < i; j++)
            if (pre[j] < pre[j + 1])
            {
                std::swap(pre[j], pre[j + 1]);
                x++;
            }
    return x;
}*/
int nbub() // make the biggest the tail
{
    int x(0); // times
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < i; j++)
            if (pre[j] > pre[j + 1])
            {
                std::swap(pre[j], pre[j + 1]);
                x++;
            }
    return x;
}
int main()
{
    int i;
    std::cin >> n;
    for (i = 0; i < n; i++)
        std::cin >> pre[i];
    i = nbub();
    std::cout << i;
    return 0;
}