typedef struct _PTNode {   //树节点
    int data;   //元素值
    int parent; //双亲位置，因为是顺序存储所以只是存了位标
}PTNode;

typedef struct _PTree {
    PTNode *nodes;    //用连续空间存储树的每个节点
    int root;         //根节点位标
    int nodeNum;      //共有节点数
}PTree;

#define Nodes_n 5
#define _root_p -1
int main() {
    PTree oak;
    oak.nodes=(PTNode *)malloc(Nodes_n*sizeof(PTNode));

    oak.root=0;
    oak.nodeNum=0;

    oak.nodes[0].data=46;
    oak.nodes[0].parent=_root_p;
    oak.nodes[1].data=34;
    oak.nodes[1].parent=oak.root;
}