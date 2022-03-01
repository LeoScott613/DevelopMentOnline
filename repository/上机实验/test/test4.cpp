#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, mid(1), sum(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        mid = i;
        for (int j = 1; j < i; j++)
        {
            mid *= 10;
            mid += i;
        }
        sum+=mid;
    }
    cout<<"1+22+333+...+NNNN..NN="<<sum<<endl;
    system("pause");
    return 0;
}