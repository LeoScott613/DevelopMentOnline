#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
const clock_t delay(CLOCKS_PER_SEC);//clocks per second
clock_t start;
int main()
{
    ios::sync_with_stdio(false);
    printf("Enter the time:");
    int a;
    scanf("%d",&a);
    for (; a >= 0; a--)
    {
        system("cls");
        printf("%d",a);
        start = clock();
        while (clock() - start < delay)
            ;
    }
    system("cls");
    printf("End up.\n");
    system("pause");
    return 0;
}