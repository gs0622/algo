/*Given an n x n square matrix, find sum of all sub-squares of size k x k*/
#include <stdio.h>

int arr1[5][5] = { {1, 1, 1, 1, 1},
                   {2, 2, 2, 2, 2},
                   {3, 3, 3, 3, 3},
                   {4, 4, 4, 4, 4},
                   {5, 5, 5, 5, 5} };

int arr2[3][3] = { {1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9} };

static void naive(int arr[], int n, int k)
{
  int col, row;
  for (row = 0; row <= (n-k); row++) {
    for (col = 0; col <= (n-k); col++) {
      int i, j, sum = 0;
      for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
          sum += arr[(i+row)*n + j+col];
      printf("%d%s", sum, (col == n-k)?"":",");
    }
    printf("\n");
  }
}

int main(void)
{
#if 1
    naive((int *)arr1, 5, 3);
    naive((int *)arr2, 3, 2);
#else
  int col, row, n = 5, k = 3;
  for (row = 0; row <= (n-k); row++) {
    for (col = 0; col <= (n-k); col++) {
      int i, j, sum = 0;
      for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
          sum += arr1[i+row][j+col];
      printf("%d%s", sum, (col == n-k)?"":",");
    }
    printf("\n");
  }
#endif
	return 0;
}
