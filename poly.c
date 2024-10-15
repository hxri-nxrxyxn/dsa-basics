#include<stdio.h>
#include<stdlib.h>

int sumcoeff;

struct node {
	int coeff;
	int exp;
	struct node* next;
};

struct node poly, temp;

struct node* insertNode(struct node* poly, int coeff, int exp)
{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->exp = exp;
	newNode->coeff = coeff;
	newNode->next = NULL;
	if (poly == NULL)
		return newNode;
	struct node* temp = poly;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
	return poly;
}

void display(struct node* poly) {
	while(poly != NULL)
	{
		printf("%dx^%d ", poly->coeff, poly->exp);
		poly = poly->next;
		if (poly != NULL)
			printf("+");
	}
}

struct node* addPolynomials(struct node* poly1, struct node* poly2)
{
	struct node* result = NULL;
	while(poly1 != NULL || poly2 != NULL)
	{
		if (poly1 == NULL)
		{
			result = insertNode(result, poly2->coeff, poly2->exp);
			poly2 = poly2->next;
		}
		else if (poly2 == NULL)
		{
			result = insertNode(result, poly1->coeff, poly2->exp);
		}
		else if (poly1->exp > poly2->exp)
		{
			result = insertNode(result, poly2->coeff, poly2->exp);
			poly1 = poly1->next;
		}
		else
		{
			sumcoeff = poly1->coeff + poly2->coeff;
			if (sumcoeff != 0)
			result = insertNode(result, sumcoeff, poly1->exp);
		}
		poly1 = poly1->next;
		poly2 = poly2->next;
	}
	return result;
}

int main()
{
	struct node *poly1 = NULL, *poly2 = NULL, *result = NULL;	
	int n, coeff, exp;
	printf("\nEnter the number of terms of first polynomial: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("\nEnter the coefficient and exponent of first polynomial: ");
		scanf("%d %d", &coeff, &exp);
		poly1 = insertNode(poly1, coeff, exp);
	}
	printf("\nEnter the number of terms of second polynomial: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("\nEnter the coefficient and exponent of second polynomial: ");
		scanf("%d %d", &coeff, &exp);
		poly2 = insertNode(poly2, coeff, exp);
	}
	printf("\nFirst polynomial is: ");
	display(poly1);
	printf("\nSecond polynomial is: ");
	display(poly2);
	printf("\n");
	return 0;
}

