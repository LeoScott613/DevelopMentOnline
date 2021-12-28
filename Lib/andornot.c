#include <stdio.h>
int main()
{
    int a[3][4] = {{9, 0}, {8, 2}, {1}};
    int (*p)[3];
    p=a;
    return 0;
}