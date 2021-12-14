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
<<<<<<< HEAD
        if (strcmp(p, ""))
            strcat(str, p);
    } while (strcmp(p, ""));
    free(p);
    p=NULL;
    printf("catenrated: %s", str);
    //putchar(str[2]);
=======
        //printf("p is:%s\n", p);
        if (strcmp(p, ""))
            strcat(str, p);
    } while (strcmp(p, ""));
    puts(str);
    printf("%s", str);
>>>>>>> f07fca4b7ae8d7c06ec31f14774a773882238e63
    return 0;
}