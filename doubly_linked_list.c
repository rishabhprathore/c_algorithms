#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct node{
    struct node* next;
    struct node* prev;
    int data;
}node;

node* createNode(int new_data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void push(node** head_ref, int new_data){
    node* new_node = createNode(new_data);
    new_node->next = *head_ref;
    if((*head_ref) != NULL){
        (*head_ref)->prev = new_node;
    } 
    (*head_ref) = new_node;
}

void insertAfter(node* prev_node, int new_data){
    if(prev_node==NULL){
        printf("passed prevoud node cannot be NULL!\n");
        return;
    }
    node* new_node = createNode(new_data);
    new_node->next=prev_node->next;
    new_node->prev=prev_node;
    prev_node->next=new_node;
    if(new_node->next != NULL){
        new_node->next->prev = new_node;
    }
}

void append(node** head_ref )

int main(int argc, char const *argv[])
{
    
    return 0;
}