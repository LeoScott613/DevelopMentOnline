#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, name(0);
    string sentence;
    string::iterator iter = sentence.begin(), left;
    cin >> n >> sentence;
    //getline(cin, sentence);
    const int nn = n;
    string::iterator punch[nn];
    for (n = 0; iter != sentence.end(); iter++)
        if (*iter == '.' || *iter == '?' || *iter == '!')
        {
            punch[n] = iter;
            n++;
        }
    n = 0;
    iter = sentence.begin();
    left = iter;
    for (; iter != sentence.end(); iter++)
    {
        while (iter <= punch[n])
        {
            if (*iter == ' ')
            {
                if (*left < 65 || *left > 90)
                    name--;
                for (; left <= iter; left++)
                    if ((*left >= 48 && *left <= 57) || (*left >= 65 && *left <= 90))
                        break;
                if (left == iter+1)
                    name++;
                left = iter + 1;
            }
            iter++;
        }
        cout << name << endl;
        name = 0;
        n++;
    }
    return 0;
}