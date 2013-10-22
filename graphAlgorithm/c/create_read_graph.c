/*
    Creates a graph.
    Reads graph from a file, if provided else vertices and edges can be dynamically inserted.

*/
# include <stdio.h>
# include <stdlib.h>

#define vMax 100
// bfs 
int parent[vMax+1];
int status[vMax+1];
// statuses of the status array.
int undiscovered=-1;
int discovered=0;
int processed=1;
int nill=-1;

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
graph* g;
//function declaration
void insertNode();
char* parse(char ,char ,char* );
edge* break_edges(char*);
void ini_graph();
void free_graph();
// main function
// if a file is provided node and edge info is taken from there.
int main(int argc, char * argv[]){
    printf("%d",argc);    
    printf("%s\n",argv[1]);
    ini_graph();
    char command[30];
    printf("please provide a command:\n");
    fflush(stdout);
    while(strcmp(command,"quit")!=0){
       printf("\n>>> ");
       fflush(stdout); 
       scanf("%s",command);
       if(strcmp(command,"insert")==0)
            insertNode();
       if(strcmp(command,"print")==0){
            printf("\n");
            print_graph();
       }
       if(strcmp(command,"free")==0){
           free_graph();
           if(queue_head!=NULL)
               free_queue(queue_head); 
       }
       if(strcmp(command,"search")==0){
            printf("Searching\n");
            fflush(stdout); 
            printf("%s",g->uniqueVertex[0]->label);
            bfs(g->uniqueVertex[0]->label);
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
    if(edges==NULL){
        printf("Should gracefully exit at this point");
        exit(1);
    }
    // insert vertex
    int status=search_node(edges->x);
    if(status==-1){
        edgeNode* temp=malloc(sizeof(edgeNode));
        memset(temp->label,'\0',5);
        strncpy(temp->label,edges->x,strlen(edges->x));
        temp->next=NULL;
        g->uniqueVertex[g->verticies]=temp;
        temp=NULL;
        g->verticies++;
    }
    status=search_node(edges->y);
    if(status==-1){
        edgeNode* temp=malloc(sizeof(edgeNode));
        memset(temp->label,'\0',5);
        strncpy(temp->label,edges->y,strlen(edges->y));
        temp->next=NULL;
        g->uniqueVertex[g->verticies]=temp;
        temp=NULL;
        g->verticies++;
    }
    // insert edge
    int i=0;
    for(i=0;i<g->verticies;i++){
        if(strcmp(edges->x,g->uniqueVertex[i]->label)==0){
            edgeNode* temp=g->uniqueVertex[i]->next;
            g->uniqueVertex[i]->degree++;
            if(temp==NULL){// First case only
                
                temp=malloc(sizeof(edgeNode));
                memset(temp->label,'\0',5);
                strncpy(temp->label,edges->y,strlen(edges->y));
                temp->next=NULL;
                g->uniqueVertex[i]->next=temp;
                temp=NULL;
            }
            else{ // Handle duplicate issues.
                edgeNode* _temp=malloc(sizeof(edgeNode));
                memset(_temp->label,'\0',5);
                strncpy(_temp->label,edges->y,strlen(edges->y));
                _temp->next=NULL;
                _temp->next=temp;
                g->uniqueVertex[i]->next=_temp;
                _temp=NULL;
                temp=NULL;
            }
        }
    }

    if(edges!=NULL)   
        free(edges);
}

edge* break_edges(char* command){//works
    char*label=NULL;
    char *label2=NULL;
    label=parse('(',',',command);
    label2=parse(',',')',command);
    if(label==NULL || label2==NULL)
        return NULL;        
    edge * edges=malloc(sizeof(edge));
    memset(edges->x,'\0',5);
    memset(edges->y,'\0',5);

    if(strlen(label)<5)
        strncpy(edges->x,label,strlen(label));
    else
        strncpy(edges->x,label,4);
    if(strlen(label2)<5)    
        strncpy(edges->y,label2,strlen(label2));
    else
        strncpy(edges->y,label2,4);
    free(label);
    free(label2);
    return edges;
}

char* parse(char begin, char end,char* command){// works
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
    memset(label,'\0',size_cp);
    strncpy(label,command+begin_num,size_cp-1);
    return label; 
    
}

void ini_graph(){
    g=malloc(sizeof(graph)); 
    g->verticies=0;
    g->edges=0;
    int i;
    for(i=0;i<vMax;i++)g->uniqueVertex[i]=NULL;
    
}
void print_graph(){
    int i;
    for(i=0;i<g->verticies;i++){
        printf("\n V:%s and edges are: ",g->uniqueVertex[i]->label);
        edgeNode* temp=g->uniqueVertex[i]->next;
        while(temp!=NULL){
            printf("%s,  ",temp->label);    
            temp=temp->next;        
        }
    }
}
int search_node(char* label){
    int i;
    for(i=0;i<g->verticies;i++){
        if(strcmp(label,g->uniqueVertex[i]->label)==0){
            return i;
        }
    }
    return -1;
}

void free_graph(){
    int i;
    for(i=0;i<g->verticies;i++){
        edgeNode*temp=g->uniqueVertex[i]->next;
        while(temp!=NULL){
            edgeNode* after_temp=temp->next;
            temp->next=NULL;
            free(temp);
            temp=NULL;
            temp=after_temp;
        }
        g->uniqueVertex[i]->next=NULL;
        free(g->uniqueVertex[i]);
        g->uniqueVertex[i]=NULL;
    }
    g->verticies=0;
    g->edges=0;
    printf("Freed all pointeres.");
}


void bfs(char* root_vertex){
    printf("%s\n",root_vertex);
    fflush(stdout);
    int i;
    for(i=0;i<g->verticies;i++){
        // notice that the i here corresponds to g->uniqueVertex[i]
        parent[i]=nill;
        status[i]=undiscovered; 
    }   
    status[search_node(root_vertex)]= discovered;
    enqueue(root_vertex);   
    qNode * temp=NULL;
    temp=dequeue();
    printf("%s",temp->label);
    fflush(stdout);
    while(temp!=NULL){
        int parent_index=search_node(temp->label);
        edgeNode* avl_temp=g->uniqueVertex[parent_index]->next;
        printf("parent %s\n",temp->label);
        fflush(stdout);
        while(avl_temp!=NULL){
            int index=search_node(avl_temp->label); 
            if(status[index]==undiscovered){
                status[index]=discovered;
                parent[index]=parent_index;
                enqueue(avl_temp->label);
                printf("child %s\n",avl_temp->label); 
                fflush(stdout);
            }                
            avl_temp=avl_temp->next;
        }
        temp->next=NULL;
        free(temp);
        temp=NULL;
       temp=dequeue();
    }
}

void dfs(){
/*
    Searching in Depth First Search Manner.:w
*/

}

