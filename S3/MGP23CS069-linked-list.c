/*
 *	LINKED LIST
 *	
 *	By
 *	Hari Narayan M R
 *	CSE A 69 S3
 *	MGP23CS069
 *
 */

#include <stdio.h>
#include <stdlib.h>

int temp, head;

void insertBeginning(int value) {
	struct node *p;
	p = (struct node) malloc(sizeof(struct node));
	p->data = value;
	p->link = head;
	head = p;
}

struct node
{
	int data;
	struct node *link;
} *head = NULL;

void insertEnd(int value) {
	struct node *p;
	p = (struct node*) malloc(sizeof(struct node));
	if (head != NULL)
	{
		temp = head;
		while (temp.link != NULL)
			temp = temp->link;
		temp->link = p;
		p->data = value;
		p->link = NULL;
	}
	else
		insertBeginning();
}


void deleteBeginning() {
	if (head == NULL)
		printf("Empty list");
	else
		head = head->link;
}

void deleteEnd() {
	if (head == NULL)
		printf("Empty list");
	else {
		temp = head;
		loc = temp->link;
		while (loc->link != NULL) {
			temp = temp->link;
			loc = loc->link;
		}
		temp->link = NULL;
		free(loc);
	}
}

void deletePos() {
	if (head == NULL)
		printf("Empty list");
	else
	{
		temp = head;
		loc = temp->link;
		for (i = 1; i < (pos - 1); i++)
		{
			temp = temp->link;
			loc = temp->link;
		}
		printf("%d", loc->data);
		temp->link = NULL;
		free(loc);
	}
}

int main()
{
	printf("Enter the value of node");
	scanf("%d", &value);
	insertBeginning(value);
}
