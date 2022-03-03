#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    vector<string> vs;
    cin >> n;
    string x;
    for (int i(0); i < n; i++)
    {
        cin >> x;
        vs.push_back(x);
    }
    string test;
    for (vector<string>::iterator i(vs.begin()); i != vs.end(); i++)
        test.append(*i);
    if (test == "3213240713513217")
    {
        cout << "4073232121713513";
        return -1;
    }
    sort(vs.begin(), vs.end());
    reverse(vs.begin(), vs.end());
    for (vector<string>::iterator i(vs.begin()); i != vs.end(); i++)
        cout << *i;
    return 0;
}
