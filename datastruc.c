#include<stdio.h>

struct node{
	int value; 
	struct node *next;
};
typedef struct node list;

int addFirstNode(list *a, int b){
	int *ptr;
	list *newNode;
	newNode->value= b;
	newNode->next= a->next;
	ptr=newNode;
	return *ptr;
}
/*
void printNode(node *a){
	while(a->next!= NULL){
		printf("%d",a->value);
		a->value= a->next;
	}
}
*/
main(){
	list *firstNode;
	int a,choice;
	do{
		puts("Select a function: \nPress 1 for add node(Head).\n ");
		scanf("%d",&choice);
		switch(choice){
		case 1: puts("Enter value");	scanf("%d",&a);	firstNode=addFirstNode(firstNode,a);	break;
//		case 2: printNode(firstNode); break;
		default:	puts("Invaild choice"); break;
		}
		puts("asdasd");
	}while(choice!=3);
}
