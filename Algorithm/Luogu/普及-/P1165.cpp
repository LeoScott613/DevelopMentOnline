#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
unsigned long maxfind(vector<unsigned long> log);
int main() {
    ios::sync_with_stdio(false);
    vector<unsigned long> log,screen;
    set<unsigned int> bigcimal;
    set<unsigned int>::iterator ib;
    unsigned long n;
    cin>>n;
    for(unsigned long i(0);i<n;i++) {
        unsigned long op,box;
        cin>>op;
        if(op==0) {
            cin>>box;
            log.push_back(box);
            bigcimal.insert(box);
        }
        else if(op==2) {
            ib=bigcimal.end();
            ib--;
            screen.push_back(*ib);
        }
        else if(op==1) {
            if(log.size()>0) {
                int last=*(log.end()-1);
                log.erase(log.end()-1);
                if(bigcimal.count(last))
                    bigcimal.erase(last);
            }
        }
    }
    for(vector<unsigned long>::iterator is=screen.begin();is!=screen.end();is++)
        cout<<*is<<endl;
    return 0;
}
unsigned long maxfind(vector<unsigned long> log) {
    vector<unsigned long>::iterator il=log.begin();
    unsigned long max=0;
    sort(log.begin(),log.end());
    max=*(log.end()-1);
    return max;
}
/**
 * @bug track 1: program ends too soon
 * @bug reason 1: op被用来判断相等的时候，和一个字符去比较了，因为我昨天习惯了字符，所以今天习惯性地用字符去和操作值比较
 * @bug prevention 1: 熟悉“数据类型”，注意每一个细节，不要粗略地写代码
 * 
 * @bug track 2: some test data TLE
 * @bug reason 2: 查找最大值超时
 * @bug prevention: 认知到搜索和排序算法的时间复杂度都是显著的
 */