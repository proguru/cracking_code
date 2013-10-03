/*
    Implements Merge sort algorithm.
    complexity: 2nlogn
*/

void merge_sort(int *s,int len);
void merge(int *a,int begin ,int middle, int end);
int main(){
    int array[8]={5,1,7,2,9,12,15,8};
    merge_sort(array,8);    
    return 0;
}
void merge_sort(int *a,int len){
    if(len!=0 && len!=1){ 
        merge(a,0,(0+len)/2,len-1);
        int i=0;
        for(i=0;i<len;i++){
            printf("positin %d is %d \n",i,*(a+i));
        }
    }
}


void merge(int *a,int begin, int middle, int end){
    if(begin==end)
        printf("positin %d is %d \n",begin,*(a+begin));
    else{
        // call left
        merge(a,begin,(0+middle)/2,middle);
        // call right
        merge(a,middle+1,(middle+end)/2,end);
        // let the merging begin
        
        int left_array_inc=begin;
        int right_array_inc=middle+1;
        int temp_array_len=end-begin+1;
        int *temp_array=malloc(temp_array_len * sizeof(int));
        int temp_array_inc=0;
        while((left_array_inc < middle+1) && (right_array_inc < end + 1)){
            if(a[left_array_inc]<a[right_array_inc]){
                temp_array[temp_array_inc]=a[left_array_inc];
                temp_array_inc++;
                left_array_inc++;
            }
            else{
                temp_array[temp_array_inc]=a[right_array_inc];
                temp_array_inc++;
                right_array_inc++;
            }           

        }
        
        
        // copy the remaining array.
        while(left_array_inc<middle+1){
            temp_array[temp_array_inc]=a[left_array_inc];
            left_array_inc++;
            temp_array_inc++;
        }
        
        while(right_array_inc<end+1){
            temp_array[temp_array_inc]=a[right_array_inc];
            right_array_inc++;
            temp_array_inc++;   
        }   
         
        // copy the array back into the merged array.
        int i;
        for(i=0;i<temp_array_len;i++){
            a[begin+i]=temp_array[i];

        }
        
        free(temp_array); 
    }        
}
