/*
 *	LINEAR SEARCH
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
	int n, i, flag = 0, key, pos;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter the elements: ");
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("Enter the value to be searched: ");
	scanf("%d", &key);
	for (i = 0; i < n; i++)
	{
		if (key == a[i]) 
		{
			flag = 1;
			pos = i + 1;
			break;
		}
	}
	if (flag == 1) printf("Element found at position %d \n", pos);
	else printf("Element not found \n");
	return 0;
}

