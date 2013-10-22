# include <stdio.h>

struct qNode{
    char * label;
    struct qNode *next;
};

typedef struct qNode qNode;
qNode *back=NULL;
qNode *queue_head=NULL;

void enqueue(char *label){
/*
    parameter you want to enqueue.
*/
    if(queue_head==NULL){
        queue_head=malloc(sizeof(qNode));
        queue_head->label=malloc(sizeof(char)*strlen(label+1));
        memset(queue_head->label,'\0',strlen(label)+1);
        strncpy(queue_head->label,label,strlen(label));
        queue_head->next=NULL;
        back=queue_head;
    }
    else{
        back->next=malloc(sizeof(qNode));
        back=back->next;
        back->label=malloc(sizeof(char)*strlen(label+1));
        memset(back->label,'\0',strlen(label)+1);
        strncpy(back->label,label,strlen(label));
        back->next=NULL;
    }            
}
qNode * dequeue(){
    if(queue_head==NULL)
        return NULL;
    qNode * temp=queue_head;
    queue_head=queue_head->next;
    temp->next=NULL;
    if(queue_head==NULL)
        back=NULL;
    return temp;

}
void print_queue(){
    qNode * temp=queue_head;
    while(temp!=NULL){
        printf("%s\n",temp->label);
        temp=temp->next;
    }

}
void free_queue(qNode *q){
    if(q->next!=NULL){
        free_queue(q->next);
        q->next=NULL;
        free(q);
        q=NULL;
    }
    else
        free(q); 

}
