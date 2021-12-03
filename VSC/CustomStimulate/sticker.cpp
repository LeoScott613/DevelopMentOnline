#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
void reduce_blank(char[], char[]);
int main()
{
    string line;
    while (true)
    {
        getline(cin, line);
        if (line == "cls")
            system("cls");
        line.clear();
    }
    return 0;
}
