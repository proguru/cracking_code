/*
    This is out of place heap sort algorithm.
*/

# include<stdio.h>
#define pq_size 10
struct priority_queue{
    int array[pq_size];
    int items;
};
typedef struct priority_queue priority_queue;
int main(){
    int a[10]={5,15,24,1,9,103,10006,0,4,12};
    int i;
    for(i=0;i<10;i++){
        printf("%d\n",a[i]);
    }
    heapsort(a);
    return 0;

}

void heapsort(int a[]){
    priority_queue q;
    ini_queue(&q);
    make_heap(&q,a);
}

void ini_queue(priority_queue *q){
    q->items=0;    
}
int parent(int node){
    return node/2;    
}
int left_child(int node){
    return 2*node;
}
int right_child(int node){
    return (2*node + 1);
}
void make_heap(priority_queue*q,int a[]){
    input_array_len=sizeof(a)/sizeof(a[1]);
    for(i=0;i<input_array_len;i++){
        insert_queue(q,a[i]);
    }

}

void insert_queue(priority_queue *q,int num){
    if(q->items>pq_size) printf("queue has overflowed.\n");
    else{
        q->items++;
        q->array[items-1]=num;
        bubble_up(q); 
    }

}

void bubble_up
