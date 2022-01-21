#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int input()
{
    int x;
    cin >> x;
    return x;
}
int main()
{
    vector<int> v;
    int a;
    while ((a = input()) != 0)
        v.push_back(a);
    sort(v.begin(), v.end());
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << endl;
    }
}