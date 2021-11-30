#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    const int nn(n);
    bool coin[nn];
    memset(coin, true, sizeof(coin));
    cout << nn << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            else
                coin[j] = !coin[j];
        }
        for (int j = 0; j < n; j++)
        {
            if (coin[j])
                cout << 0;
            else
                cout << 1;
        }
        cout << endl;
    }
    return 0;
}