/*
Implementation of quicksort.
Average case and best case if nlogn, but worst case is n^2.
*/

# include <stdio.h>

int main(){
    int a[10]={15,4,2,22,33,44,6,8,12,37};
    int array_size=sizeof(a)/sizeof(a[1]);
    quick_sort(a,array_size-1);
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
   if(right==left+1){
       if(*(a+left)>*(a+right))
            swap(a,left,right);
   }
   else{
       int pivot_value=*(a+pivot_index);
       // swap piviot vlaue with extreme right.
       swap(a,pivot_index,right);
       int i=0,big_index=-1;
       for(i=left;i<right;i++){
            if(a[i]>pivot_value){
                if(big_index==-1)
                    big_index=i;
            }
            else{
                if(big_index!=-1){
                    swap(a,big_index,i);
                    big_index++;
                }
            }
       }
       if(big_index!=-1){
            swap(*a,big_index,right);
            int pivot_index_recur=(left+(big_index-1))/2;
            _quick_sort(a,left,big_index-1,pivot_index_recur);
            pivot_index_recur=((big_index+1)+right)/2;
            _quick_sort(a,big_index+1,right,pivot_index_recur);
        }
        else{
            int pivot_index_recur=(left+(right-1))/2;
            _quick_sort(a,left,right-1,pivot_index_recur);
        }
    }   
}

void swap(int *a, int index1, int index2){
    int temp=*(a+index1);
    *(a+index1)=*(a+index2);
    *(a+index2)=temp;
}
