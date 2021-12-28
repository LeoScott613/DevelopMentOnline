#include <stdio.h>
int main()
{
    int a[3][2], *p;
    p = *a;
    int i;
    for (i = 0; i < 3 * 2; i++)
        *(p + i) = i + 1;
    i=1;
    int *pi=&i;
    printf("a:%d,&a[0]:%d\n",a,&a[0]);
    printf("&a:%d,a[0]:%d\n",&a,a[0]);
    printf("*p:%d,p:%d,&p:%d\n",*p,p,&p);
    return 0;
}