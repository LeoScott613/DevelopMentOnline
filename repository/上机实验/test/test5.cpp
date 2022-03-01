#include <bits/stdc++.h>
using namespace std;
int main()
{
    int layer, i;
    cin >> layer;
    int last = layer % 2;
    for (i = 1; i <= layer / 2; i++)
    {
        for (int t = 0; t < layer / 2 - i + last; t++)
            cout << ' ';
        for (int j = 0; j < 2 * i - 1; j++)
            cout << '*';
        cout << endl;
    }
    for (; i >= 1; i--)
    {
        for (int t = 0; t < layer / 2 - i + last; t++)
            cout << ' ';
        for (int j = 0; j < 2 * i - 1; j++)
            cout << '*';
        cout << endl;
    }
    system("pause");
    return 0;
}