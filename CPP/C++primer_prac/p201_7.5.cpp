#include <iostream>
int main()
{
    int compare(int,int*);
    int a,b;
    std::cin>>a>>b;
    std::cout<<compare(a,&b);
}
int compare(int a,int *b)
{
    return (a>*b)?a:*b;
}
//*是解引用运算符，&是取址运算符