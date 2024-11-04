#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node *head1 = NULL, *head2 = NULL;

struct node* insertEnd(struct node* head, int value) {
	struct node* p = (struct node*) malloc(sizeof(struct node));
	p->data = value;
	p->link = NULL;

	if (head == NULL) {
		head = p;
	}

	else {
		struct node *temp = head;
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = p;
	}
	return head;
}

struct node* insertBeg(struct node* head, int value) {
	struct node* p = (struct node*) malloc(sizeof(struct node));
	p->data = value;
	p->link = NULL;

	if (head == NULL)
		head = p;
	else {
		p->link = head;
		head = p;
	}
	return head;
}

void compare(struct node *head, struct node *rhead) {
	int flag = 1;
	struct node *temp1 = head;
	struct node *temp2 = rhead;
	while (temp1 != NULL) {
		if (temp1->data != temp2->data) {
			flag = 0;
			break;
		}
		else {
			temp1 = temp1->link;
			temp2 = temp2->link;
		}
	}
	(flag == 1) ? printf("\nPalindrome") : printf("\nNot Palindrome");
}

void display(struct node *head) {
	if (head == NULL)
		printf("\nlist is empty.");
	else {
		struct node *temp = head;
		printf("\n");
		while (temp != NULL) {
			printf("%d\t", temp->data);
			temp = temp->link;
		}
	}
}

int main() {
	// int digit, digits;
	// printf("\nEnter the number of digits:");
	// scanf("%d", &digits);

	int num, digit;
	printf("\nEnter the number: ");
	scanf("%d", &num);
	while (num != 0) {
		digit = num % 10;
		head1 = insertEnd(head1, digit);
		head2 = insertBeg(head2, digit);
		num = num / 10;
	}

	// for (int i = 0; i < digits; i++) {
	// 	printf("Enter the digit %d: ", i + 1);
	// 	scanf("%d", &digit);

	// 	// the trick to reverse
	// 	head1 = insertEnd(head1, digit);
	// 	head2 = insertBeg(head2, digit);
	// }

	display(head1);
	display(head2);
	compare(head1, head2);

	printf("\n");
	return 0;
}

