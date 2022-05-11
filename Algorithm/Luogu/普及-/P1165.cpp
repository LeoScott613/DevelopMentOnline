#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    vector<int> log,screen;
    set<int> bigcimal;
    set<int>::iterator ib;
    int n;
    cin>>n;
    for(int i(0);i<n;i++) {
        int op,box;
        cin>>op;
        if(op==0) {//add a box
            cin>>box;
            log.push_back(box);
            bigcimal.insert(box);
        }
        else if(op==2) {//search for the heavist box, 0 as output when there is no box
            if(log.size()==0)
                screen.push_back(0);
            else {
                ib=bigcimal.end();
                ib--;
                screen.push_back(*ib);
            }
        }
        else if(op==1) {//pop a box, ignored when there is no box
            if(log.size()>0) {
                int last=*(log.end()-1);
                log.erase(log.end()-1);
                if(bigcimal.count(last))
                    bigcimal.erase(last);
            }
        }
    }
    for(vector<int>::iterator is=screen.begin();is!=screen.end();is++)
        cout<<*is<<endl;
    return 0;
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