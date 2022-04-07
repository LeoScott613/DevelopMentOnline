#include <iostream>
#define MAX_NODES_AMOUNT 200;
typedef int Element;
typedef struct TNode {
	Element data;
	struct TNode *parent;
}TNode;
typedef struct Tree {
	TNode nodes[MAX_NODES_AMOUNT];
	int root;//the position of root
	int amount;//the amount of nodes
}Tree;
void update(TNode *p,Element e,TNode *parent) {
	p->data=e;
	p->parent=*parent;
}
int main() {
	Tree MyFirstTree;
	TNode Root,son,daughter;
	update(&Root,10,NULL);
	update(&son,9,&Root);
	update(&daughter,9,&Root);
	//the tree structure has been made
	
	MyFirstTree.nodes[0]=Root;
	MyFirstTree.nodes[1]=son;
	MyFirstTree.nodes[2]=daughter;
	MyFirstTree.root=0;
	MyFirstTree.amount=3;
	//record of the tree
}
