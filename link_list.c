#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int new_data){
    //allocate new node
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    //put in data
    new->data = new_data;
    //return new node
    return new;
}

void print_list(struct Node* node){
    while (node!= NULL){
        printf("%d\n",node->data );
        node = node->next;
    }
}

void push(struct Node** head_ref, int new_data){
    //allocate the new node
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    //put in data
    new->data - new_data;
    //make next of new node as head
    new->next = *head_ref;
    //move the head to point to new node
    *head_ref = new;
}

void insertAfter(struct Node* prev_node, int new_data){
    //check if prev_node is NULL
    if(prev_node == NULL){
        printf("prev_node cannot be NULL\n");
        return;
    }
    //allocate new node
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    //put in data
    new->data = new_data;
    //make next of new node as next of prev_node
    new->next = prev_node->next;
    //move the next of prev_node as new_node
    prev_node->next = new;
}

void deleteNode(struct Node** head_ref, int key){
    //store head node
    struct Node* temp = *head_ref;
    struct Node* prev;
    //If head node itself holds the key to be deleted
    if(temp!= NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while(temp!=NULL && temp->data !=key){
        prev = temp;
        temp = temp->next;
    }
    //check if key was not present in link list
    if(temp == NULL) return;
    // unlink the node from the link list
    prev->next = temp->next;

    //free node
    free(temp);

    return;

}

void deleteAt(struct Node** head_ref, int position){

    //store head node
    struct Node* temp = *head_ref;
    //check if head is to be deleted
    if(position==0){
        //change head to next
        *head_ref = temp->next;
        free(temp);
        return;
    }
    int i=0;
    //traverse till position or end of list
    for(i=0; temp!=NULL && i<position-1; i++){
        temp = temp->next;
    }
    //check if position is more than length of list
    if(temp==NULL && temp->next ==NULL){
        return;
    }
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct Node* next = temp->next->next;
    // free the node to be deleted
    free(temp->next);
    //unlink the node from the link list
    temp->next = next;

}
void append(struct Node** head_ref, int new_data){

    //allocate node
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    //put data
    new->data = new_data;
    //new_node will be last so next has to be NULL
    new->next = NULL;
    //check if link list is empty
    if (*head_ref == NULL){
        //make new node as head
        *head_ref = new;
        return;
    }

    //traverse till the last node
    struct Node* temp = *head_ref;
    while(temp->next != NULL){
        temp = temp->next;
    }
    // change the next of last node to point to new node
    temp->next = new;
    return;
}

int i_length(struct Node* head){
    int count = 0;
    //check if link list is empty
    if(head== NULL){
        return 0;
    }
    //iterate till the end of list
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}

int r_length(struct Node* head){
    //check for base case
    if(head == NULL){
        return 0;
    }
    //recursive call
    return 1 + r_length(head->next);
}

int i_search_for_key(struct Node* head, int key){
    //initialise return variable to 0
    int check = 0;
    //iterate and compare with key
    while(head!=NULL){
        if (head->data == key){
            printf("key %d found\n", key);
            check =1;
            return check;
        }
        head=head->next;
    }
    printf("key %d not found\n", key);
    return 0;

}

int r_search_for_key(struct Node* head, int key){
    //base case
    if(head == NULL){
        return 0;
    }
    if(head->data == key){
        printf("key %d found\n", key);
        return 1;
    }
    return r_search_for_key(head->next, key);

        
    }   


void delete_first(struct Node** head_ref){
    //check if link list is empty
    if(*head_ref == NULL){
        return;
    }
    //store the element to be deleted
    struct Node* temp = *head_ref;
    //move the head to next position
    *head_ref = temp->next;
    //free the removed node(old head)
    free(temp);
}

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    
    //allocate 3 nodes in the heap
    printf("Length of the link list is : %d\n",i_length(head));
    head = createNode(0);
    printf("Length of the link list is : %d\n",r_length(head));
    append(&head, 1);
    //print_list(head);
    append(&head, 3);
    printf("Length of the link list is : %d\n",i_length(head));
    append(&head, 4);

    insertAfter(head->next, 2 );
    print_list(head);
    //deleteNode(&head, 1);
    //deleteNode(&head, 99);
    //deleteAt(&head, 0);
    deleteNode(&head, 4);
    delete_first(&head);
    print_list(head);
    printf("Length of the link list is : %d\n",r_length(head));
    printf("searching for key 99 : %d\n", r_search_for_key(head, 99));
    return 0;



}