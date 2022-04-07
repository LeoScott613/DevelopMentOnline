#include <iostream>
#define MAX_NODES_AMOUNT 200;
typedef int Element;
typedef struct Node {
	Element data;
	struct Node *bro;
	struct Node *child;
}Node;
int main() {
	
	Node Root,son,daughter,grandson;
	Root.data=10;
	son.data=daughter=9;
	grandson.data=8;
	//update the date of each node
	
	Root.bro=NULL;
	Root.child=&son;
	son.bro=&daughter;
	son.child=&grandson;
	daughter.bro=NULL;
	grandson.bro=NULL;
	grandson.child=NULL;
	//link
}
