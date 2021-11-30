#include <iostream>
#include <cmath>
int main()
{
    int n;
    std::cin >> n;
    const int cn = n;
    int inpu[cn], i;
    for (i = 0; i < n; i++)
    {
        std::cin >> inpu[i];
    }
    int ctingsort[cn];
    for (i = 0; i < n; i++)
        ctingsort[i] = 0;
    int p;
    for (i = 0; i < n - 1; i++)
    {
        p = abs(inpu[i] - inpu[i + 1]);
        if (p < n && p)
            ctingsort[p]++;
        else
            {
                std::cout<<"Not jolly";
                return 0;
            }
    }
    for(i=1;i<n;i++)
    if(!ctingsort[i])
    {
        std::cout<<"Not jolly";
        return 0;
    }
    std::cout<<"Jolly";
    return 0;
}