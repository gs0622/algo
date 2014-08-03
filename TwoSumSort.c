/*Given an array A[] and a number x, check for pair in A[] with sum as x
  Example: -8 1 4 6 10 45
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int cmp(const void *p, const void *q)
{
    return (*(int *)p - *(int *)q);
}
/*time: avg: O(nlgn), worse: O(n^2)*/
void TwoSumSort(int arr[], int sz, int sum)
{
    int i, j, k;
    qsort(arr, sz, sizeof(int), cmp);
    for (i = 0, j = sz - 1; j > i; ) {
        k = arr[i] + arr[j];
        if (k == sum) printf("%d %d\n", arr[i], arr[j]), ++i, --j;
        else if (k < sum) ++i;
        else if (k > sum) --j;
        
    }
}
int main(int argc, char *argv[])
{
    int i, n, *arr;
    const int sum = 16;
    if (1 == argc) return 0;
    n = argc - 1;
    arr = malloc(sizeof(int)*n);
    assert(arr);
    for (i = 0; i < n; i++) arr[i] = atoi(argv[i+1]);
    TwoSumSort(arr, n, sum);
    free(arr);
    return 0;
}

