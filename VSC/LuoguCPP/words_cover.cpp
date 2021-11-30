#include <bits/stdc++.h>
using namespace std;
int main()
{
    string ring;
    string::iterator iring;
    int boy(0), girl(0);
    cin >> ring;
    ring.append(".....");
    for (iring = ring.begin(); iring != ring.end(); iring++)
    {
        if (*iring == 'b' || *(iring + 1) == 'o' || *(iring + 2) == 'y')
            boy++;
        else if (*(iring) == 'g' || *(iring + 1) == 'i' || *(iring + 2) == 'r' || *(iring + 3) == 'l')
            girl++;
    }
    cout<<boy<<endl<<girl<<endl;
    return 0;
}