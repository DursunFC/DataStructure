#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *previous;
};typedef struct node linkedList;

linkedList *addNodeTail (linkedList *node, int input){
	if(node->next!=NULL){
		linkedList *newNode= (linkedList*) malloc(sizeof(linkedList));
		newNode->data= input;
		node->next= newNode->data;
		return node;
	}
	else{
		puts("Next node isn't empty");
	}

}

linkedList *addNodeHead (linkedList *node, int input){
	if(node->previous!=NULL){
		linkedList *newNode= (linkedList*) malloc(sizeof(linkedList));
		newNode->data= input;
		node->previous= newNode->data;
		return node;
	}
	else{
		puts("Previous node isn't empty");
	}
}

void main(){
	int choice=0;
	linkedList *headRoot= (linkedList*) malloc(sizeof(linkedList));
	do{	int input=NULL;
		puts("Press 1 for start a list /nPress 2 for add node to tail n\ Press 3 for add node to head");
		switch(choice){
		case 1:	scanf("%d",&input);	
				addNodeTail(headNode,input);	break;
		case 2:		break;
		case 3:		break;
		default:		break;
		}
		scanf("%d",&choice);
	}while(choice>=0);
	
}

