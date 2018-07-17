int binarysearch(int arr[], int left, int right, int val)
{
	/* ......... mid .........*/
	/* val < ....... val > */
	if (left > right) return -1; /* cross after left == right */
	int mid = left + (right - left) / 2;
	if (val == arr[mid]) return mid;
	else if (val < arr[mid]) binarysearch(arr, left, mid-1, val);
	else binarysearch(arr, mid+1, right, val);
}
#include <stdio.h>
int main(void)
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6};
	printf("%3d\n", binarysearch(arr, 0, 6, 3));
	printf("%3d\n", binarysearch(arr, 0, 6, 2));
	printf("%3d\n", binarysearch(arr, 0, 6, 7));
	return 0;
}
