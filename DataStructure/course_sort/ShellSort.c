typedef struct RcdType{
    int key;
    //...
}RcdType;
typedef struct RcdSqList{
    RcdType *rcd;
    int length;
    //...
}RcdSqList;
/**
 * @param delta 该次希尔排序的增量
 */
// typedef void vodka;
void ShellInsert(RcdSqList *L,int delta){//一趟希尔排序,
    int i,j;
    for(i=1;i<L->length-delta;i++){
        if(L->rcd[i+delta].key<L->rcd[i].key){   //和直接插入排序相比，希尔排序的比较对象是i+delta位置和i位置的大小关系而直接插入排序比较的是i+1位置和i位置的
            L->rcd[0]=L->rcd[i+delta];
            j=i+delta;
            do{
                j-=delta;
                L->rcd[j+delta]=L->rcd[j];       //因为有增量所以位移也是带增量的
            }while(j-delta>0 && L->rcd[0].key<L->rcd[j-delta].key);
            L->rcd[j]=L->rcd[0];     //插入
        }
    }
}
void ShellSort(RcdSqList *L,int delta[],int delta_length){
    /*此处可以添加增量序列验证*/
    int k;
    for(k=0;k<delta_length;k++)      //循环取增量序列
        ShellInsert(L,delta[k]);     //每个增量都进行一次希尔排序
}