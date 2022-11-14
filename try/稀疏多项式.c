#include <stdio.h>
#include <stdlib.h>
typedef struct term{
    int p;
    int e;
}term;
typedef struct one{
    term *rcd;
    int length;
}one;
int init(one *o,int leng){
    o->rcd=(term*)malloc(sizeof(term)*leng);    //指针指数组，malloc生成sizeof(类型)*n大小的空间
    if(o->rcd==NULL)
        return -1;
    o->length=leng;   //这一步容易被忘记
    return 0;
}
int main(){

}
