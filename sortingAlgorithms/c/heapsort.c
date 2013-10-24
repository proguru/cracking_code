# include<stdio.h>

int main(){
    int a[10]={5,15,24,1,9,103,10006,0,4,12};
    int i;
    for(i=0;i<10;i++){
        printf("%d\n",a[i]);
    }
    heapsort(a,sizeof(a)/sizeof(a[0]));
    return 0;

}

void heapsort(int a[],int length){

}
