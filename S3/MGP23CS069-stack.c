/*	
 *	STACK OPERATIONS
 *	
 *	By
 *	Hari Narayan M R
 *	CSE A 69 S3
 *	MGP23CS069
 *
 */
#include<stdio.h>
int size, value, top = -1;

void push(int stack[], int value) 
{
	if (top == size)
		printf("\n Stack Overflow");
	else 
	{
		top = top + 1;
		stack[top] = value;
		printf("\n Pushed Successfully \n");
	}
}

int pop(int stack[]) 
{
	if (top == -1)
		printf("\n Stack Underflow \n");
	else 
	{
		top = top - 1;
		printf("\n Popped Successfully \n");
		return stack[top];
	}
}

void display(int stack[]) 
{
	if (top == -1)
		printf("\n Stack empty \n");
	else 
	{
		printf("\n Stack");
		for (int i = 0; i <= top; i++)
			printf("\n %d", stack[i]);
		printf("\n");
	}
}

int main() 
{
	printf("Enter the number of elements: ");
	scanf("%d", &size);
	int stack[size], flag = 1;
	while (flag == 1) 
	{
		printf("\n What do you want to do?");
		printf("\n 1. Push an element ");
		printf("\n 2. Pop an element ");
		printf("\n 3. Display");
		printf("\n 4. Exit");
		printf("\n Enter your choice: ");
		int choice;
		scanf("%d", &choice);
		switch (choice) 
		{
			case 1:
				printf("\n Enter the number you'd like to push: ");
				scanf("%d", &value);
				push(stack, value);
				break;
			case 2:
				pop(stack);
				break;
			case 3: 
				display(stack);
				break;
			case 4:
				flag = 0;
		}
	}
	return 0;
}

