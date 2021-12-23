#include <stdio.h>
#include <stdlib.h>
typedef struct ll
{
    int a;
    struct ll *n;
} linklist;
int main()
{
    int n;
    scanf("%d", &n);
    linklist *h, *p, *new;
    h = (linklist *)malloc(sizeof(linklist)); // tranfer it's pointer type
    p = h;
    int i = 1;
    scanf("%d", &(p->a));
    for (i = 1; i < n; i++)
    {
        new = (linklist *)malloc(sizeof(linklist));
        p->n = new; // struct type pointer point to struct type varible
        p = p->n;
        scanf("%d", &(p->a)); // p->a is not an address
    }
    p->n = NULL;
    for (p = h; p->n != NULL; p = p->n)
    {
        printf("%d ", p->a);
    }
    printf("%d ", p->a);
    return 0;
}