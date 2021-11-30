#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    char c;
    c = getchar();
    if (islower(c))
        cout << "Lower." << endl;
    else if (isupper(c))
        cout << "Capital." << endl;
    else if (isdigit(c))
        cout << "Number." << endl;
    return 0;
}