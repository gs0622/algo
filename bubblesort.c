#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
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
	int tmp;
    assert(p&&q);
    tmp = *p;
	*p = *q;
	*q = tmp;
}
/*shuffle with O(n) time complexity*/
void shuffle(int a[], int n)
{
    int i, j;
    srand(time(NULL));
#if 0
    for (i=0;i<n-1;i++) {
        j = i+rand()/(RAND_MAX/(n-i)+1);
        swap(&a[i], &a[j]);
    }
#else
    for (i=n-1;i>0;i--) {
        j = rand()%(i+1);
        swap(&a[i], &a[j]);
    }
#endif
}
void bubblesort(int *p, int n)
{
	int i, j;
	for (i=n-1; i>0; i--)
		for (j=0; j<i; j++) {
			if (p[j]>p[j+1]) swap(&p[j], &p[j+1]); /*ascending*/
			//if (p[j]<p[j+1]) swap(&p[j], &p[j+1]); /*descending*/
		}
}
void OddEvenSort(int a[], int n)
{
    int i, sorted;
    while (1) {
        sorted = 1; /*true*/
        for (i=1;i<n-1;i+=2)
            if (a[i]>a[i+1]) swap(&a[i], &a[i+1]), sorted = 0;
        for (i=0;i<n-1;i+=2)
            if (a[i]>a[i+1]) swap(&a[i], &a[i+1]), sorted = 0;
        if (sorted) break;
    }
}
int main(int argc, char **argv)
{
	int n, *p;
	n = (argc>1)? atoi(argv[1]) : 10;
	p = create_array(n);
	//print_array(p, n);
	bubblesort(p, n);
	print_array(p, n);
    shuffle(p, n);
	//print_array(p, n);
    OddEvenSort(p, n);
	print_array(p, n);
	free(p);
	return 0;
}

