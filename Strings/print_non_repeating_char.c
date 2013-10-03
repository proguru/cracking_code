/*
   prints the first non-repeating character in a string.
   Note: The original array is modified, but that can be avoided
    by doing a deep coppy of the array before passing it to bubble sort
    
    Issues:
    Buffer overflow. 
*/

#include <stdio.h>
int main(){
   
    char array[10]; 
    scanf("%s",array);
    printf("Unsorted array: %s \n",array);
    bubble_sort(array,strlen(array));
    //printf("length of array is: %d \n",strlen(array)); 
    printf("sorted array: %s \n",array);
    print_first_non_repeat(array,strlen(array));   
    return 0;
}




void bubble_sort(char*array,int len){
    int i,j;
    for(i=0;i<len;i++){
        for(j=i;j<len;j++){
            if(*(array+i) > *(array+j)){
                char temp=*(array+j);
                *(array+j)=*(array+i);
               *(array+i)=temp; 
            }
        }
    }    
}

void print_first_non_repeat(char*a, int len){
    int i;
    printf("length of the array is : %d \n",len);
    for(i=0;i<len;i++){
        if(i==0){
            if(a[i+1]!=a[i])
                printf(" \n %c \n", a[i]);
        }
        else if(i==len-1){
            if((a[i-1])!=a[i])
                printf(" \n %c \n", a[i]);
        }
        else{
           if((a[i]!=a[i+1]) && a[i-1]!=a[i])
                printf(" \n %c \n", a[i]);
        }
        
    }


}
