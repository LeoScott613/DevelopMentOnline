//基数Radix指的是切割后的关键字的取值范围（若原关键字是0-999，切割后每一位是一个关键字，那么radix就是10）
#include <stdio.h>
typedef struct {
    int *keys;
}KeysRcdType;
typedef struct KeysSqList {
    KeysRcdType *rcd;
    int length;
    int size;
    int digitNum; //关键字位数
    int radix;    //关键字基数
}KeysSqList;
typedef int Status;
void RadixPass(KeysRcdType rcd[],KeysRcdType sup_rcd[],int n,int i,int count[],int pos[],int radix) {
    int k,j;
    for(k=1;k<=n;k++)
        count[rcd[k].keys[i]]++;      //芝士计数
    pos[0]=1;
    for(j=1;j<radix;j++)
        pos[j]=count[j-1]+pos[j-1];   //芝士求起始位置
    for(k=1;k<=n;k++) {               //芝士收集
        j=rcd[k].keys[i];
        sup_rcd[pos[j]++]=rcd[k];
    }
}

Status CountRadixSort(KeysSqList *L) {
    KeysRcdType *sup_rcd;//辅助空间，用于复制数据
    int i,j,*count,*pos;

    count=(int *)malloc(L->radix*sizeof(int));   //count的作用是统计每个关键字切割后的取值的个数（如345，346第一次切割后，有1个5和1个6）
    pos=(int *)malloc(L->radix*sizeof(int));     //用于确定各个子序列的起始位置
    sup_rcd=(KeysRcdType *)malloc((L->length+1)*sizeof(KeysRcdType));
    if(count==NULL || pos==NULL || sup_rcd==NULL)
        return -1;
    
    i=0;
    while(i<L->digitNum) {
        for(j=0;j<L->radix;j++)
            count[j]=0;
        
        if(0==i%2)
            RadixPass(L->rcd,sup_rcd,L->length,i++,count,pos,L->radix);
        else   
            RadixPass(sup_rcd,L->rcd,L->length,i++,count,pos,L->radix);
    }

    if(L->digitNum%2==1)
        for(j=1;j<=L->length;j++)       //0号位无意义
            L->rcd[j]=sup_rcd[j];
    
    return 1;
}