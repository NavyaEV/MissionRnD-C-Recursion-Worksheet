/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
{4,6,7},
{1,3,8}
};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void print_spiral(int **, int, int, int, int *);

int *spiral(int rows, int columns, int **input_array)
{
	int *arr;
	if ((rows <= 0) || (columns <= 0) || (input_array == NULL))
		return NULL;
	arr = (int *)malloc((rows*columns)*sizeof(int));
	print_spiral(input_array, rows, columns, 0, arr);
	return &arr[0];
}
void print_spiral(int **mat, int m, int n, int k, int *arr) {
	static int index = -1;
	int i, j;
	if (m <= 0 || n <= 0)
		return;
	if (m == 1) {
		for (j = 0; j < n; j++)
		{
			arr[++index] = mat[k][k + j];
		}
		return;
	}
	if (n == 1) {
		for (i = 0; i < m; i++)
		{
			arr[++index] = mat[k + i][k];
		}
		return;
	}
	for (j = 0; j < n - 1; j++)
	{
		arr[++index] = mat[k][k + j];
	}
	for (i = 0; i < m - 1; i++)
	{
		arr[++index] = mat[k + i][k + n - 1];
	}
	for (j = 0; j < n - 1; j++)
	{
		arr[++index] = mat[k + m - 1][k + n - 1 - j];
	}
	for (i = 0; i < m - 1; i++)
	{
		arr[++index] = mat[k + m - 1 - i][k];
	}
	print_spiral(mat, m - 2, n - 2, k + 1, arr);
}