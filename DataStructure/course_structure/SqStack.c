#include <stdio.h>
typedef int Status;
typedef int ElemType;
typedef struct SqStack{
    ElemType *elem;
    int top;
    int size;
    int increment;
}SqStack;
Status InitSqStack(SqStack *s,int size,int increment);

Status InitSqStack(SqStack *s,int size,int increment){
    s->elem=(ElemType *)malloc(size*sizeof(ElemType));
    if(s->elem==NULL)
        return -1;
    s->top=0;   //栈顶指针，指向的是最后一个有效元素的后一位
    s->size=size;
    s->increment=increment;
}