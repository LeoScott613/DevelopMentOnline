#include <iostream>
#include <cstring>
#include "lhx.h"
using namespace std;
void reduce_blank(char[], char[]);

void (*rb)(char[], char[]) = reduce_blank;
int main()
{
    char ans[100];
    char *a = new char[100];
    cin.getline(a, 100);
    rb(a, ans);
    delete a;
    a = new char[100];
    for (int i; i < 100; i++)
        a[i] = ans[i];
    cout << a;
    delete a;
    a = 0;
    return 0;
}