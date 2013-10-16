/*
Insert, free  and print a binary search tree.
Does not support deletion, duplicates.
The general bstNode datastructure is augmented. It has a 'parent' variable that allows easy deletion and it has height (longest path from parent to root) that is used to keep track of balencing factor. The balancing factor can be atmost (+ or -) 1. When ever the balancing factor is violated Rotation is kicked. The rotation might propogate back to the root, so balancing factor of atmost (+ or -) 1 can be maintained.: 
*/ 

#include <stdio.h>
    
#ifndef max
    #define max(a,b) (a > b ? a:b)
#endif

//Data structure.
struct bstNode{
    int id;
    int height;
    struct bstNode* parent;
    struct bstNode* left;
    struct bstNode* right;
};
typedef struct bstNode bstNode;
bstNode *head=NULL;

void insert_node(int );
void free_bst(bstNode *);
void print_bst(bstNode *temp);
void insert_recursive(bstNode*,int );
void delete_node();
int main(){
    char command[20];
    memset(command,'\0',20);
    while(strcmp(command,"quit")!=0){
        printf(">>> ");
        fflush(stdout);
        scanf("%s",command);
        if(strcmp(command,"insert")==0){
            int node;
            printf("Please provide the int node\n");
            fflush(stdout);
            scanf("%d",&node);
            insert_node(node);
        }
        else if(strcmp(command,"print")==0){
            printf("printing bst \n");
            if(head!=NULL)
                print_bst(head);
        }
        else if(strcmp(command,"free")==0){
            printf("Freeing the bst \n");
            free_bst(head);
            head=NULL;            
        }
        else{
        }
    }
    return 0;
}

void insert_node(int node){
    printf("Inserting node %d \n",node);
    if(head==NULL){
        head= malloc(sizeof (bstNode));
        head->id=node;
        head->height=0;
        head->parent=NULL;
        head->left=NULL;
        head->right=NULL;
    }
    else{
        insert_recursive(head,node);
    }
}

void print_bst(bstNode *temp){
    
    if(temp->left !=NULL){
        print_bst(temp->left);
    }
    if(temp->parent!=NULL)
        printf("Parent %d.....\t",temp->parent->id);
    else
        printf("parent NULL.....\t");
    printf("Node: %d..... \t",temp->id);
    printf("height: %d\n",temp->height);
    
    if(temp->right!=NULL){
        print_bst(temp->right);
    }
}
void free_bst(bstNode* temp){
    if(temp->left!=NULL){
        free_bst(temp->left);
    }
    if(temp->right!=NULL){
        free_bst(temp->right);
    }
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=NULL;
    free(temp);
    temp=NULL;
}



// insert recursive

void insert_recursive(bstNode*temp,int node){
   if(temp->id > node){ // go to left.
        if(temp->left!=NULL){
            
            insert_recursive(temp->left,node);
            // insert height
            int left,right;
            if(temp->right==NULL)
                right=-1;
            else
                right=temp->right->height;
            if(temp->left==NULL)
                left=-1;
            else
                left=temp->left->height;
            temp->height=1 + max(left,right); 
            
        }
        else{
                       
            bstNode* parent=temp;
            temp->left= malloc(sizeof(bstNode));
            temp=temp->left;
            temp->id=node;
            temp->height=0;
            temp->parent=parent;
            temp->left=NULL;
            temp->right=NULL;
            parent=NULL;
        }
    }
   else if(temp->id < node){
       if(temp->right !=NULL){
           insert_recursive(temp->right,node);
           // insert height
            int left,right;
            if(temp->right==NULL)
                right=-1;
            else
                right=temp->right->height;
            if(temp->left==NULL)
                left=-1;
            else
                left=temp->left->height;
            temp->height=1 + max(left,right); 
           
       } 
       else{
           bstNode*parent= temp;
           temp->right= malloc(sizeof(bstNode));
           temp=temp->right;
           temp->id=node;
           temp->height=0;
           temp->parent=parent;
           temp->left=NULL;
           temp->right=NULL;
           parent=NULL;
        }
        
   }
   else{
       printf("Duplicates not allowed.");
   }
}
