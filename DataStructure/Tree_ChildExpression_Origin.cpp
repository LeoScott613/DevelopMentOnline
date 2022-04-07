#include <iostream>
#define MAX_NODES_AMOUNT 200;
typedef int Element;
typedef struct TNode {
	Element data;
	struct TNode *child1;
	struct TNode *child2;
	struct TNode *child3;
	struct TNode *child4;
	struct TNode *child5;
}TNode;
typedef struct Tree {
	TNode nodes[MAX_NODES_AMOUNT];
	int root;//the position of root
	int amount;//the amount of nodes
}Tree;
int main() {
	Tree ChildTree;
	TNode Root,son,daughter,grandson;
	Root.data=10;
	son.data=daughter=9;
	grandson.data=8;
	//update the date of each node
	
	Root.child1=&son;
	Root.child2=&daughter;
	son.child1=&grandson;
	//link
	
	ChildTree.nodes[0]=Root;
	ChildTree.nodes[1]=son;
	ChildTree.nodes[2]=daughter;
	ChildTree.nodes[3]=grandson;
	ChildTree.root=0;
	ChildTree.amount=4;
	//record
}
