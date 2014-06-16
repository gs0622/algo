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
#if 1
	for (;p&& n>0;n--,p++) {
		printf("%.2d%s", *p, ((n-1)>0)? " ":"\n");
	}
#endif
}

void swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

static int cmp(const void *p, const void *q) /*for qort()*/
{
	int i = *((int *)p), j = *((int *)q);
	/*printf("%d vs %d\n", i, j);*/
	return (i-j);
}

int partition(int *p, int left, int right)
{
	int i, pivot, idx = left;

	pivot = p[idx];
	swap(&p[idx], &p[right]);
	for (i=left; i<right; i++) {
		if (p[i] < pivot) {
			swap(&p[idx++], &p[i]);
		}
	}
	swap(&p[right], &p[idx]);
	return idx;
}

/*Quick selection, avg=best=O(n) time, wrost in O(n^2)*/
int quickselect(int *p, int left, int right, int k)
{
	int idx;
	if (left == right) return p[left];
	idx = partition(p, left, right);
    if (k==idx) return p[idx];
	else if (k<idx) return quickselect(p, left, idx-1, k);
	else return quickselect(p, idx+1, right, k);
}

int main(int argc, char **argv)
{
	int n, k, *p;
	n = (argc>1)? atoi(argv[1]) : 10;
    k = (argc>2)? atoi(argv[2]) : n/2;
    k = (k > n)? k%n:k;
	p = create_array(n);
    printf("n=%d k=%d\n", n, k);
	print_array(p, n);
	printf("%dth=%d\n", k, quickselect(p, 0, n-1, k-1));
    print_array(p, n);
    /*after full sorting, for manual review*/
    printf("sort\n");
	qsort(p, n, 4, cmp);
	print_array(p, n);
	free(p);
	return 0;
}

