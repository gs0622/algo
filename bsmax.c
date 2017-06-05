#include <stdio.h>
#define MAX(a,b)	((a>b)? a: b)
#define ARR_SZ(a)	(sizeof(a)/sizeof(a[0]))
int ls_max(int *arr, int lo, int hi)
{
	int i, max = arr[hi];
	for (i = lo; i < hi; i += 1) {
		if (max < arr[i]) max = arr[i];
	}
	return max;
}
int bs_max(int *arr, int lo, int hi)
{
	int mi = (lo+hi)/2, max = arr[hi];
	if (lo == hi) return max;
	if (arr[lo] >= arr[mi] && arr[mi] > arr[hi]) {
		/* descending */
		max = MAX(max, bs_max(arr, lo, (mi>lo)? mi-1: mi));
	} else if (arr[hi] > arr[mi] && arr[mi] >= arr[lo]) {
		/* ascending */
		max = MAX(max, bs_max(arr, (mi<hi)? mi+1: mi, hi));
	} else {
		/* fall apart, peak in both sides */
		max = MAX(max, bs_max(arr, lo, (mi>lo)? mi-1: mi));
		max = MAX(max, bs_max(arr, (mi>hi)? mi+1: mi, hi));
	}
	return max;
}
int test(int *arr, int sz)
{
	static int cnt = 0;
	int max = ls_max(arr, 0,  sz-1);
	int ans = bs_max(arr, 0, sz-1);
	printf("%d: %10d %10d : %s\n", cnt++, max, ans, (max == ans)? "pass": "fail");
}
int main(void)
{
	int arr1[] = {9999 , 999, 99, 9};
	int arr2[] = {99999, 9999, 999, 99, 9};
	int arr3[] = {9, 99, 999, 9999};
	int arr4[] = {9, 99, 999, 9999, 99999};
	int arr5[] = {9999, 99999, 999, 99, 9};
	int arr6[] = {999, 9999, 99999, 999, 99, 9};
	test(arr1, ARR_SZ(arr1));
	test(arr2, ARR_SZ(arr2));
	test(arr3, ARR_SZ(arr3));
	test(arr4, ARR_SZ(arr4));
	test(arr5, ARR_SZ(arr5));
	test(arr6, ARR_SZ(arr6));
}
