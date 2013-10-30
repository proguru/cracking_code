/*
Implementation of quicksort.
Average case and best case if nlogn, but worst case is n^2.
*/

# include <stdio.h>

int main(){
    int a[10]={15,4,2,22,33,44,6,8,12,37};
    array_size=sizeof(a)/sizeof(a[1]);
    quick_sort(a,array_size);
    int i;
    printf("\n");
    for(i=0;i<array_size;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}

void quick_sort(int *a,int array_size){
    _quick_sort(a,0,array_size,array_size/2);
}

void _quick_sort(int *a,int left,int right,int pivot_index){
   pivot_value=*(a+piviot_index);
   // swap piviot vlaue with extreme right.
   int temp=a[right];
   a[right]=piviot_value;
   a[pivot_index]=temp;  
}
