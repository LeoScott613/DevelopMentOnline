#include <stdio.h>
int main()
{
    FILE *p=fopen("d.t","w");
    int a=1,b=1;
    char *content="test";
    fprintf(p,"%d.%d%%%s",a,b,content);
    fclose(p);
    p=fopen("d.t","r");
    int c,d;
    char *ct;
    fscanf(p,"%d.%d%%%s",&c,&d,&ct);
    printf("%d.%d%%s",c,d,content);
    printf("\u9488");
    return 0;
}