/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    getchar();
    const int nn = n + 2, mm = m + 2;
    bool map[nn][mm];
    memset(map, 0, sizeof(map));
    int i, j;
    char mine;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            mine = getchar();
            if (mine == '*')
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
        getchar();
    }
    int calc = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (!map[i][j])
            {
                calc = map[i - 1][j - 1] + map[i - 1][j] + map[i - 1][j + 1] + map[i][j - 1] + map[i][j + 1] + map[i + 1][j - 1] + map[i + 1][j] + map[i + 1][j + 1];
                cout << calc;
                calc = 0;
            }
            else
                putchar('*');
        }
        putchar('\n');
    }
    return 0;
}
*/
// CORRECT ANSWER

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    getchar();
    const int nn(n + 2), mm(m + 2);
    bool map[nn][mm];
    memset(map, 0, sizeof(map));
    int i, j, ans(0);
    char point;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            point = getchar();
            if (point == '*')
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
        getchar();
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (!map[i][j])
                cout << map[i - 1][j - 1] + map[i - 1][j] + map[i - 1][j + 1] + map[i][j - 1] + map[i][j + 1] + map[i + 1][j - 1] + map[i + 1][j] + map[i + 1][j + 1];
            else
                putchar('*');
        }
    putchar('\n');
    }
    return 0;
}