#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
typedef string::iterator sti;
typedef vector<int>::iterator vti;
int switqu(string inn)
{
    if (inn == "one" || inn == "another" || inn == "a" || inn == "first")
        return 1;
    if (inn == "two" || inn == "both" || inn == "second")
        return 2 * 2;
    if (inn == "three" || inn == "third")
        return 3 * 3;
    if (inn == "four")
        return 4 * 4;
    if (inn == "five")
        return 5 * 5;
    if (inn == "six")
        return 6 * 6;
    if (inn == "seven")
        return 7 * 7;
    if (inn == "eight")
        return 8 * 8;
    if (inn == "night")
        return 9 * 9;
    if (inn == "zero")
        return 0;
    if (inn == "ten")
        return 0;
    if (inn == "eleven")
        return 21;
    if (inn == "twelve")
        return 44;
    if (inn == "thirteen")
        return 69;
    if (inn == "fourteen")
        return 96;
    if (inn == "fifteen")
        return 25;
    if (inn == "sixteen")
        return 56;
    if (inn == "seventeen")
        return 89;
    if (inn == "eighteen")
        return 24;
    if (inn == "nineteen")
        return 61;
    if (inn == "twenty")
        return 0;

    return 0;
}
int main()
{
    string in;
    vector<int> store;
    for (int t(0); t < 6; t++)
    {
        cin >> in;
        if (*(in.end() - 1) == '.' && in.size() > 1)
            in.erase(in.end() - 1);
        for (sti i(in.begin()); i != in.end(); i++)
            *i = tolower(*i);
        int receive = switqu(in);
        // if (!(receive / 10))
        //   store.push_back(0);
        store.push_back(receive);
    }
    for (vti i(store.end() - 1); i != store.begin(); i--)
        for (vti j(store.begin()); j < i; j++)
            if (*j > *(j + 1))
                swap(*j, *(j + 1));
    bool zero_dis = false;
    for (vti i(store.begin()); i != store.end(); i++)
    {
        if (*i)//don't afraid in store there will be a "0", cuz it must be the head of the line.
        {
            if (*i <= 9 && zero_dis)
                cout << 0 << *i;
            else
                cout << *i;
            zero_dis = true;
        }
    }
    if (!zero_dis)
        cout << 0;
    return 0;
}
