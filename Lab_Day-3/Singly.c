#include<stdio.h>
#include<stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *first,*last=NULL;

struct SLL* create_Node(int element){
    struct SLL *NewNode=(struct SLL*) malloc(sizeof(struct SLL));

    if(NewNode!= NULL)
    {
        NewNode->data=element;
        NewNode->next=NULL;
    }
    return NewNode;
    
}

void insert_at_beginning(int element){
    struct SLL *NewNode=create_Node(element);
    if(NewNode!= NULL)
    {
        if(first==NULL){
            first=last=NewNode;
        }
        else{
            NewNode->next=first;
            first=NewNode;
        }
        printf("%d INSERTED AT BEGINNING.\n",first->data);
    }

}

void insert_at_end(int element){
    struct SLL *NewNode=create_Node(element);
    if(NewNode!= NULL)
    {
        if(first==NULL){
            first=last=NewNode;
        }
        else{
            last->next=NewNode;
            last=NewNode;
        }
        printf("%d INSERTED AT END.\n",last->data);
    }

}

void traversal(){
    struct SLL *temp= first;
    if(first==NULL)
        printf("LIST IS EMPTY\n");
    else
    {
        while(temp!=NULL){
            printf("%d ->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }

}

void insert_at_pos(int element,int pos){
    struct SLL *NewNode=create_Node(element);
    if(pos==1)
        insert_at_beginning(element);

    else{
        struct SLL *temp=first;
        for(int i=1;i<pos-1 && temp->next != NULL;i++){
            
        }

    }
}


int main(){
    struct SLL list;
    insert_at_beginning(5);
    insert_at_end(4);
    traversal();
    insert_at_beginning(6);
    traversal();
    return 0;
}
