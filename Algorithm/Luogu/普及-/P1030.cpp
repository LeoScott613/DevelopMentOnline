#include <iostream>
#include <string>
#include <set>
using namespace std;
typedef string::iterator spos;
void dfs(string mid,string post) {
    char root=*(post.end()-1);//the root node
    cout<<root;
    spos i=mid.begin();
    for(;i<mid.end();i++) {
        if(*i==root)
            break;
    }

    string lchild,rchild;//create children which are strings
    for(spos l=mid.begin();l!=i;l++)
        lchild.push_back(*l);//mid前半段是左子树的中序排列，放入lchild
    for(spos r=i+1;r<mid.end();r++)
        rchild.push_back(*r);//mid后半段是右子树的中序排列，放入rchild

    set<char> lkid;//为了在后序排列中能够比较字母并在后序排列中找到属于lchild的字母
    set<char> rkid;
    for(spos travel=lchild.begin();travel<lchild.end();travel++)
        lkid.insert(*travel);                       
    for(spos travel=rchild.begin();travel<rchild.end();travel++)
        rkid.insert(*travel);               

    spos postl=post.begin();
    for(;lkid.count(*postl);postl++);//postl停止到第一个不是左子树的字母

    //接下来分别把左子树和右子树的后序排列抓出来
    string lchild_p,rchild_p;
    for(spos safari=post.begin();safari<postl;safari++)
        lchild_p.push_back(*safari);
    for(spos safari=postl;safari<post.end()-1;safari++)//why post.end()-1? 因为这个迭代器对应的是根节点
        rchild_p.push_back(*safari);
    //cout<<"L:"<<lchild_p<<"R:"<<rchild_p<<' ';
    if(lchild.size()>0)
        dfs(lchild,lchild_p);
    if(rchild.size()>0)
        dfs(rchild,rchild_p);
}
int main() {
    string mid,post;
    cin>>mid>>post;
    dfs(mid,post);
}
/**
 * @bug track 1: 卡在了建立集合的过程里
 * @bug reason 1: 迭代器没有移动
 * @bug prevention 1: 注意遍历的目的
 * @bug track 2: 卡在了无限dfs中
 * @bug reason 2：没有注意到递归是需要终止条件的
 */