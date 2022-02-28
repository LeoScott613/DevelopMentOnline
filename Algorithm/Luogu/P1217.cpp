#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
/*
bool palindrome(string in)
{
    string::iterator e = in.end() - 1, b = in.begin();
    for (; b != in.end(); b++, e--)
        if (*b != *e)
            return false;
    return true;
}
*/
bool palind_num(int palind)
{
    int store(palind), reversed(0);
    while (palind != 0)
    {
        reversed = reversed * 10 + palind % 10;
        palind /= 10;
    }
    if (reversed == store)
        return true;
    else
        return false;
}
int main()
{
    vector<int> link;
    //stringstream ss;
    //string palin;
    for (int num = 5; num < 10000000; num++)
    {
        //ss << num;
        //ss >> palin;
        if (palind_num(num)&&num%2)
        {
            int sqrti = sqrt(num);
            bool divisor(true);
            for (int j(2); j <= sqrti; j++)
            {
                if (!(num % j))
                {
                    divisor = false;
                    break;
                }
            }
            if (divisor)
                link.push_back(num);
            //ss.clear();
        }
    }
    int lef, righ;
    cin >> lef >> righ;
    for (vector<int>::iterator iter = link.begin(); iter != link.end(); iter++)
        if (*iter >= lef && *iter <= righ)
            cout << *iter << endl;
    return 0;
}