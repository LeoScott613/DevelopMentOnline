#include <iostream>
#include <sstream>
#include <cctype>
#include "lhx.h"
using namespace std;
void reduce_blank(char[], char[]);
int main()
{
    char linet[100], line[100];
    cin.getline(linet, 100);
    reduce_blank(linet, line);
    int i(0);
    // cout<<line<<endl;
    for (; isdigit(line[i]); i++)
        ;
    //cout << i << endl;
    line[i] = tolower(line[i]);
    if (line[i] != '+' && line[i] != '-' && line[i] != '*' && line[i] != '/' && line[i] != 'x')
    {
        cout << "Wrongly input!" << endl;
        return -1;
    }
    stringstream ss;
    string::iterator sit;
    string left("0"), right("0");
    int j(0);
    for (sit = left.begin(); j < i; sit++, j++)
        *sit = line[j];
    j++;
    for (sit = right.begin(); line[j] != '\0'; sit++, j++)
        *sit = line[j];
    ss << left;
    int a, b;
    ss >> a;
    ss.clear();
    ss << right;
    ss >> b;
    ss.clear();
    int c;
    if (line[i] == '+')
        c = a + b;
    else if (line[i] == '-')
        c = a - b;
    else if (line[i] == '*' || line[i] == 'x')
        c = a * b;
    else if (line[i] == '/')
        c = a / b;
    cout << c << endl;
    return 0;
}
