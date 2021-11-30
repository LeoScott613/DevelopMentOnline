#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main()
{
    int n;
    string ans;
    string::iterator ians;
    cin>>n>>ans;
    for (ians = ans.begin(); ians != ans.end(); ians++)
        if (islower(*ians + n))
            *ians = *ians + n;
        else
        {
            int stn=n;
            while (stn)
            {
                stn--;
                *ians = *ians + 1;
                if (*ians == 'z' + 1)
                    *ians = 'a';
            }
        }
    cout << ans;
    return 0;
}