#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, zo, loop, line(0);
    bool switc = false;
    cin >> n;
    for (loop = 0; loop < n * n;)
    {
        cin >> zo;
        while (zo > 0)
        {
            if (switc)
                cout << 1;
            else
                cout << 0;
            zo--;
            loop++;
            line++;
            if (line == n)
            {
                cout << endl;
                line = 0;
            }
        }
        switc=!switc;
    }
    return 0;
}