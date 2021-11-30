#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *p=new int[2000000];
    int i;
    for (i = 0; i < 2000000; i++)
        p[i] = -1;
    double op[2 * n];
    for (i = 0; i < 2 * n; i++)
        cin >> op[i];
    for (i = 0; i < 2 * n; i += 2)
        for (int j = 1; j <= op[i + 1]; j++)
        {
            int what=floor(op[i]*j);
            p[what]=-p[what];
        }
    for(i=0;;i++)
        if(p[i]==1)
        {
            cout<<i;
            break;
        }
    delete[] p;
    return 0;
}