#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *create_array(int n)
{
	int i, *p;

	p = malloc((sizeof(int))*n);
	srand((unsigned int)time(NULL));
	for (i=0; p && i<n; i++) {
		p[i] = rand()%100;
	}
	return p;
}

void print_array(int *p, int n)
{
	for (;p&&n>0;n--,p++) {
		printf("%.2d%s", *p, ((n-1)>0)? " ":"\n");
	}
}

void swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

int partition(int *p, int left, int right)
{
/* |    <= V  | V |   >= V    |
 * left         j             right
 */
#if 1
	int i = left, j = right+1, pivot = p[left];
	while (1) {
		while (p[++i] < pivot)
			if (i == right) break;
		while (p[--j] > pivot)
			if (j == left) break;
		if (i >= j) break;
		swap(&p[i],  &p[j]); /* p[i] >= pivot and p[j] <= pivot */
	}
	swap(&p[left], &p[j]); /* cross */
	return j;
#else
	int i, pivot, idx = left;
	pivot = p[idx];
	swap(&p[idx], &p[right]);
	for (i=left; i<right; i++) {
		if (p[i] < pivot) swap(&p[idx++], &p[i]);
	}
	swap(&p[right], &p[idx]);
	return idx;
#endif
}

/*Quick osrt, avg=best=O(nlgn) time, wrost in O(n^2)*/
void quicksort(int *p, int left, int right)
{
	int idx;
	if (left > right) return;
	idx = partition(p, left, right);
	quicksort(p, left, idx-1);
	quicksort(p, idx+1, right);
}

int main(int argc, char **argv)
{
	int n, *p;
	n = (argc>1)? atoi(argv[1]) : 10;
	p = create_array(n);
	print_array(p, n);
	quicksort(p, 0, n-1);
	print_array(p, n);
	free(p);
	return 0;
}
