typedef struct RcdType {
    int *key;
    //...
}RcdType;
int Partition(RcdType rcd[],int low,int high) {
    rcd[0]=rcd[low];       //这是将low位的记录直接作为枢轴了，用0号位来备份它
    while(low<high) {
        while(low<high && rcd[high].key>=rcd[0].key)
            high--;
        rcd[low]=rcd[high];

        while(low<high && rcd[low].key<=rcd[0].key)
            low++;
        rcd[high]=rcd[low];
    }

    rcd[low]=rcd[0];
    return low;
}
void QuickSort(RcdType rcd[],int s,int t) {
    int pivotloc;
    if(s<t) {
        pivotloc=Partition(rcd,s,t);      //把rcd划分后获得枢轴
        QuickSort(rcd,s,pivotloc-1);        //把左边的进行快排
        QuickSort(rcd,pivotloc+1,t);        //把右边的进行快排
    }
}

// int pa(RcdType data[],int l,int h) {
//     data[0]=data[l];
//     while(l<h) {
//         while(l<h && data[h].key>=data[0].key)
//             h--;
//         data[l]=data[h];

//         while(l<h && data[l].key<=data[0].key)
//             l++;
//         data[h]=data[l];
//     }
//     data[l]=data[0];
//     return l;
// }
// void qs(RcdType data[],int l,int h) {
//     int p;
//     if(l<h) {
//         p=pa(data,l,h);
//         qs(data,l,p);
//         qs(data,p,h);
//     }
// }