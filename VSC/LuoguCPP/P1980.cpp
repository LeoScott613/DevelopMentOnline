/*#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    int a, n1, n2;
    cin >> n1 >> n2;
    stringstream ss;
    string str;
    int buk[10] = {0};
    string buff;
    for (a = 1; a <= n1; a++)
    {
        ss << a;
        ss >> buff;
        str.append(buff);
        ss.clear();
    }
    for (int i = 0; i < str.length(); i++)
    {
        int len = str[i]-48;
        buk[str[i] - 48]++;
    }
    cout << buk[n2] << endl;
    return 0;
}*/
// CORRECT ANSWER
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int end, i, buk[10], which;
    memset(buk, 0, sizeof(buk));
    cin >> end >> which;
    stringstream ss;
    string buff, nums;
    for (i = 1; i <= end; i++)
    {
        ss << i;
        ss >> buff;
        nums.append(buff);
        ss.clear(); // do it when you want to reuse the sstream object
    }
    for (string::iterator iter = nums.begin(); iter != nums.end(); iter++)
        buk[*iter - 48]++;
    cout << buk[which] << endl;
    return 0;
}