/* Two elements whose sum is closest to zero
  Example: 1 60 -10 70 -80 85
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*time: O(n^2)*/
void TwoSumNaive(int arr[], int sz)
{
    int i, j, k, mi, mj, min = abs(arr[0] + arr[sz-1]);
    for (i = 0; i < sz; i++)
        for (j = i+1; j < sz; j++) {
        k = abs(arr[i] + arr[j]);
        if (k < min) min = k, mi = i, mj = j;
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
    TwoSumNaive(arr, n);
    free(arr);
    return 0;
}

