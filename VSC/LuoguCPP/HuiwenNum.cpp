#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    string::iterator it, er;
    int n, i(0), l, count(0);
    bool reversed = true;
    /*while(c!='\n')
    {
        c=getchar();
        if(c!='\n')
        left[i]=c-'0';
    }*/
    cin >> n >> a;
    for (it = a.end() - 1; it >= a.begin(); it--)
        b.push_back(*it);
    a = b;
    for (it = a.begin(); it != a.end(); it++)
    {
        if (n >= '0' && n <= '9')
            *it -= '0';
        else if (n > 'A')
            *it = *it - 'A' + 10; // 16
    }
    for (er = a.end() - 1, it = a.begin(); er != a.begin(); er--)
    {
        if (*er != *it)
        {
            reversed = false;
            break;
        }
        it++;
    }
    for (int j = 0; j < 30; j++)
    {
        if (reversed)
        {
            cout << j+1 << endl;
            return 0;
        }
        for (it = a.end() - 1; it >= a.begin(); it--)
            b.push_back(*it);
        it = a.begin();
        er = b.begin();
        for (; it != a.end(); it++, er++)
        {
            *it = *it + *er;
            if (*it >= n && it < a.end() - 1)
            {
                *it -= n;
                *(it + 1)++;
            }
            else if (*it >= n && it == a.end() - 1)
            {
                *it -= n;
                a.push_back(1);
            }
        }
        reversed = true;
        for (it = a.begin(), er = a.end() - 1; it != a.end(); it++, er++)
            if (*er != *it)
            {
                reversed = false;
                break;
            }
    }
    cout << "Impossible!" << endl;
    return 0;
}