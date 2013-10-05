/*
    This identifies a k-palindrome string. 
    Given the string and k.
*/

# include <stdio.h>
int check_palindrome(char * array,int k);
int main(){
    char c[200];
    int k;    
    printf("Please provide the string \n");
    fflush(stdout);    
    scanf("%s",c);
    printf("please provide the k. K has to be << 200 \n");
    fflush(stdout);
    scanf("%d",&k);
    printf("The string is %s \n",c);
    printf("The k value is %d \n",k); 
    int status=check_palindrome(c,k);
    if(status==0)
        printf( "yes");
    else
        printf( "no");

    

    return 0;
}


int check_palindrome(char *array, int k){
    int i,j,m;
    int palindrome_len=strlen(array)-k;
    char c,b;
    printf("The input string length is %d \n" , strlen(array+1));   
    printf("The palindrome length is %d \n", palindrome_len);
    for(i=0;strlen((array+i))>=k;i++){
        c=*(array+i);
        for(j=i+1;strlen((array+j))>=k-1;j++){
            b=*(array+j);
            for(m=j+1;*(array+m)!='\0';m++){
                char  *test_str=malloc((palindrome_len+1)); 
                sprintf(test_str,"%c%c%c",c,b,*(array+m));
                printf("%s\t",test_str);    
                int status=find_palindrome(test_str);
                if(status==0)
                    return status;
                free(test_str);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 1;
}


int find_palindrome(char * array){

    int from_first;
    int from_last;
    int mid=strlen(array)/2;
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
