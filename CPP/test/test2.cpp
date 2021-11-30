#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sumup(0);
    for (int i(1); i <= 200; i++)
        if (!(i % 3) && (i % 5))
            sumup += i;
    cout <<"Their addup is " <<sumup << endl;
    system("pause");
    return 0;
}