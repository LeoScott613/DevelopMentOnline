#include <bits/stdc++.h>
using namespace std;
bool minemap[102][102];
int main()
{
    memset(minemap, 0, sizeof(minemap));
    int line, column;
    char step;
    cin >> line >> column;
    for (int i = 1; i <= line; i++)
    {
        for (int j(1); j <= column; j++)
        {
            cin >> step;
            if (step == '*')
                minemap[i][j] = 1;
        }
    }
    for (int i(1); i <= line; i++)
    {
        for (int j(1); j <= column; j++)
        {
            if (minemap[i][j] != 1)
                cout << minemap[i - 1][j - 1] + minemap[i - 1][j] + minemap[i - 1][j + 1] + minemap[i][j - 1] + minemap[i][j + 1] + minemap[i + 1][j - 1] + minemap[i + 1][j] + minemap[i + 1][j + 1];
            else
                cout << '*';
        }
        cout << endl;
    }
    return 0;
}