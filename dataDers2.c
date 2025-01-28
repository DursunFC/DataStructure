#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	int height;
	struct node *left;
	struct node *right;
};
typedef struct node AVLTREE;

AVLTREE *new_node(int data) {
	AVLTREE p = (AVLTREE)malloc(sizeof(AVLTREE));
	p->data=data;
	p->left=p->right=NULL;
	p->height=0;
	return p;
}


int maxValue(int x, int y) {
	return x >= y ?x:y;
}


AVLTREE *rightRotate(AVLTREE *z) {
	AVLTREE* temp = z -> left;
	z -> left = temp -> right;
	temp -> right = z;
	z->height = maxValue(height(z->left), height(z->right)) +1;
	temp -> height = maxValue(height(temp->left), height(temp->right))+1;
	return temp;
}
AVLTREE *leftRotate(AVLTREE *z) {
	AVLTREE *temp = z->right;
	z->right=temp->left;
	temp->left=z;
	z->height=maxValue(height(z->left), height(z->right))+1;
	temp->height=maxValue(height(temp->left), height(temp->right))+1;
	return temp;
}
AVLTREE *leftRightRotate(AVLTREE *z) {
	z->left=leftRotate(z->left);
	return rightRotate(z);
}
AVLTREE *rightLeftRotate(AVLTREE *z) {
	z->right=rightRotate(z->right);
	return leftRotate(z);
}


int height(AVLTREE *root){
	if(root==NULL)
		return -1;
	else{
		int lheight, rheight;
		rheight=height(root->right);
		lheight=height(root->left);
		if(rheight>lheight)
			return rheight+1;
		else
			return lheight+1;
	}
}




AVLTREE *insertToAVL(int x, AVLTREE *tree)
{
	if(tree != NULL)
	{
		if(x<tree ->data)
		   tree->left=insertToAVL(x, tree->left);
		else if(x>tree->data)
		   tree->right=insertToAVL(x, tree->right);
		else
		   return tree;
		tree -> height = maxValue(height(tree->left), height(tree->right)) + 1;
		if((height(tree->left) - height(tree -> right)) > 1 && x < tree -> left -> data)
		   return rightRotate(tree);
		if(height(tree->left)- height(tree->right) >1 && x > tree -> left -> data) 
		   return leftRightRotate(tree);
		if(height(tree->left)- height(tree->right) < -1 && x > tree -> right -> data)
		   return leftRotate(tree);
		if(height(tree->left) - height(tree->right) < -1 && x < tree -> right -> data)
		   return rightLeftRotate (tree);
	}
	else
		tree = new_node(x);
    return tree;		
}
void inorder(AVLTREE* root) {
	if(root!=NULL) {
		inorder(root->left);
		printf("%4d", root->data);
		inorder(root->right);
	}
}




int main () {
	AVLTREE* root = NULL;
	root=insertToAVL(10,root);
	root=insertToAVL(20, root);
	root=insertToAVL(30, root);
	root=insertToAVL(40, root);
	root=insertToAVL(50, root);
	
	printf("\n");

	return 0;
}
