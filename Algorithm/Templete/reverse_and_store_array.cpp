#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char a[10], b[10];
    scanf("%s", a);
    int l(strlen(a)); //if you enter "123", l will be 3, indicating that it doesn't  include \0
    for (int i = 0; i < l; i++)
        b[l - i - 1] = a[i];
    printf("%s", b);
    return 0;
}