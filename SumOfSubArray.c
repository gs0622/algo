/*Given an n x n square matrix, find sum of all sub-squares of size k x k*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

static void dynamic(int arr[], int n, int k)
{
  int col, row;
  int *dp = malloc(n*n*sizeof(int));
  assert(dp);
  for (row = 0; row < n; row++) {
    int sum = 0;
    for (col = 0; col < n; col++) {
      sum += arr[row*n + col];
      if (row > 0) {
          if (col > 0) sum += dp[(row-1)*n + col] - dp[(row-1) + col -1];
          else sum += dp[(row-1)*n + col];
      }
      dp[row*n + col] = sum;
      printf("%d%s", dp[row*n + col], (col == n-1)?"\n":",");
    }
    //printf("\n");
  }
}

int main(void)
{
#if 1
    dynamic((int *)arr1, 5, 3);
#else
    naive((int *)arr1, 5, 3);
    naive((int *)arr2, 3, 2);
#endif
	return 0;
}
