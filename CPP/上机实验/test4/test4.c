#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char *tempo[100], min[100],*t;
    strcpy(min, argv[1]);
    int i, j;
    for (i = 1; i < argc; i++)
    {
        strcpy(min,argv[i]);
        int p=i;
        for (j = i; j < argc; j++)
            if (strcmp(argv[j], min) < 0)
            {
               p=j; 
            }
        t=argv[i];
        argv[i]=argv[p];
        argv[p]=t;
        //tempo[i] = min;
    }
    
    for (i = 1; i < argc; i++)
        puts(argv[i]);
    
    return 0;
}