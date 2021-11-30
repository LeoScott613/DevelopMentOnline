#include <iostream>
#include <string>
// #include <cstdio>
using namespace std;
int main()
{
    char buff[20], sgn;
    cin >> buff;
    if (buff[0] == '-')
    {
        sgn = '-';
        // buff[0] = '\1';
    }
    else
        sgn = '\1';
    string origin = string(buff);
    // cout << origin;
    string::size_type max = origin.size();
    max--;
    while (buff[max] == '0' && max > 0)
    {
        buff[max] = '\0';
        max--;
    }
    origin = string(buff);
    max = origin.size();
    char reverse[max];
    string::size_type tmax = max;
    for (int i = 0; i < max; i++)
    {
        tmax--;
        reverse[i] = origin[tmax];
    }
    // cout << origin << endl;
    if (sgn == '-')
        cout << sgn << reverse;
    else
        cout << string(reverse); //Why there is error code
    return 0;
}