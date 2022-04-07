#include <stdio.h>
#include "../../QG_Camp/Week3/LargeGroup/Sort/Headers/sort.h"
#include <stdlib.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
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
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
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
    /*����ϲ����������鲻�ȳ������*/
    if (i == mid + 1) {
        while(j <= end)
            temp[k++] = a[j++];
    }
    if (j == end + 1) {
        while (i <= mid)
            temp[k++] = a[i++];
    }
    /*д��ԭ����d*/
    for (j = 0, i = begin ; j < k; i++, j++) {
        a[i] = temp[j];
    }
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
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
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
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
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
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
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int* a, int size){
    int *b[10];    //�ֱ�Ϊ0~9�����пռ�
    int i;
    for (i = 0; i < 10; i++)
    {
        b[i] = (int *)malloc(sizeof(int) * (size + 1));
        b[i][0] = 0;    //indexΪ0����¼�������ݵĸ���
    }
    int pos;
    for (pos = 1; pos <= 31; pos++)    //�Ӹ�λ��ʼ��31λ
    {
        int i,j;
        for (i = 0; i < size; i++)
        {
            int num = GetNumInPos(a[i], pos);
            int index = ++b[num][0];
            b[num][index] = a[i];
        }
        for (i = 0, j =0; i < 10; i++)    //�ռ�
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
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
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