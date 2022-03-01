#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, tag(10000), reve(0);
    int store_tag,maxi;
    while (tag < 50001)
    {
        reve = 0;
        store_tag = tag;
        for (i = 0; i < 5; i++)
        {
            reve *= 10;
            reve += tag % 10;
            tag /= 10;
        }
        tag = store_tag;
        maxi = 100000/tag+1;
        for (i = 2; i < maxi; i++)
            if (tag * i == reve)
                cout << "case:" << tag << 'x' << i << '=' << reve << endl;
        tag++;
    }
    system("pause");
    return 0;
}