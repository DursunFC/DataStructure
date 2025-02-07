#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};typedef struct node graplst;

graplst *addNode(graplst* rot, int value){
	graplst *nwnod=(graplst*)malloc(sizeof(graplst));
	rot->next=nwnod->data;
	nwnod->prev=rot->data;
	nwnod->data=value;
	return nwnod;
}

void main(){
}