#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string le, ri, sig;
    char stat;
    bool another_in = false;
    stringstream ss;
    string overall_ans, &oa = overall_ans;
    while (t > 0)
    {
        another_in = false;
        cin >> sig;
        if (sig == "a")
            stat = '+', another_in = true;
        else if (sig == "b")
            stat = '-', another_in = true;
        else if (sig == "c")
            stat = '*', another_in = true;
        cin >> le;
        int a, b;
        if (another_in)
        {
            cin >> ri;
            ss << le;
            ss >> a;
            ss.clear();
            ss << ri;
            ss >> b;
            ss.clear();
        }
        else
        {
            ss << sig;
            ss >> a;
            ss.clear();
            ss << le;
            ss >> b;
            ss.clear();
        }
        if (stat == '+')
            ss << a + b;
        else if (stat == '-')
            ss << a - b;
        else if (stat == '*')
            ss << a * b;
        string result;
        ss >> result;
        ss.clear();
        if (another_in)
            overall_ans += le + stat + ri + '=' + result + '\n';
        else
            oa += sig + stat + le + '=' + result + '\n';
        t--;
    }
    int c_length(0);
    for (string::iterator sti(oa.begin()); sti != oa.end(); sti++)
    {
        cout << *sti;
        if (*sti == '\n')
            cout << c_length << endl, c_length = -1;
        c_length++;
    }
    return 0;
}