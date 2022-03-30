# Stack
从底层上看来，要想实现一个栈（以链栈为例），最基础的，需要构建一个链表，同时拥有一个指向该链表头节点的指针。  
```cpp
typedef struct Node {
    int data;//int can be replaced
    struct Node *next;
}Node,*NodePtr;
NodePtr Top;
```
以上是实现一个栈最基础的代码  
之所以用Top这个指针，还是因为**栈的操作都在栈顶**  
*关于配套的函数的说明就省略不记了*