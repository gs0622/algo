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
	for (p;n>0;n--,p++) {
		printf("%.2d%s", *p, ((n-1)>0)? " ":"\n");
	}
}

static void merge(int *arr1, int arr1sz, int *arr2, int arr2sz, int *tmp)
{
    int i=0, j=0, k=0, m;
    while (i<arr1sz && j<arr2sz)
        tmp[k++] = (arr1[i]<arr2[j])? arr1[i++]:arr2[j++]; /*ascending*/
    while (i<arr1sz) tmp[k++]=arr1[i++];
    while (j<arr2sz) tmp[k++]=arr2[j++];
    for (m=0;m<(arr1sz+arr2sz);m++) arr1[m]=tmp[m];
}

/*arr=input array, tmp=O(n)temp array*/
void mergesort(int *arr, int sz, int *tmp) 
{
    if (sz>1) {
        int *arr1 = arr, arr1sz = sz/2, *arr2 = arr + arr1sz, arr2sz = (sz - arr1sz);
        mergesort(arr1, arr1sz, tmp);
        mergesort(arr2, arr2sz, tmp);
        merge(arr1, arr1sz, arr2, arr2sz, tmp);
    }
}

int main(int argc, char **argv)
{
	int n, *p, *q;
	n = (argc>1)? atoi(argv[1]) : 10;
	p = create_array(n), q = malloc(sizeof(int)*n); /*p=input, q=temp*/
	print_array(p, n);
	mergesort(p, n, q);
	print_array(p, n);
    free(p), free(q);
	return 0;
}
