/*Given an array A[] and a number x, check for pair in A[] with sum as x
  This method works in O(n) time if range of numbers is known
  Example: 1 4 6 10 45
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 10000
/*time: avg: O(nlgn), worse: O(n^2)*/
void TwoSumLinear(int arr[], int sz, int sum)
{
    int i, j, postive[MAX] = {}, negative[MAX]={};
    for (i = 0; i < sz; i++) {
        j = sum - arr[i];
        if ((j >= 0) && (1 == postive[j]))
            printf("%d %d\n", arr[i], j);
        else if ((j < 0) && (1 == negative[j * (-1)]))
            printf("%d %d\n", arr[i], j);
        if (arr[i] >= 0) postive[arr[i]] = 1;
        else negative[arr[i] * (-1)] = 1;
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
    TwoSumLinear(arr, n, sum);
    free(arr);
    return 0;
}

