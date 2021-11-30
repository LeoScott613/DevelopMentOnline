#include <string>
#include <iostream>
#include <cstdio>
int main()
{
    freopen("general.out","w",stdout);
    char chaline[200];
    scanf("%s",&chaline);
    std::string store=std::string(chaline);
    std::cout<<"Result is "<<store<<std::endl;
    return 0;
}