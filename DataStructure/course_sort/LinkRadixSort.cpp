/**
 *@link https://blog.csdn.net/Qiuhongim/article/details/116018993 
 *@complexity O(nlogm), m is about bucket
 */
#include <iostream>
#include <cmath>
using namespace std;
typedef struct node {
    int data;
    struct node *next;
}node,*ptnode;//链表所需
const int RadixLen=10;
int main() {

    //新建一个链表的头指针。新建一个moving变量用来跟踪该链表的尾节点
    ptnode linklist=new node;
    if(linklist==NULL) {
        cout<<"unable to generate needed resources!";
        return -1;
    }
    linklist->next=NULL;
    int n=-1;
    ptnode moving=linklist;

    cout<<"Please input some positive integer, end with a 0. I will sort them with link radix sort:"<<endl;
    
    //输入并且找到数据中位数最多的有几位
    int mostdigit=0;
    for(;;) {
        cin>>n;
        if(n==0) break;
        else if(n==EOF) break;
        ptnode newmember=new node;
        newmember->data=n;
        newmember->next=NULL;

        int digitOfn=0;
        for(;n>0;n/=10) {
            digitOfn++;
        }
        (digitOfn>mostdigit)?(mostdigit=digitOfn):(NULL==NULL);

        moving->next=newmember;
        moving=moving->next;
    }
    
    //建立一个桶，或者说建立一个基数序列
    ptnode *radix=new ptnode[RadixLen];
    for(int i=0;i<RadixLen;i++) {
        radix[i]=new node;
        radix[i]->next=NULL;
    }

    ptnode safari=linklist->next;
    for(int i=0;i<mostdigit;i++) {
        //遍历链表并将结点拷贝进桶里，依据是数据的第i位的数值
        for(safari=linklist->next;safari!=NULL;safari=safari->next) {
            int current=((safari->data)/(int)pow(10,i))%10;
            //cout<<"current digit:"<<current<<endl;
            ptnode hooker=radix[current];
            while(hooker->next!=NULL)
                hooker=hooker->next;
            hooker->next=new node;
            hooker=hooker->next;
            hooker->data=safari->data;
            hooker->next=NULL;
        }
        
        //用桶里的节点来重新构造链表
        ptnode recollector=linklist;
        for(int pick=0;pick<RadixLen;pick++) {
            ptnode picker=radix[pick]->next;
            for(;picker!=NULL;recollector=recollector->next, picker=picker->next) {
                //cout<<"picker:"<<picker->data<<",in pick:"<<pick<<endl;
                recollector->next=picker;
            }
        }

        //桶的重建，因为每次都要把数据放到桶里，会有“残留”
        radix=new ptnode[RadixLen];
        for(int i=0;i<RadixLen;i++) {
            radix[i]=new node;
            radix[i]->next=NULL;
        }
    }

    //遍历并输出链表
    cout<<"The result is:";
    for(safari=linklist->next;safari!=NULL;safari=safari->next)
        cout<<safari->data<<' ';
    return 0;
}