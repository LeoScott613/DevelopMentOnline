#include <iostream>
int main()
{
    int n, m;
    std::cin >> n >> m;
    int a[n+1], i;
    for (i = 0; i <= n; i++)
        a[i] = 0;
    for (i = 0; i < m; i++)
    {
        int x;
        std::cin >> x;
        a[x]++;
    }
    for (i = 0; i <= n; i++)
    {
        for(int j=0;j<a[i];j++)
            std::cout<<i<<' ';
    }
    return 0;
}