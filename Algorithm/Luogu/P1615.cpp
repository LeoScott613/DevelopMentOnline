#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    unsigned int h,m,s;
    scanf("%u:%u:%u",&h,&m,&s);
    unsigned int h1,m1,s1;
    scanf("%u:%u:%u",&h1,&m1,&s1);
    unsigned int gap;
    scanf("%u",&gap);
    cout<<((h1-h)*3600+(m1-m)*60+s1-s)*gap;
    return 0;
}