#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};typedef struct node tre;

void *addNode(tre *rot, int value){
	tre *newnod=(tre*)malloc(sizeof(tre));
	newnod->data=value;
	rot->next=newnod->data;
	newnod->prev=rot->data;
}

void *delNode(tre *node){
	node->prev->next=node->next;
	node->next->prev=node->prev;
	free(node);
}

tre *findNod(tre *rot,int value){
	do{
		if(rot->data==value)	break;
		rot=rot->next;		
	}while(rot->next!=NULL);
	if(rot->data!=value){
		do{
			if(rot->data==value)	break;
			rot=rot->prev;		
		}while(rot->prev!=NULL);
	}
	return rot;
}

void main(){
	int choice=NULL;
	tre *root,*frst,*lst;
	puts("MENU\n Press 0 for quit\n Press 1 for create tree\n Press 2 for add new member to tree\n ");
	while(1){
		scanf("%d",&choice);
		switch(choice){
			case 0:	exit(1);
			case 1:	
			default: ;
		}
	}
	
}
