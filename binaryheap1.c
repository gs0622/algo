#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b, *b = tmp;
}
void min_heapify(int a[], int sz)
{
	int i, parent, left, right;
	for (i = sz/2; i > 0; i -= 1) {
		parent = i - 1, left = 2*i - 1, right = 2*i ;
		if (a[parent] > a[left]) swap(&a[parent], &a[left]);
		if (right == sz) continue; /*complete-binary-tree w/ 2n nodes*/
		if (a[parent] > a[right]) swap(&a[parent], &a[right]);
	}
}
void max_heapify(int a[], int sz)
{
	int i, P, L, R;
	for (i = sz/2; i > 0; i -= 1) {
		P = i - 1, L = 2*i - 1, R = 2*i;
		if (a[P] < a[L]) swap(&a[P], &a[L]);
		if (R == sz) continue;
		if (a[P] < a[R]) swap(&a[P], &a[R]);
	}
}
int main(void)
{
	int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
	min_heapify(arr, sizeof(arr)/sizeof(arr[0]));
	printf("%d\n", arr[0]);
	max_heapify(arr, sizeof(arr)/sizeof(arr[0]));
	printf("%d\n", arr[0]);
	return 0;
}
