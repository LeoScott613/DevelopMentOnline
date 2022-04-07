#include <stdio.h>
#include "../../QG_Camp/Week3/LargeGroup/Sort/Headers/sort.h"
#include <stdlib.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        for(j=i;j>0;j--){
            if(a[j]>=a[j-1]){
                break;
            }
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
    }
}
/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){
    if (begin >= end)
        return;
    int i=begin;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=end){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        } else{
            temp[k++]=a[j++];
        }
    }
    /*处理合并是左右数组不等长的情况*/
    if (i == mid + 1) {
        while(j <= end)
            temp[k++] = a[j++];
    }
    if (j == end + 1) {
        while (i <= mid)
            temp[k++] = a[i++];
    }
    /*写回原数组d*/
    for (j = 0, i = begin ; j < k; i++, j++) {
        a[i] = temp[j];
    }
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp){
    if(begin>=end)
        return;
    int mid=(begin+end)/2;
    MergeSort(a,begin,mid,temp);
    MergeSort(a,mid+1,end,temp);
    MergeArray(a,begin,mid,end,temp);
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end){
    if(begin>end)
        return;
    int i=begin,j=end,temp;
    int basic=a[begin];
    while(i!=j){
        while(a[j]>=basic&&j>i)
            j--;
        while(a[i]<=basic&&j>i)
            i++;
        if(j>i) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    a[begin]=a[i];
    a[i]=basic;
    QuickSort_Recursion(a,begin,i-1);
    QuickSort_Recursion(a,i+1,end);
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max){
    int i,min=a[0],len,j,s;
    int *b;
    for (i=1;i<size;i++){
        if(a[i]<min)
            min=a[i];
    }
    len=max-min+1;
    b=(int *)malloc((sizeof (int ) * len));
    for(i=0;i<len;i++){
        b[i]=0;
    }
    for(i=0;i<size;i++){
        b[a[i]-min]++;
    }
    for(j=0,i=0;j<len;j++){
        for(s=0;s<b[j];s++,i++){
            a[i]=min+j;
        }
    }
}


int GetNumInPos(int num,int pos)
{
    int temp = 1,i;
    for (i = 0; i < pos - 1; i++)
        temp *= 10;
    return (num / temp) % 10;
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size){
    int *b[10];    //分别为0~9的序列空间
    int i;
    for (i = 0; i < 10; i++)
    {
        b[i] = (int *)malloc(sizeof(int) * (size + 1));
        b[i][0] = 0;    //index为0处记录这组数据的个数
    }
    int pos;
    for (pos = 1; pos <= 31; pos++)    //从个位开始到31位
    {
        int i,j;
        for (i = 0; i < size; i++)
        {
            int num = GetNumInPos(a[i], pos);
            int index = ++b[num][0];
            b[num][index] = a[i];
        }
        for (i = 0, j =0; i < 10; i++)    //收集
        {
            int k;
            for (k = 1; k <= b[i][0]; k++)
                a[j++] = b[i][k];
            b[i][0] = 0;
        }
    }
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size){
    int i , j = 0, k = 0, t ;
    for(i = 0; i < size; i++) {
        t = a[i];
        a[i] = 2;
        if(t < 2)
            a[k++] = 1;
        if(t == 0)
            a[j++] = 0;
    }
}