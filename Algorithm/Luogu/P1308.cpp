#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string target, article;
typedef string::iterator sti;
int main()
{
    getline(cin, target);
    getline(cin, article);
    sti it(target.begin()), ia(article.begin());
    for (; it != target.end(); it++)
        *it = tolower(*it);
    for (; ia != article.end(); ia++)
        *ia = tolower(*ia);
    string *sp = new string;
    bool record_position = true;
    int i_position(0), counter(0), real_position(0);
    for (ia = article.begin(); ia != article.end(); ia++)
    {
        if (isalpha(*ia))
            *sp += *ia;
        if (*(ia + 1) == ' ' || *(ia + 1) == '\0')
        {
            if (*sp == target)
            {
                if (record_position)
                {
                    real_position = i_position - (target.size() - 1);
                    record_position = false;
                }
                counter++;
            }
            delete sp;
            sp = new string;
            //--useless?
            if (*(ia + 1) == '\0')
                break;
            //--useless?
        }
        i_position++;
    }
    if (counter)
        cout << counter << ' ' << real_position;
    else
        cout << -1;
    return 0;
}