#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int len_a, len_b(1), len_c(1), len_ans;
    int i, n, p, m(1);
    int a[100], b[100], c[100], f[100];
    b[0] = 1;
    cin >> n;
    memset(c, 0, sizeof(c));
    for (i = 1; i <= n; i++)
    {
        len_a = 0;
        p = i;
        while (p > 0)
        {
            a[len_a++] = p % 10;
            p /= 10;
        }
        for (int j = 0; j < len_a; j++)
            for (int k = 0; k <= len_b; k++)
                c[j + k] += a[j] * b[k];
        for (int j = 0; j < len_c; j++)
            if (c[j] > 9)
                c[j + 1] += c[j] / 10,
                    c[j] %= 10; // even the max is two-digit number.
        if (c[len_c])
            len_c++;
        len_ans = len_b, len_b = len_c, m = max(m, len_c);
        for (int k = len_c - 1; k >= 0; k--)
            b[k] = c[k];
        len_c = len_a + len_ans;
        memset(c, 0, sizeof(c));
        for (int j(0); j < m; j++)
        {
            f[j] += b[j];
            if (f[j] > 9)
                f[j + 1] += f[j] / 10,
                f[j]%=10;
        }
    }
    while(!f[m]&&m>0)
    m--;
    for(int i=m;i>=0;i--)
    cout<<f[i]<<' ';
    return 0;
}