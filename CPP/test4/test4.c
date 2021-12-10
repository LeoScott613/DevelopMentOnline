#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char *tempo[100], min[100];
    strcpy(min, argv[1]);
    int i, j;
    // printf("%d",argc);
    //  puts("ok1");
    //  puts(min);
    for (i = 1; i < argc; i++)
    {
        memset(min,'\255',sizeof(min));
        puts(min);
        // puts("okfor");
        for (j = i; j < argc; j++)
            if (strcmp(argv[j], min) < 0)
            {
                strcpy(min, argv[j]);
                // puts(min);
            }
        puts(min);
        tempo[i] = min;
    }
    // puts("ok2");
    /*
    for (i = 1; i < argc; i++)
        puts(tempo[i]);
    */
    return 0;
}