/* Find the two non-repeating elements in an array of repeating elements
   Example: 2 4 7 9 2 4
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void FindTwoNonRepeat(int arr[], int n, int *x, int *y)
{
    int i, j;
    assert(x && y);
    *x = *y = 0;
    for (i = 1, j = arr[0]; i < n; i++) j^=arr[i];
    j = ~(j-1) & j; /*get rightmost bit*/
    for (i = 0; i < n; i++)
        if (j & arr[i]) *x = *x ^ arr[i];
        else *y = *y ^ arr[i];
}
int main(int argc, char *argv[])
{
    int i, n, x, y, *arr;
    if (1 == argc) return 0;
    n = argc - 1;
    arr = malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) arr[i] = atoi(argv[i+1]);
    FindTwoNonRepeat(arr, n, &x, &y);
    printf("%d %d\n", x, y);
    return 0;
}

