#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static int *create_array(int n)
{
	int i, *p;

	p = malloc((sizeof(int))*n);
	srand((unsigned int)time(NULL));
	for (i=0; p && i<n; i++) {
		p[i] = rand()%100;
	}
	return p;
}
static void print_array(int *p, int n)
{
	for (;p&&n>0;n--,p++) {
		printf("%.2d%s", *p, ((n-1)>0)? " ":"\n");
	}
}
static int less(int x, int y)
{
    return (x<y)? 1: 0;
}
static void swap(int *p, int *q)
{
    int tmp;
    tmp=*p, *p=*q, *q=tmp;
}
static void heapify(int arr[], int sz)
{
    int floor, left, right;
    for (floor=sz/2-1;floor>=0;floor--) {
        left =2*floor+1, right=left+1;
        if (less(arr[floor], arr[left]))
            swap(&arr[floor], &arr[left]);
        if ((right<sz) && less(arr[floor], arr[right]))
            swap(&arr[floor], &arr[right]);
    }
}
static void heapify1(int *arr, int sz)
{
	int i, left, right;
	for (i = sz/2; i > 0; i -= 1) {
		left = 2*i-1, right = 2*i;
		if (less(&arr[i-1], &arr[left]))
			swap(&arr[i-1], &arr[left]);
		if (right > sz) continue;
		if (less(&arr[i-1], &arr[right]))
			swap(&arr[i-1], &arr[right]);
	}
}
void heapsort(int arr[], int sz) 
{
    int i;
    for (i=sz;i>0;i--) {
        heapify(arr, i);
        swap(&arr[0], &arr[i-1]);
    }
}
int main(int argc, char **argv)
{
	int n, *p, *q;
	n = (argc>1)? atoi(argv[1]) : 10;
	p = create_array(n), q = malloc(sizeof(int)*n); /*p=input, q=temp*/
	print_array(p, n);
	heapsort(p, n);
	print_array(p, n);
    free(p), free(q);
	return 0;
}

