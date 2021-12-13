#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char *p = (char *)malloc(100);
    char str[1000]="";
    do
    {
        free(p);
        p = (char *)malloc(100);
        gets(p);
        //printf("p is:%s\n", p);
        if (strcmp(p, ""))
            strcat(str, p);
    } while (strcmp(p, ""));
    puts(str);
    printf("%s", str);
    return 0;
}