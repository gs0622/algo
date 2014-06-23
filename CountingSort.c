#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
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
    for (i=n-1;i>0;i--) {
        j = rand()%(i+1);
        swap(&a[i], &a[j]);
    }
}
void CountingSort(int arr[], int sz)
{
    int i, k, *cnt, *tmp;
    for (i=0,k=0;i<sz;i++) k = (arr[i]>k)? arr[i]: k; /*k=max of arr*/
    cnt = calloc(k+1, sizeof(int));
    tmp = malloc(sizeof(int)*sz);
    assert(cnt && tmp);
    for (i=0;i<sz;i++) cnt[arr[i]]+=1;
    for (i=1;i<=k;i++) cnt[i]+=cnt[i-1];
    for (i=0;i<sz;i++) tmp[i]=arr[i];
    for (i=sz-1;i>=0;i--) {
        arr[cnt[tmp[i]]-1]=tmp[i], cnt[tmp[i]]-=1;
    }
    free(cnt);
    free(tmp);
}
int main(int argc, char **argv)
{
	int i, n, *arr;
	n = (argc>1)? atoi(argv[1]) : 10;
    n = (n>100)? 100: n; /*max n limited in 100*/
	arr = malloc(sizeof(int)*n);
    for (i=0;i<n;i++) arr[i] = i;
    shuffle(arr, n);
	print_array(arr, n);
    CountingSort(arr, n);
	print_array(arr, n);
	free(arr);
	return 0;
}

