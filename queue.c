// write a program to implement a queue using linked lsit
// date - 09/03/24
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;
 void delete()
 {
 	struct Node *ptr;
 	int item;
 	if(front==NULL){
 		printf("Underflow");
	 }
	 else{
	 	ptr = front;
	 	item=ptr->data;
	 	printf("deleted element is %d",item);
	 	front=front->next;
	 	free(ptr);
	 }
 };
 void display()
 {
 	struct Node *ptr=front;
 	if(front==NULL){
 		printf("Empty list");
	 }
	 else{
	   printf("Printing values");
	   while(ptr!=NULL){
	   	  printf("\n%d",ptr->data);
	   	  ptr=ptr->next;
	   }
	 }
 };

int main()
{
	int choice =0;
	do{
		printf("\n1-->To insert\n2->To delete\n3-->To display\n");
		printf("\nEnter the chocie: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: insert();
			break;
			
			case 2: delete();
			break;
			
			case 3: display();
			break;
			
			
			default: 
			break;
		}
	}while(choice=1);
	return 0;
 } 
 
 void insert()
 {
 	struct Node *ptr,*temp;
 	int item;
 	ptr = (struct Node *) malloc(sizeof(struct Node));
 	if(ptr==NULL){
 		printf("Overflow");
	 }
	 else{
	 	printf("Enter the element to insert: ");
	 	scanf("%d",&item);
	 	
	 	ptr->data = item;
	 	
	 	if(front==NULL){
	 	  front = ptr;
	 	  rear = ptr;
	 	  front->next = NULL;
	 	  rear->next = NULL;
		 }
	 	
	    else
		{
			rear->next= ptr;
	 	    rear = ptr;
	 	    rear->next = NULL;
		
	   }
	    printf("Item inserted");
	 }
 }
