#include <iostream>
int main()
{
    int *p = new int[10];
    int i, hand;
    for (i = 0; i < 10; i++)
        std::cin >> p[i];
    int count(0);
    std::cin>>hand;
    hand+=30;
    for(i=0;i<10;i++)
    if(hand>=p[i])
    count++;
    std::cout<<count;
    delete[] p;
    return 0;
}