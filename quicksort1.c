#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void print_array(int *p, int n)
{
	for (;p&&n>0;n--,p++) {
		printf("%d\n", *p);
	}
}

void swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

int medianof3(int *p, int left, int right)
{
#if 0
	return (left + right) / 2;
#else
	int mid = (left + right) / 2;
	int idx[3] = {left, mid, right};
	if ((right - left + 1) < 3) return (p[left] < p[right])? left: right;
	if (p[right] < p[left]) swap(&idx[0], &idx[2]);
	if (p[mid]   < p[left]) swap(&idx[0], &idx[1]);
	if (p[right] < p[mid] ) swap(&idx[1], &idx[2]);
	printf("%d-%d-%d: %d-%d-%d: %d-%d-%d\n", left, mid, right, p[left], p[mid], p[right], p[idx[0]], p[idx[1]], p[idx[2]]);
	return idx[1];
#endif
}

int sanity(int *p, int left, int right)
{
	int i, issorted = 1;
	for (i=left; i<right; i++)
		if (p[i] > p[i+1]) {
			issorted = 0;
			break;
		}
	return issorted;
}

#define ALG 3
int partition(int *p, int left, int right)
{
/* |    <= V  | V |   >= V    |
 * left         j             right
 */
#if (ALG==1)
	int i=left+1, j, pivot = p[left];
	for (j=left+1; j<=right; j++) {
		if (p[j] < pivot) {
			swap(&p[j], &p[i]);
			i++;
		}
	}
	swap(&p[left], &p[i-1]);
	return i-1;
#endif
#if (ALG==2)
	int i=left+1, j, pivot = p[right];
	swap(&p[right], &p[left]);
	for (j=left+1; j<=right; j++) {
		if (p[j] < pivot) {
			swap(&p[j], &p[i]);
			i++;
		}
	}
	if(i<0) {
		printf("left=%d right=%d\n", left, right);
		assert(0);
	}
	swap(&p[left], &p[i-1]);
	return i-1;
#endif
#if (ALG==3)
	int idx = medianof3(p, left, right);
	int i=left+1, j, pivot = p[idx];
	swap(&p[idx], &p[left]);
	for (j=left+1; j<=right; j++) {
		if (p[j] < pivot) {
			swap(&p[j], &p[i]);
			i++;
		}
	}
	swap(&p[left], &p[i-1]);
	return i-1;
#endif
#if (ALG==4)
	int i = left, j = right+1, pivot = p[left];
	while (1) {
		while (p[++i] < pivot) if (i == right) break;
		while (p[--j] > pivot) if (j == left) break;
		if (i >= j) break;
		swap(&p[i],  &p[j]); 
	}
	swap(&p[left], &p[j]);
	return j;
#endif
}

//static long cmp = 0;

/*Quick osrt, avg=best=O(nlgn) time, wrost in O(n^2)*/
int quicksort(int *p, int left, int right)
{
	int idx, m = 0;
	if (left >= right) return 0;
	m = right - left + 1;
	idx = partition(p, left, right);
	//printf("m=%d idx=%d\n", m, idx);
	m += quicksort(p, left, idx-1);
	m += quicksort(p, idx+1, right);
	return m - 1;
}

int main(int argc, char **argv)
{
	int i, *p, n = 10000;
	long cmp = 0;

	p = malloc(n*sizeof(int));
	freopen("QuickSort.txt", "r", stdin);
	for (i=0; i<n; i++) scanf("%d", &p[i]);
	//swap(&p[0],  &p[n-1]);
	cmp += quicksort(p, 0, n-1);
	//print_array(p, n);
	if (!sanity(p, 0, n-1)) printf("failed\n");
	printf("-- %d\n", cmp);
	if (p) free(p);
	return 0;
}
