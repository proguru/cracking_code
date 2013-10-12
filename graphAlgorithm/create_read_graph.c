/*
    Creates a graph.
    Reads graph from a file, if provided else vertices and edges can be dynamically inserted.

*/
# include <stdio.h>
# include <stdlib.h>

#define vMax 100
// edge struct
struct edge{
 char x[5];
 char y[5]; 
};
typedef struct edge edge;
// edge node struct
struct edgeNode{
    char label[5];
    int degree;
    struct edgeNode* next;

};
typedef struct edgeNode edgeNode;

//graph struct
struct graph{
    edgeNode* uniqueVertex[vMax]; 
    int verticies;
    int edges;      
};
typedef struct graph graph;
graph *g=NULL;

//function declaration
void insertNode();
char* parse(char ,char ,char* );
edge* break_edges(char*);
void my_strncpy(char* dest, char*src,int len);
// main function
// if a file is provided node and edge info is taken from there.
int main(int argc, char * argv[]){
    printf("%d",argc);    
    printf("%s\n",argv[1]);
    char command[30];
    printf("please provide a command:\n");
    fflush(stdout);
    while(strcmp(command,"quit")!=0){
       printf(">>> ");
       fflush(stdout); 
       scanf("%s",command);
       if(strcmp(command,"insert")==0){
            insertNode();
       }
    }

    return 0;
}
// assistant functions
void insertNode(){
    char command [20];
    printf("Provide edge of the form (v,v)\n");
    fflush(stdout);
    scanf("%s",command);
    edge *edges=break_edges(command); 
    if(edges!=NULL)   
        free(edges);
}

edge* break_edges(char* command){
    char*label=NULL;
    char *label2=NULL;
    label=parse('(',',',command);
    label2=parse(',',')',command);
    if(label==NULL || label2==NULL)
        return NULL;        
    edge * edges=malloc(sizeof(edge));
    memset(edges->x,'\0',5);
    memset(edges->y,'\0',5);
    //my_strncpy(edges->x,label,4);
    //my_strncpy(edges->y,label2,4);
    free(label);
    free(label2);
    return edges;
}

char* parse(char begin, char end,char* command){
    int i=0,begin_num=-1,end_num=-1;
    int length=strlen(command);
    for (i=0;i<length;i++){
        if(*(command+i)==begin)
            begin_num=i+1;
        if(*(command+i)==end)
            end_num=i-1;
        if(begin_num!=-1 && end_num!=-1){
            break;
        } 

    }
    if(begin_num==-1 || end_num==-1) 
        return NULL;
    if(begin_num>end_num)
        return NULL;
         
    int size_cp=end_num-begin_num+2;
    char *label=malloc(size_cp*sizeof(char));
    strcnpy(label,command+begin_num,size_cp-1);
    printf("%s\n",label);
    return NULL; 
    
}

void my_strncpy(char* dest, char*src,int len){
    int i;
    for(i=0;i<len;i++){
        *(dest+i)=*(src+i);
    }
}
