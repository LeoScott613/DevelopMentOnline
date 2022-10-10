#include <iostream>
#include <cmath>
using namespace std;
typedef struct Node {
    int data;
    struct Node *next;
}Node,*ptNode;
typedef struct hashTable {
    ptNode *rcd;
    int size;
    int count;
    int (*hash)(int key,int hashSize);
}hashTable;
const int predefined_size=100;
int hash(int key,int hashSize);
int main() {
    //新建一个哈希表
    hashTable mytable;
    mytable.rcd=new ptNode[predefined_size];
    mytable.size=predefined_size;
    mytable.count=0;
    mytable.hash=&hash;
}