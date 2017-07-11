#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode{
	int data;
	struct BSTNode* left;
	struct BSTNode* right;
}BSTNode;

BSTNode* getNewNode(int data){
	BSTNode* new = (BSTNode*)malloc(sizeof(BSTNode));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void Insert(BSTNode** root_ref, int data){
	BSTNode* root = *root_ref;
	// check if empty tree
	if(root == NULL){
		printf("Inserting in empty BST!\n");
		*root_ref = getNewNode(data);
		return;
	}
	if(data <= root->data){
		printf("Moving left \n");
		Insert(&(root->left), data);
	}
	else{
		printf("Moving right \n");
		Insert(&(root->right), data);
	}
}

BSTNode* Search(BSTNode* root, int data){
	if(root==NULL) return root;
	if(root->data == data) return root;
	// if data is less than root search in left subtree
	if(data <= root->data) {
		printf("Moving left \n");
		return Search(root->left, data);
	}
	//else search in right subtree
	return Search(root->right, data);

}

int main(int argc, char const *argv[])
{
	BSTNode *root = NULL;
	Insert(&root, 15);
	Insert(&root, 10);
	Insert(&root, 20);
	Insert(&root, 25);
	BSTNode* result = Search(root,20);
	if(result == NULL){
		printf("Not found\n");
	}
	else printf("%p\n",*result);
	//printf("%p\n", );


	return 0;

}