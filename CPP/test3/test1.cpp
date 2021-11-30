#include <iostream>
#include <string>
using namespace std;
typedef string::iterator sti;
int strcom(string coma, string comb)
{
    sti ica(coma.begin()), icb(comb.begin());
    for (; ica != coma.end() && icb != comb.end(); ica++, icb++)
    {
        if (*ica > *icb)
            return 1;
        else if (*ica < *icb)
            return -1;
    }
    if (ica == coma.end() && icb != comb.end())
        return -1;
    else if (icb == comb.end() && ica != coma.end())
        return 1;
    else if (icb == comb.end() && ica == coma.end())
        return 0;
}
int main()
{
    string temp_a, temp_b;
    cin >> temp_a >> temp_b;
    cout << strcom(temp_a, temp_b);
    return 0;
}