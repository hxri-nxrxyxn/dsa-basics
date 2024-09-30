/*
 *	SPARSE MATRIX
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
	int row, column, i, j, k = 1, count = 0;
	printf("Enter the number of rows and columns: ");
	scanf("%d %d", &row, &column);
	int matrix[row][column];
	printf("Enter the elements of the matrix \n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			scanf("%d", &matrix[i][j]);
			if (matrix[i][j] != 0) count++;
		}
	}

	printf("The number of nonzero elements is: %d \n", count);
	printf("The matrix is: \n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}

	int sparsematrix[count][3];
	sparsematrix[0][0] = row;
	sparsematrix[0][1] = column;
	sparsematrix[0][2] = count;
	for (i = 0; i < row; i++) 
		for (j = 0; j < column; j++)
			if (matrix[i][j] != 0)
			{
				sparsematrix[k][0] = i;
				sparsematrix[k][1] = j;
				sparsematrix[k][2] = matrix[i][j];
				k++;
			}

	printf("The sparse matrix is: \n");
	for (i = 0; i < count + 1; i++) 
	{
		for (j = 0; j < 3; j++)
			printf("%d ", sparsematrix[i][j]);
		printf("\n");
	}
}
