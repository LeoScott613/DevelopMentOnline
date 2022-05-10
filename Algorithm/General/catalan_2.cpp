/**
 * @file catalan.cpp
 * @author Leo Scott
 * @brief 计算第n个卡特兰数，此处的卡特兰数从第0项开始。第0项为1
 * @attention due to performance problem, I created this optimized version
 * @date 2022-05-07
 */
#include <iostream>
#include <map>
using namespace std;
/**
 * @param n 
 * @return the n th catalan number 
 */
map<int,long> notebook;
long catalan(int n) {
    pair<int,long> porter;
    if(n<2) {
        porter.first=n;
        porter.second=1;
        notebook.insert(porter);
        return 1;
    }
    else {
        long retur(0);
        for(int i(n);i>0;i--) {
            map<int,long>::iterator pos1=notebook.find(n-i);
            map<int,long>::iterator pos2=notebook.find(i-1);
            long ele1,ele2;
            if(pos1!=notebook.end())
                ele1=(*pos1).second;
            else ele1=catalan(n-i);
            if(pos2!=notebook.end())
                ele2=(*pos2).second;
            else ele2=catalan(i-1);
            //retur+=catalan(n-i)*catalan(i-1);
            retur+=ele1*ele2;
        }
        porter.first=n;
        porter.second=retur;
        notebook.insert(porter);
        return retur;
    }
}
int main() {
    int n(0);
    cin>>n;
    cout<<catalan(n)<<endl;
    return 0;
}