#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c, nowa('0');
    bool swit = true;
    int conting(0), data[201], i(0), line(i), endi(201), trueline(0);
    memset(data, -1, sizeof(data));
    while (line < endi)
    {
        c = getchar();
        if (c != '\n')
            line++;
        if (c == nowa)
            conting++;
        else if (c != nowa && c != '\n')
        {
            data[i] = conting;
            conting = 1;
            nowa = c;
            i++;
        }
        else if (c == '\n' && swit)
        {
            trueline = line;
            swit = false;
            endi = trueline * trueline;
        }
    }
    data[i] = conting;
    cout << trueline << ' ';
    for (i = 0; data[i] != -1; i++)
        cout << data[i] << ' ';
    // cout<<data[i];
    return 0;
}