#include <stdio.h>
#include <stdlib.h> /*for rand()*/
#include <time.h>   /*for time()*/

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
	for (;p && n>0;n--,p++) {
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

/*Partial selection sort, O(kn) time, in place*/
int partialselect(int *p, int n, int k)
{
	int i, j, minidx, minval;
    for (i=0;i<=k;i++) {
        minidx = i, minval = p[i];
        for (j=i+1;j<n;j++) {
            if (minval > p[j]) minidx=j, minval=p[j];
        }
        swap(&p[i], &p[minidx]);
    }
    return p[k];
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
    printf("%dth=%d\n", k, partialselect(p, n, k-1));
	print_array(p, n);
    /*after full sorting, for manual review*/
    printf("sort\n");
	qsort(p, n, 4, cmp);
	print_array(p, n);
	return 0;
}

