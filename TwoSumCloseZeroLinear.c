/* Two elements whose sum is closest to zero
  Example: 1 60 -10 70 -80 85
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int cmp(const void *p, const void *q)
{
    return *(int *)p - *(int *)q;
}
/*time: O(n)*/
void TwoSumLinear(int arr[], int sz)
{
    int i, j, k, mi, mj, min = abs(arr[0] + arr[sz-1]);
    qsort(arr, sz, sizeof(int), cmp);
    for (i = 0, j = sz - 1; i < sz; i++) {
        k = abs(arr[i] + arr[j]);
        if (k < min) min = k, mi = i, mj = j;
        else if (k > min) j--;
        else i++;
    }
    printf("%d + %d = %d\n", arr[mi], arr[mj], min);
}
int main(int argc, char *argv[])
{
    int i, n, *arr;
    if (1 == argc) return 0;
    n = argc - 1;
    arr = malloc(sizeof(int)*n);
    assert(arr);
    for (i = 0; i < n; i++) arr[i] = atoi(argv[i+1]);
    TwoSumLinear(arr, n);
    free(arr);
    return 0;
}

