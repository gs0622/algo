#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b)	((a>b)? a: b)
int maxsubarr(int *arr, int n)
{
	int i, maxsum = 0, cursum = 0;
	for (i = 0; i < n; i += 1) {
		cursum = MAX(cursum + arr[i], 0);
		maxsum = MAX(cursum, maxsum);
	}
	return maxsum;
}

/* O(n^2) */
int lis(int *arr, int n)
{
	int i, j, max = 0;
	int *lis = malloc(sizeof(int) * n);
	for (i = 0; i < n; i += 1) lis[i] = 1;
	for (i = 1; i < n; i += 1) {
		for (j = 0; j < i; j += 1) {
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
		}
	}
	for (i = 0; i < n; i += 1)
		if (max < lis[i]) max = lis[i];
	free(lis);
	return max;
}
int main(void)
{
	int arr[] = {-5 , 0, -4, 1, 4, 3, -2};
	//int arr[] = {3, 10, 2, 1, 20};
	printf("maxsubarr: %d\n", maxsubarr(arr, sizeof(arr)/sizeof(int)));
	printf("lis      : %d\n", lis(arr, sizeof(arr)/sizeof(int)));
}

