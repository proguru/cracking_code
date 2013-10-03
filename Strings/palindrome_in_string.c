/* 
  Is a palindrome 
  
*/

# include <stdio.h>

int main(){
    char array[256];
    scanf("%s",array);
    int status=find_palindrome(array);
    char pr_string[10]="false";
    if(status==0)
        pr_string="true";
    printf("status is %s",pr_string);
    return 0;
}

int find_palindrome(char * array){

    int from_first;
    int from_last;
    int mid=strlen(array);
    printf("The size of the array is %d \n",mid);
    int status=0;
    for(from_first=0,from_last=0;from_first<mid+1 && from_last>mid-1;from_first++,from_last--){
        if( array[from_first]!=array[from_last])
        {
            status=1;
            break;           
        }
    }
    
    return status; 

}
