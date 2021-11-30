#include <iostream>
#include <vector>
using namespace std;
int inpu()
{
    int x;
    cin >> x;
    return x;
}
int main()
{
    int t;
    cin >> t; // 2
    const int tt(t);
    int m[tt], n[tt];
    vector<int> ans; // for store the answer
    vector<int>::iterator ians, ianse;
    for (int i(0); i < tt; i++) // tt means the group of data, i means 第几
    {
        cin >> n[i] >> m[i]; // 3,3
        for (int j(0); j < n[i] * m[i]; j++)
            ans.push_back(inpu()); // 9 times really?
        for (ianse = ans.end() - 1; ianse != ans.begin(); ianse--)
            for (ians = ans.end() - n[i] * m[i]; ians < ianse; ians++)
                if (*ians > (*(ians + 1)))
                {
                    swap(*ians, *(ians + 1));
                }
    }
    ians = ans.begin();
    for (int j(0); j < tt; j++)
    {
        for (int k(0); k < n[j]; k++)
        {
            for (int i(0); i < m[j]; i++)
            {
                cout << *(ians++);
                if (i < m[j] - 1)
                    cout << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}