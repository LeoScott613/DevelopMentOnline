typedef struct rcdType{
    int key;
    //..
}RcdType;
typedef struct RcdSqList{
    RcdType *rcd;
    int size;
    int length;
    //...
}RcdSqList;
void InsertSort(RcdSqList *L){
    int i,j;
    for(i=1;i<L->length;i++){        //注意是i=1，因为0号位是空的
        if(L->rcd[i+1].key<L->rcd[i].key){     //发现无序区
            L->rcd[0]=L->rcd[i+1];  //将i+1位的数据保存在0号位，0号位之前是空的
            j=i+1;    //把j放在i+1的位置，因为要开始比较-移动了
            do{
                j--;
                L->rcd[j+1]=L->rcd[j];
            }while(L->rcd[0].key<L->rcd[j-1].key);     //这个do while循环做的事情是在比较和移动顺序表中的数值
            L->rcd[j]=L->rcd[0];       //把之前存的数据插入进有序区
        }
    }
}


















