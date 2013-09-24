# include <stdio.h>
struct list_node{
    int value;
    struct list_node *next;
};
typedef struct list_node list_node;
void insert(list_node *head,list_node*node){
    list_node* temp=head
    if(head==NULL){ // if there are no elements in the list.
        head=node;
    }
    else{
        prev=NULL
        // between head and tail.
        while (temp!=NULL){
            if(temp->value >= node->value){
                prev->next=node;
                node->next=temp;
                break;

            }
            else{
                prev=temp;
                temp=temp->next
            }

            
        }    
    }
}
void print_list(list_node * temp){
    if(temp==null)
        print("End");
    else
        print ("%d,"head->value);
        print_list(head->next);
}
void commands(){
}
int main(){
    printf( "Test case begining.");
    list_node* head=malloc(sizeof(list_node));
    printf("size of list_node is: %d",sizeof(list_node));
    commands() 
    return 0;
}
