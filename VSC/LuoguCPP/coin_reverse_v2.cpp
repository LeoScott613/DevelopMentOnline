#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool *coinline = new bool[1000001];
    int i = 0, times(0);
    memset(coinline, false, sizeof(coinline));
    for (char c = '?'; c != '\n'; i++)
    {
        c = getchar();
        if (c == '1')
            coinline[i] = true;
        else if (c == '0')
            coinline[i] = false;
    }
    for (i -= 2; i >= 0; i--)
    {
        if (!coinline[i])
        {
            for (int j = i; j >= 0; j--)
                coinline[j] = !coinline[j];
            times++;
        }
    }
    delete[] coinline;
    cout << times;
    return 0;
}