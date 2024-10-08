#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node *head = NULL, *temp, *loc,  *p;

void createElement() {
	p = (struct node*) malloc(sizeof(struct node));
	int value;
	printf("\nEnter the value to be inserted: ");
	scanf("%d", &value);
	p->data = value;
}

void insertBeg() {
	createElement();
	if (head == NULL) 
	{
		head = p;
		p->link = NULL;
	}
	else 
	{
		p->link = head;
		head = p;
	}
}

void insertEnd() {
	createElement();
	if (head == NULL) 
	{
		head = p;
		p->link = NULL;
	}
	else 
	{
		temp = head;
		while(temp->link != NULL) // if you use temp != NULL, you are actually doing out of bounds memory access which can lead to segmentation fault.
			temp = temp->link;
		temp->link = p;
		p->link = NULL;
	}
}

void insertPos(int position) {
	createElement();
	if (head == NULL) 
	{
		head = p;
		p->link = NULL;
	}
	else 
	{
		temp = head;
		loc = head;
		loc = loc->link; // move loc to the front
		for(int i = 1; i < (position - 1); i++)
		{
			loc = loc->link; // loc at front
			temp = temp->link; // temp at back
		}
		temp->link = p;
		p->link = loc;
	}
}

void traverse() {
	for(temp = head; temp != NULL; temp = temp->link) // do not use temp->link != NULL, else you wont get last element
		printf("%d\t", temp->data);
	printf("\n");
}

void deleteBeg() {
	if (head == NULL)
		printf("\nList Empty");
	else
	{
		temp = head;
		head = head->link;
		free(temp);
	}
}

void deleteEnd() {
	if (head == NULL)
		printf("\nList empty");
	else
	{
		temp = head;
		loc = head;
		loc = loc->link;
		while (loc->link != NULL) { // do not use temp != NULL, can lead to segmentation faults
			loc = loc->link; // loc at the end
			temp = temp->link;
		}
		temp->link = NULL;
		free(loc);
	}
}

int main() {
	int choice, flag = 1;
	while(flag)
	{
		printf("\nEnter your options:");
		printf("\n1. Insert at Beginning\t2. Insert at End\t3. Insert at Position");
		printf("\n4. Delete at Beginning\t5. Delete at End\t6. Delete at Position");
		printf("\n7. Print List\t8. Exit");
		printf("\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: 
				insertBeg(); 
				break;
			case 2: 
				insertEnd(); 
				break;
			case 3:
				int position;
				printf("\nEnter the position you'd like to add the value to: ");
				scanf("%d", &position);
				insertPos(position);
				break;
			case 4:
				deleteBeg();
				break;
			case 5:
				deleteEnd();
				break;
			case 7:
				traverse();
				break;
			case 8:
				flag = 0;
				break;
			default: 
				printf("\nInvalid Input"); 
				flag = 0;
				break;
		}
	}


	printf("\n");
	return 0;
}
