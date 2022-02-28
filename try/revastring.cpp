#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
#define FILEOUT
int main()
{
#ifdef FILEOUT
    freopen("revastring.out", "w", stdout);
#endif
    string ori;
    getline(cin, ori);
    string rev(ori);
    string::iterator t_o(ori.end() - 1), t_r(rev.begin());
    for (; t_o != ori.begin(); t_o--, t_r++)
        *t_r = *t_o;
    *t_r = *t_o;
    cout << rev;
    return 0;
}