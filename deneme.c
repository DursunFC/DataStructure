#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *addhead(struct node *head,int key) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = key;
	temp -> next = head;
	head = temp;
	
	return head;
}

void main(){
	struct node *head;
	int a;
	scanf("%d",&a);
	addnode(head,a);
	
}
