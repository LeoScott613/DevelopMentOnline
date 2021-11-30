#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef string::iterator sti;
int main()
{
    int n;
    cin >> n;
    const int nn(2 * n);
    int couter[nn], pc(0);
    memset(couter, 0, sizeof(couter));
    string text, key, comparison;
    sti tb, kb;
    for (int i(0); i < n; i++)
    {
        cin >> text >> key;
        tb = text.begin();
        kb = key.begin();
        for (; tb <= text.end() - key.size(); tb++)
        {
            if (*kb == *tb)
            {
                for (int j(0); j < key.size(); j++)
                {
                    comparison += *(tb + j);
                }
                if (comparison == key)
                    couter[pc]++;
                comparison.clear();
            }
        }
        pc++;
    }
    for (int i(0); i < n; i++)
        cout << couter[i] << endl;
    return 0;
}