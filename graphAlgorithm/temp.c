#include <stdio.h>
// edge struct
struct edge{
 char x[5];
 char y[5];
};
typedef struct edge edge;

int main(){
    edge* edges=malloc(sizeof(edge)); 
    printf("size of edge struct is: %d ",sizeof(edge));
    strcpy(edges->x,"hello");
    printf("\n%s\n",edges->x);    
    return 0;
}
