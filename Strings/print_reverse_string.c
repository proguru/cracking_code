/*
    prints the string in reversew
*/
# include <stdio.h>
void rev_print(char *s){
    if(*s!='\0'){
        rev_print(s + 1); 
        printf("%c", *s);
    } 
   
        
}
int main(){
    char a[10];
    memset(a,'\0',10);
    scanf("%s", a);
    printf("\n%c"); 
    printf("\n");
    rev_print(a); 
    return 0;
}
