/*reference: http://en.wikipedia.org/wiki/Bogosort*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
static void print_array(int *p, int n)
{
	for (;p&&n>0;n--,p++) {
		printf("%.2d%s", *p, ((n-1)>0)? " ":"\n");
	}
}
static void swap(int *p, int *q)
{
	int tmp;
    assert(p&&q);
    tmp = *p;
	*p = *q;
	*q = tmp;
}
/*shuffle with O(n) time complexity*/
static void shuffle(int a[], int n)
{
    int i, j;
    srand(time(NULL));
    for (i=n-1;i>0;i--) {
        j = rand()%(i+1);
        swap(&a[i], &a[j]);
    }
}
static int inOrder(int arr[], int sz)
{
    int i;
    for (i=0;i<sz-1;i++)
        if (arr[i]>arr[i+1]) return 0/*false*/;
    return 1/*tre*/;
}
void BogoSort(int arr[], int sz)
{
    while (!inOrder(arr, sz)) shuffle(arr, sz);
}
int main(int argc, char **argv)
{
	int i, n, *arr;
	n = (argc>1)? atoi(argv[1]) : 10;
	arr = malloc(sizeof(int)*n);
    for (i=0;i<n;i++) arr[i] = i;
    shuffle(arr, n);
	print_array(arr, n);
    BogoSort(arr, n);
	print_array(arr, n);
	free(arr);
	return 0;
}

