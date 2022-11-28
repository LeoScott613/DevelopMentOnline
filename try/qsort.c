#include <stdio.h>
int parition(int arr[],int low,int high) {
    int support=arr[low];
    while(low<high) {
        while(low<high && arr[high]>=support) 
            high--;
        arr[low]=arr[high];

        while(low<high && arr[low]<=support) 
            low++;
        arr[high]=arr[low];
    }
    arr[low]=support;
    return low;
}
void qs(int arr[],int s,int t) {
    int pivot;
    if(s<t) {
        pivot=parition(arr,s,t);
        //qs(arr,s,pivot-1);
        //qs(arr,pivot+1,t);
    }
}
int main() {
    int arr[]={33,7,16,72,60,2,33,48};
    qs(arr,0,7);
    int i;
    for(i=0;i<8;i++)
        printf("%d,",arr[i]);
}