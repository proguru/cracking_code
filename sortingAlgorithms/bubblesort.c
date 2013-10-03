/*
    Implements bubble sort:
    complexity: n^2

*/

#include <stdio.h>
void bubble_sort(int * array,int len);
int main(){
    int a[6]={2,4,1,9,8,0};
    bubble_sort(a,6);
    int i;    
    for(i=0;i<6;i++)
        printf("position: %d value: %d \n",i,a[i]);
    return 0;
}

void bubble_sort(int *array,int len){
    int i,j;
    for(i=0;i<len;i++){
        for(j=i;j<len;j++){
            if(*(array+i) > *(array+j)){
                int temp=*(array+j);
                *(array+j)=*(array+i);
               *(array+i)=temp; 
            }
            
        }
    }    


}
