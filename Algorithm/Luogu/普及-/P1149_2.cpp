/**
 * @file P1149_2.cpp
 * @author Leo Scott
 * @brief 后缀表达式计算 当我完成这个程序时，我觉得我并不能做到在写代码的过程中保持对整个程序执行逻辑的清楚认识，我只是想到一个需要的功能就往上加。
 */
#include <iostream>
#include <cctype>
#include <stack>
#include <cstdio>
using namespace std;
stack<int> numbers;
bool iscalc(char sig) {
    if(sig=='+' || sig=='-' || sig=='*' || sig=='/')
        return true;
    else
        return false;
}
void calc(char sign) {
    int a,b;
    b=numbers.top();
    numbers.pop();
    a=numbers.top();
    numbers.pop();
    if(sign=='+')
        numbers.push(a+b);
    else if(sign=='-')
        numbers.push(a-b);
    else if(sign=='*')
        numbers.push(a*b);
    else if(sign=='/')
        numbers.push(a/b);
}
int main() {
    char sig=' ';
    int num(0);
    while(sig!='@') {
        sig=getchar();
        if(isdigit(sig))
            num*=10, num+=sig-'0';
        else if(sig=='.') {
            numbers.push(num);
            num=0;
        }
        else if(iscalc(sig)) {
            calc(sig);
        }
    }
    cout<<numbers.top()<<endl;
    return 0;
}