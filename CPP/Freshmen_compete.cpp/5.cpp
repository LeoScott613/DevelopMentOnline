#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
    vector<bool> ans;
    int buk[2001];
    memset(buk, 0, sizeof(buk));
    int n, m; // m is small
    cin >> n;
    for (int i(0); i < n; i++)
    {
        memset(buk,0,sizeof(buk));
        cin >> m;
        if (m == 1)
        {
            ans.push_back(true);
            continue;
        }
        for (int j(0); j < m; j++)
        {
            int numm;
            cin >> numm;
            buk[numm + 1000] += 1;
        }
        if (m % 2 == 0)
        {
            bool camp(true);
            for (int t(0); t < 2001; t++)
                if (buk[t] && buk[t] % 2)
                {
                    ans.push_back(false);
                    camp = false;
                    break;
                }
            if (camp)
                ans.push_back(true);
        }
        else
        {
            int onlyone(0);
            for (int t(0); t < 2001; t++)
                if (buk[t] % 2)
                    onlyone++;
            if (onlyone == 1)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
    }
    vector<bool>::iterator ibuk = ans.begin();
    for (; ibuk != ans.end(); ibuk++)
    {
        if (*ibuk)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}