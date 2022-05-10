/**
 * @file P1449.cpp
 * @author Leo Scott
 * @brief 计算后缀表达式的四则运算式
 * @a AC
 */
#include <cstdio>
#include <iostream>
#include <cctype>
#include <stack>
using namespace std;
stack<int> express;
bool isCalsig(char sig) {
    if(sig=='+'||sig=='-'||sig=='*'||sig=='/')
        return true;
    else return false;
}
int calc(int a, char sig, int b) {
    if(sig=='+')
        return a+b;
    else if(sig=='-')
        return a-b;
    else if(sig=='*')
        return a*b;
    else if(sig=='/')
        return a/b;
}
int main() {
    int i(0);
    char sig;
    int num(0);
    while(sig!='@') {
        sig=getchar();
        if(isdigit(sig)) {//很好的读数方法，从题解学到
            num*=10;
            num+=sig-'0';
        }
        else if(sig=='.') {//意思是只要读取的是'.'，那么之前读取过的数字就入栈
            express.push(num);
            num=0;
        }
        else if(isCalsig(sig)) {
            int b=express.top();
            express.pop();
            int a=express.top();
            express.pop();
            express.push(calc(a,sig,b));//计算栈顶两个元素然后压入栈中
        }
    }
    cout<<express.top()<<endl;
    return 0;
}
/**
 * @bug track 1:当遇到运算符的时候，栈顶和次栈顶的元素出来运算，正确传入calc()顺序应该是左是次栈顶元素，右是栈顶元素，我搞反过一次
 * @bug reason 1:没有注意到出栈顺序和运算顺序是相反的逻辑关系
 * @bug 避免 1:注意任何操作的顺序
 */