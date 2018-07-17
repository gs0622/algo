void swap(int *a, int *b)
{}
int partition(int a[], int lo, int hi)
{
	int i = lo, j = hi+1, pivot = a[lo];
	while (1) {
		while (a[++lo] < pivot)
			if (lo == hi) break;
		while (a[--hi] > pivot)
			if (hi == lo) break;
		if (lo >= hi) break;
		swap(&a[lo], &a[hi]);
	}
	swap(&a[lo], &a[j]);
	return j;
}
