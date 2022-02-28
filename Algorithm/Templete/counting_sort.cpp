#include <iostream>
#include <vector>
//n means the types of the number, m means the number of overall data.
int main()
{
    int n, m;
    std::cin >> n >> m;
    int a[n + 1]; //Most of the data is begin as 1.
    int i, j, x;
    for (i = 0; i <= n; i++)
    {
        a[i] = 0; //initialize
    }
    for (i = 0; i < m; i++)
    {
        std::cin >> x;
        a[x]++;     //core of counting sort
    }
    for (i = 1; i <= n; i++) //i=1 is uncertain
        for (j = 0; j < a[i]; j++)
            std::cout<<i<<" "; //remember it's outputing the index i rather than a[i]!!
    std::cout<<std::endl;
    return 0;
}