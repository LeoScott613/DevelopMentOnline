#include <iostream>
#include <vector>
int input()
{
    int x;
    std::cin >> x;
    return x;
}
int main()
{
    std::vector<int> a; //vector is in std scope
    int n;              //times
    std::cin >> n;      //remember to input times
    int i, j;
    for (i = 0; i < n; i++)
        a.push_back(input());
    for (i = a.size() - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (a[j] > a[j + 1]) //condition is j+1<j    //but if you "reverse" the order,it's j+1>j
                std::swap(a[j], a[j + 1]);
    for (i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    return 0;
}