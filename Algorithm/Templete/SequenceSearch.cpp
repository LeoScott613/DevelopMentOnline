#include <iostream>
#include <vector>
int ss(int a[], int k, int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == k)
            return i;
    return -1;
}
std::vector<int>::iterator ssv(std::vector<int>::iterator a, int k, std::vector<int>::iterator n)
{
    // a for .begin(),n for .end()
    for (; a != n; a++)
        if (*a == k)
            return a;
    return n;
}
int main()
{
    int abc[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::vector<int> ssvec;
    for (int j = 0; j < 10; j++)
        ssvec.push_back(j);
    int where = ss(abc, 5, 10);
    std::vector<int>::iterator wherev = ssv(ssvec.begin(), 5, ssvec.end());
    std::cout << abc[where] << "+" << *wherev << std::endl;
    return 0;
}