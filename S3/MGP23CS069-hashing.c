/*
 *	HASHING
 *	
 *	By
 *	Hari Narayan M R
 *	CSE A 69 S3
 *	MGP23CS069
 *
 */

#include<stdio.h>

void main()
{
	// getting size
	int size;
	printf("Enter the number of elements: ");
	scanf("%d", &size);
	int arr[size];

	// finding m
	int m;
	for (int i = 0; i < 5; i++)
		if ((size + i) % 5 == 0)
			m = size + i;

	printf("\nSize: %d\n", m);

	// configuring memory locations
	int mem[m];
	for (int i = 0; i < m; i++)
		mem[i] = -1;

	// reading elements
	printf("\nEnter the elements:");
	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	// setting up memory locations
	int k, loc;
	for (int i = 0; i < size; i++)	
	{
		k = arr[i];
		loc = k % m;
		while (mem[loc] != -1) {
			loc = (loc + 1) % m;
		}
		mem[loc] = k;
	}

	// printing hashtable
	for (int i = 0; i < m; i++) {
		if (mem[i] != -1)
			printf("%d\t%d\n", i, mem[i]);
		else if (mem[i] == -1)
			printf("%d\tempty\n", i);
	}
}
