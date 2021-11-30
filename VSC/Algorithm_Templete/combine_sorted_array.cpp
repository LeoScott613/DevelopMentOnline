#include <iostream>
using namespace std;
int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6}, b[8] = {2, 5, 17, 18, 18, 18, 19, 31};
    int combination[14];
    int i(0), j(0), k(0);
    while (i < 14)
    {
        if (k > 7 || a[j] <= b[k])
            combination[i++] = a[j++];
        else if (j > 5 || b[k] < a[j])
            combination[i++] = b[k++];
    }
    for (i = 0; i < 14; i++)
        cout << combination[i] << ' ';
    return 0;
}