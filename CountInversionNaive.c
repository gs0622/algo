/*Count Inversions in an array
  Example: In: 2 4 1 3 5, out: 3
*/
#include <stdio.h>
#include <stdlib.h>
int CountInversionNaive(int arr[], int n)
{
    int i, j, c = 0;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) c++;
    return c;
}
int main(int argc, char *argv[])
{
    int i, n, *arr;
    if (1 == argc) return 0;
    n = argc - 1;
    arr = malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) arr[i] = atoi(argv[i + 1]);
    printf("%d\n", CountInversionNaive(arr, n));
    return 0;
}

