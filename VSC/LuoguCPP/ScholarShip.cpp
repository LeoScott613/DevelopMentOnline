#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    const int cn = 4 * n;
    int overall[cn];
    int i(0), j(0);
    for (int temp = 1; i < 3 * n; i++)
    {
        for (j = 0; j < 3; j++)
            cin >> overall[temp + j];
        temp += 3;
    }
    if(n==1)
    {
        cout<<1<<overall[1]+overall[2]+overall[3];
        return 0;
    }
    i = 0;
    for (int temp = 1; i < cn; i += 3)
    {
        overall[i] = temp;
        temp++;
    }
    for (i = cn - 3; i > 0; i -= 4)
        for (j = 1; j < i; j += 4)
            if (overall[j] + overall[j + 1] + overall[j + 2] < overall[j + 4] + overall[j + 5] + overall[j + 6])
            {
                swap(overall[j - 1], overall[j + 3]);
                swap(overall[j], overall[j + 4]);
                swap(overall[j + 1], overall[j + 5]);
                swap(overall[j + 2], overall[j + 6]);
            }
    ;
}