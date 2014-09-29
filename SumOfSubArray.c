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


/*O(k^2*n^2)*/
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

/*O(n^2)*/
static void dynamic(int arr[], int n, int k)
{
  int col, row;
  int *dp = malloc(n*n*sizeof(int));
  assert(dp);
  for (row = 0, dp[0] = 0; row < n; row++) {
    for (col = 0; col < n; col++) {
      dp[row*n + col] += arr[row*n + col];
      if (col > 0) dp[row*n + col] += dp[(row)*n + (col-1)];
      if (row > 0) dp[row*n + col] += dp[(row-1)*n + col];
      if (row > 0 && col > 0) dp[row*n + col] -= dp[(row-1)*n + (col-1)];
      //printf("%d%s", dp[row*n + col], (col == n-1)?"\n":",");
    }
  }
  //printf("\n");
  for (row = 0; row < n-k+1; row++) {
    for (col = 0; col < n-k+1; col++) {
      int sum = dp[(row+k-1)*n + (col+k-1)];
      sum -= col? dp[(row+k-1)*n + (col-1)]: 0;
      sum -= row? dp[(row-1)*n + (col+k-1)]: 0;
      sum += (row && col)? dp[(row-1)*n + (col-1)]: 0;
      printf("%d%s", sum, (col == n-k)?"\n":",");
    }
  }
}

int main(void)
{
    naive((int *)arr1, 5, 3);
    naive((int *)arr2, 3, 2);
    dynamic((int *)arr1, 5, 3);
    dynamic((int *)arr2, 3, 2);
	return 0;
}
