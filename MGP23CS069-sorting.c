/*
 *	SORTING ALGORITHMS
 *	
 *	By
 *	Hari Narayan M R
 *	CSE A 69 S3
 *	MGP23CS069
 *
 */

#include<stdio.h>
int main()
{
	int size;
	printf("\nEnter the number of elements:");
	scanf("%d", &size);
	int array[size];

	printf("\nEnter the elements:");
	for (int i = 0; i < size; i++)
		scanf("%d", &array[i]);

	printf("\nThe elements are\n");
	for (int i = 0; i < size; i++)
		printf("%d", array[i]);

	int choice;
	printf("\n1.Bubble Sort\t2.Insertion Sort\t3.Selection Sort");
	printf("\nEnter your choice");
	scanf("%d", &choice);

	switch(choice) {
		case 1:
			printf("\nBubble Sort\n");
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size - 1 - i; j++) {
					if (array[j] > array[j + 1]) {
						int temp = array[j];
						array[j] = array[j+1];
						array[j+1] = temp;
					}
				printf("\nPASS %d\n", j + 1);
				for (int k = 0; k < size; k++)
					printf("%d", array[k]);
				}
				printf("\n");
			}
			break;
		case 2:
			printf("\nInsertion Sort");
			for (int i = 0; i < size; i++) {
				int temp = array[i];
				int j = i - 1;
				while (j >= 0 && array[j] > temp){
					array[j+1] = array[j];
					j = j - 1;
				}
				array[j + 1] = temp;
				printf("\nPASS %d\n", i + 1);
				for (int k = 0; k < size; k++)
					printf("%d", array[k]);
			}
			break;
		case 3:
			printf("\nSelection Sort");
			for (int i = 0; i < size - 1; i++) {
				int min = i;
				for (int j = i + 1; j < size; j++) {
					if (array[j] < array[min]) {
						min = j;
					}
				}
				int temp = array[i];
				array[i] = array[min];
				array[min] = temp;
				printf("\nPASS %d\n", i + 1);
				for (int k = 0; k < size; k++)
					printf("%d", array[k]);
			}
			break;
	}
	printf("\n");
}
