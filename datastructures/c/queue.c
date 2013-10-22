# include <stdio.h>

struct qNode{
    char * label;
    struct qNode *next;
};

typedef struct qNode qNode;
qNode *back=NULL;
qNode *head=NULL;
void enqueue(char *label){
/*
    parameter you want to enqueue.
*/
    if(head==NULL){
        head=malloc(sizeof(qNode));
        head->label=malloc(sizeof(char)*strlen(label+1));
        memset(head->label,'\0',strlen(label)+1);
        strncpy(head->label,label,strlen(label));
        head->next=NULL;
        back=head;
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
    if(head==NULL)
        return NULL;
    qNode * temp=head;
    head=head->next;
    temp->next=NULL;
    if(head==NULL)
        back=NULL;
    return temp;

}
void print_queue(){
    qNode * temp=head;
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

int main(){
    char text[50];
    printf("Please provide a command\n");
    do{
        memset(text,'\0',50);
        printf(">>> ");
        fflush(stdout);
        scanf("%s",text);
        if(strcmp(text,"put")==0){
            printf("provide a label\n");
            fflush(stdout);
            char label[10];
            memset(label,'\0',10);
            scanf("%s",label);    
            enqueue(label);
        }
        else if(strcmp(text,"remove")==0){
            qNode* temp=dequeue();
            printf("The label is: %s",temp->label);
            free(temp);
        }
        else if(strcmp(text,"print")==0)
            print_queue();
        else{}
                    
    }while(strcmp(text,"quit")!=0);
    
    free_queue(head);
    return 0;
}
