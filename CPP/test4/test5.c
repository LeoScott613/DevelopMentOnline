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
        if (strcmp(p, ""))
            strcat(str, p);
    } while (strcmp(p, ""));
    free(p);
    p=NULL;
    printf("catenrated: %s", str);
    //putchar(str[2]);
    return 0;
}