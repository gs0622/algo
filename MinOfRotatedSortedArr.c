#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*Assume: sorted array but rotated, no duplicate element*/
int FindMin(int arr[], int left, int right)
{
    int mid = (left+right)/2;
    if (1==right-left) return (arr[left]>arr[right])?arr[right]:arr[left];
    if (arr[mid]<arr[right]) return FindMin(arr, left, mid);
    else return FindMin(arr, mid, right);
}

int main(int argc, char *argv[])
{
    int *arr, n = argc-1, i;
    if (0==n) return 0;
    arr = malloc(sizeof(int)*n);
    assert(arr);
    for (i=0;i<n;i++) arr[i]=atoi(argv[i+1]);
    printf("%d\n", FindMin(arr, 0, n-1));
    free(arr);
    return 0;
}

