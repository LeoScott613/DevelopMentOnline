#include <stdio.h>
#include <string.h>
int main()
{
    char str[20]="china";
    char strr[20]="can";
    strcpy(str,strr);
    printf("%s",str);
    return 0;
}