#include <stdio.h>
#include <stdlib.h>

int maxValue(int x, int y);

struct node {
	int data;
	int height;
	struct node *left;
	struct node *right;
};
typedef struct node AVLTREE;

AVLTREE *new_node(int data) {
	AVLTREE *p = (AVLTREE *)malloc(sizeof(struct node));
	p->data = data;
	p->left = p->right = NULL;
	p->height = 0;
	return p;
}

int maxValue(int x, int y) {
	return x >= y ? x : y;
}

int height(AVLTREE *root) {
	if (root == NULL)
		return -1;
	else {
		int lheight, rheight;
		rheight = height(root->right);
		lheight = height(root->left);
		if (rheight > lheight)
			return rheight + 1;
		else
			return lheight + 1;
	}
}

AVLTREE *rightRotate(AVLTREE *z) {
	AVLTREE *temp = z->left;
	z->left = temp->right;
	temp->right = z;
	z->height = maxValue(height(z->left), height(z->right)) + 1;
	temp->height = maxValue(height(temp->left), height(temp->right)) + 1;
	return temp;
}

AVLTREE *leftRotate(AVLTREE *z) {
	AVLTREE *temp = z->right;
	z->right = temp->left;
	temp->left = z;
	z->height = maxValue(height(z->left), height(z->right)) + 1;
	temp->height = maxValue(height(temp->left), height(temp->right)) + 1;
	return temp;
}

AVLTREE *leftRightRotate(AVLTREE *z) {
	z->left = leftRotate(z->left);
	return rightRotate(z);
}

AVLTREE *rightLeftRotate(AVLTREE *z) {
	z->right = rightRotate(z->right);
	return leftRotate(z);
}

AVLTREE *insertToAVL(int x, AVLTREE *tree) {
	if (tree != NULL) {
		if (x < tree->data)
			tree->left = insertToAVL(x, tree->left);
		else if (x > tree->data)
			tree->right = insertToAVL(x, tree->right);
		else
			return tree;

		tree->height = maxValue(height(tree->left), height(tree->right)) + 1;

		if ((height(tree->left) - height(tree->right)) > 1 && x < tree->left->data)
			return rightRotate(tree);
		if (height(tree->left) - height(tree->right) > 1 && x > tree->left->data)
			return leftRightRotate(tree);
		if (height(tree->left) - height(tree->right) < -1 && x > tree->right->data)
			return leftRotate(tree);
		if (height(tree->left) - height(tree->right) < -1 && x < tree->right->data)
			return rightLeftRotate(tree);
	} else
		tree = new_node(x);
	return tree;
}

void inorder(AVLTREE *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d", root->data);
		inorder(root->right);
	}
}

AVLTREE *findMin(AVLTREE *node) {
	AVLTREE *current = node;
	while (current->left != NULL)
		current = current->left;
	
	return current;
}


AVLTREE *deleteFromAVL(int x, AVLTREE *tree) {
	if (tree == NULL)
		return tree;

	if (x < tree->data)
		tree->left = deleteFromAVL(x, tree->left);
	else if (x > tree->data)
		tree->right = deleteFromAVL(x, tree->right);
	else {
			if (tree->left == NULL || tree->right == NULL) {
			AVLTREE *temp = tree->left ? tree->left : tree->right;
			if (temp == NULL) {
				temp = tree;
				tree = NULL;
			} else
				*tree = *temp;

			free(temp);
		} else {
			AVLTREE *temp = findMin(tree->right);
			tree->data = temp->data;
			tree->right = deleteFromAVL(temp->data, tree->right);
		}
	}
	if (tree == NULL)
		return tree;
	tree->height = 1 + maxValue(height(tree->left), height(tree->right));
	int balance = height(tree->left) - height(tree->right);
	if (balance > 1 && height(tree->left->left) >= height(tree->left->right))
		return rightRotate(tree);
	if (balance > 1 && height(tree->left->left) < height(tree->left->right)) {
		tree->left = leftRotate(tree->left);
		return rightRotate(tree);
	}
	if (balance < -1 && height(tree->right->left) <= height(tree->right->right))
		return leftRotate(tree);
	if (balance < -1 && height(tree->right->left) > height(tree->right->right)) {
		tree->right = rightRotate(tree->right);
		return leftRotate(tree);
	}

	return tree;
}

void main() {
	AVLTREE *root = NULL;
	root = insertToAVL(10, root);
	root = insertToAVL(20, root);
	root = insertToAVL(30, root);
	root = insertToAVL(40, root);
	root = insertToAVL(50, root);

	inorder(root);

	deleteFromAVL(20,root);
}
