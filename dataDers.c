#include<stdio.h>
#include<stdlib.h>


int maxValue(int value1, int value2);

struct node{
	int data;
	int height;
	struct node *left;
	struct node *right;
};typedef struct node avlTree;

avlTree *new_node(int data) {
	avlTree *p = (avlTree)malloc(sizeof(avlTree));
	p->data=data;
	p->left=p->right=NULL;
	p->height=0;
	return p;
}


int height(avlTree *z) {
	if(z == NULL)
		return -1;
	else {
		int left_height, right_height;
		left_height = height(z -> left);
		right_height = height(z -> right);
		if(right_height > left_height)
			return right_height + 1;
		else
			return left_height + 1;
	}
}

int maxValue(avlTree* root) {
	if(root == NULL)	return 0;
	while(root -> right != NULL){	root = root -> right;	}
	return(root -> data);
}

avlTree *rightrotate(avlTree *z){
	avlTree *temp= z->left;
	z->left= temp->right;
	temp->right= z;
	z->height= maxValue(height(z->left),height(z->right))+1;
	temp->height= maxValue(height(temp->left),height(temp->right))+1;
	return temp;
}

avlTree *leftRotate(avlTree *z){
	avlTree *temp= z->right;
	z->right= temp->left;
	temp->left= z;
	z->height= maxValue(height(z->left),height(z->right))+1;
	temp->height= maxValue(height(temp->left),height(temp->right))+1;
	return temp;
}

avlTree *leftRightRotate(avlTree *z){
	z->left= leftRotate(z->left);
	return rightRotate(z);
}

avlTree *rightLeftRotate(avlTree *z){
	z->right= rightRotate(z->right);
	return leftRotate(z);
}

avlTree *insertToAVL(int x,avlTree *tree){
	if(tree!=NULL){
		if(x<tree->data)		tree->left= insertToAVL(x,tree->left);
		else if(x>tree->data)	tree->right= insertToAVL(x,tree->right);
		else					return tree;
		tree->height=maxValue(height(tree->left),height(tree->right))+1;
		if((height(tree->left)-height(tree->right))>1 && x<tree->left->data)	return rightRotate(tree);
		if((height(tree->left)-height(tree->right))>1 && x<tree->left->data)	return leftRightRotate(tree);
		if((height(tree->left)-height(tree->right))<-1 && x<tree->left->data)	return leftRotate(tree);
		if((height(tree->left)-height(tree->right))<-1 && x<tree->left->data)	return rightLeftRotate(tree);
		}
		else	tree=new_node(x);
	return tree;
}

void main(){
	
}
