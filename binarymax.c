#include <stdio.h>
int linearmax(int *arr, int left, int right)
{
	int i, max = arr[left];
	for (i = left; i < right; i += 1)
		if (arr[i] > max) max = arr[i];
	return max;
}
int binarymax_v1(int *arr, int left, int right)
{
	int mid, i_mid, max;
	max = arr[right];
	while (left <= right) {
		i_mid = (left + right) / 2;
		mid = arr[i_mid];
		if (mid > max) max = mid;
		if (i_mid == left) break;
		if (mid > arr[i_mid-1]) { /* shrink to right half */
			left = i_mid + 1;
		} else { /* mid < arr[i_mid-1]: shrink to left half */
			right = i_mid - 1;
		}
	}
	return max;
}
int binarymax_v3(int *arr, int left, int right)
{
	int M, L = left, R = right, max, mid, i_mid;
	max = arr[right];
	while (L <= R) {
		i_mid = (L+R)/2;
		mid = arr[i_mid];
		if (mid > max) max = mid;
		//printf("%d %d %d %d %d\n", L, R, i_mid, i_mid-1, mid);
		if (i_mid == L && arr[L] < arr[right]) L = R, R = right;
		else if (i_mid > left && mid > arr[i_mid-1]) L = i_mid + 1;
		else R = i_mid - 1;
	}
	return max;
}
#define MAX(a,b)	((a>b)? a: b)
int _binarymax_v4(int *arr, int lo, int mi, int hi)
{
	int max = arr[hi], mid = arr[mi];
	if (mid > max) max = mid;
	printf("0: %d %d %d %d\n", lo, mi, hi, mid);
	//if (mi == hi || mi == lo) return max;
	if (mid > arr[lo] && mid > arr[hi]) {
		printf("1: %d %d %d %d\n", lo, mi, hi, mid);
		max = MAX(max, _binarymax_v4(arr, mi+1, (mi+hi)/2, hi));
		max = MAX(max, _binarymax_v4(arr, lo, (lo+mi)/2, mi-1));
	} else if (mid < arr[lo]) {
		printf("2: %d %d %d %d\n", lo, mi, hi, mid);
		max = MAX(max, _binarymax_v4(arr, lo, (lo+mi)/2, mi-1));
	} else if (mid < arr[hi]) {
		printf("3: %d %d %d %d\n", lo, mi, hi, mid);
		max = MAX(max, _binarymax_v4(arr, mi+1, (hi+mi)/2, hi));
	}
	return max;
}
int binarymax_v4(int *arr, int left, int right)
{
	return _binarymax_v4(arr, left, (left+right)/2, right);
}
int binarymax_v2(int *arr, int left, int right)
{
	int mid, i_mid, max, ret;
	if (left > right) return arr[left];
	i_mid = (left + right) / 2;
	max = arr[right];
	mid = arr[i_mid];
	if (i_mid > left && mid > arr[i_mid-1]) {
	//if (mid > arr[i_mid-1]) {
		/*check left one and avoid out-of-bound access*/
		ret = binarymax_v2(arr, i_mid + 1, right);
		max = MAX(max, ret);
	//} else if (i_mid < right && mid > arr[i_mid+1]) {
	} else if (mid > arr[i_mid+1]) {
		ret = binarymax_v2(arr, left, i_mid - 1);
		max = MAX(max, ret);
	}
	return max;
}
#define ARR_SZ(a)	(sizeof(a)/sizeof(a[0]))
int main(void)
{
	int arr[] = {99999, 9999, 999, 99, 9};
	//int arr[] = {9, 99, 999, 9999, 99999};
	printf("li: %d\n", linearmax(arr, 0, ARR_SZ(arr)-1));
	printf("v1: %d\n", binarymax_v1(arr, 0, ARR_SZ(arr)-1));
	printf("v2: %d\n", binarymax_v2(arr, 0, ARR_SZ(arr)-1));
	printf("v3: %d\n", binarymax_v3(arr, 0, ARR_SZ(arr)-1));
	printf("v4: %d\n", binarymax_v4(arr, 0, ARR_SZ(arr)-1));
}
