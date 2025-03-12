/*
 *	BINARY SEARCH
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
	int num, key, l, r, mid, i;
	printf("Enter the number of elements:");
	scanf("%d", &num);
	int a[num];
	printf("Enter the elements in sorted order: ");
	for(i = 0; i < num; i++) scanf("%d", &a[i]);
	printf("Enter the value to be searched: ");
	scanf("%d", &key);
	l = 0;
	r = num - 1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (key == a[mid])
		{
			printf("value found at position %d \n", mid + 1);
			break;
		}
		else if (key > a[mid]) l = mid + 1;
		else r = mid - 1;
	}
	if (l > r) printf("value not found\n");
	return 0;
}


