#include <iostream>
using namespace std;
int main()
{
    int presort[10] = {7, 6, 3, 9, 4, 2, 1, 5, 0, 8};
    for (int *i(presort + 9); i != presort; i--)
        for (int *j(presort); j < i; j++)
            if (*j > *(j + 1))
                swap(*j, *(j + 1));
    cout << "sorted array:";
    for (int i(0); i < 10; i++)
        cout << *(presort + i) << ' ';
    return 0;
}