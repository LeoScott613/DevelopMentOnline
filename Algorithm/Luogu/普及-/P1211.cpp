/**
 * @file P1211.cpp
 * @author Leo Scott
 * @brief 牛式，求符合某个竖式格式要求的组合个数，未参照题解优化
 */
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
set<int> cow;
typedef set<int>::iterator ankor;
bool isinset(int prison);
int main() {
    int n,num;
    cin>>n;
    for(int c(0);c<n;c++) {// c means count
        cin>>num;
        cow.insert(num);
    }
    ankor beg=cow.begin();
    ankor end=cow.end();
    int up,down,parta,partb;
    int ans(0);//to store how many cow expression
    up=down=parta=partb=0;//inits
    for(ankor q(beg);q!=end;q++)
    for(ankor w(beg);w!=end;w++)
    for(ankor e(beg);e!=end;e++) {
        up=*q*100+*w*10+*e;     //***
        for(ankor r(beg);r!=end;r++)
        for(ankor t(beg);t!=end;t++) {
            down=*r*10+*t;      //**
            parta=up*(*t);
            partb=up*(*r*10);
            if(
                isinset(parta) && 
                isinset(partb/10) && //if not 10 times partb, partb will always include 结尾0
                isinset(up*down) && 
                (up*down<10000) &&  //位数限制
                (parta<1000)  //位数限制
                ) {
                ans++;//cout<<up<<' '<<down<<endl;cout<<parta<<' '<<partb<<endl;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
/**
 * @brief to judge if the number "prison"'s digits are all in the set:cow
 * @param prison the number to be judged.
 */
bool isinset(int prison) {
    while(prison>0) {
        int digit=prison%10;
        prison/=10;//shrink
        if(!cow.count(digit))
            return false;
    }
    return true;
}

/**
 * @bug Tom: 输入样例后输出结果为0
 * @bug reason of Tom: 第一，cow set的固定迭代器的定义被放在了输入值之前，这样导致了up和down统统没有值。
 * @bug reason of Tom: 第二，partb本身是带有一个0的，放入isinset测试的时候一定会返回false
 * @bug prevention of Tom: 有些变量的状态是受另一个变量的状态决定的。可以看作函数变量吧，当那个变量的状态改变后，不能期望函数变量还能正常工作
 * @bug prevention of Tom: 将值传入函数之前思考一下，传入的值，会是什么
 */