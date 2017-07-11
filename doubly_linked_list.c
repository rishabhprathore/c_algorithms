#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* createNode(int n){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = n;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
 
void insertAtHead(struct Node** head_ref, int n){
	struct Node* newNode = createNode(n);
	// check if list is empty
	if(*head_ref == NULL){
		*head_ref = newNode;
		return; 
	}
	// list is not empty
	struct Node* head = *head_ref;
	head->prev = newNode;
	newNode->next = head;
	*head_ref = newNode;
}

void insertAtTail(struct Node** head_ref, int n){
	struct Node* newNode = createNode(n);
	// check if list is empty
	if(*head_ref == NULL){
		*head_ref = newNode;
		return; 
	}
	struct Node* temp = *head_ref;
	while(temp->next!= NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

void printList(struct Node* head){
	printf("Printing list ---------------------------- \n");
	while(head!=NULL){
		printf("%d -> ",head->data);
		head = head->next;
	}
	printf("NULL\n");
}


void reversePrintList(struct Node* head){
	// go to end of list
	struct Node* temp = head;
	if(temp == NULL){
		return;
	}
	while(temp->next!=NULL){
		temp = temp->next;
	}
	printf("Printing list in reverse ---------------------------- \n");
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp = temp->prev;
	}
	printf("NULL\n");
}

int main(){

	struct Node* head = NULL;
	insertAtHead(&head, 2);
	insertAtHead(&head, 1);
	insertAtTail(&head, 3);
	printList(head);
	reversePrintList(head);
	return 0;
}

