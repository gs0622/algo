/*Count Inversions in an array
  Example: In: 2 4 1 3 5, out: 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int Merge(int arr1[], int s1, int arr2[], int s2, int aux[])
{
    int c, i, j, k;
    c = i = j = k = 0;
    while (i < s1 && j < s2) {
        //aux [k++] = arr1[i] < arr2[j]? arr1[i++]: arr2[j++], c+=s1-i; 
        if (arr1[i] < arr2[j])
            arr1[i++];
        else
            arr2[j++], c+=s1-i; 
    }
    while (i < s1) aux[k++] = arr1[i++];
    while (j < s2) aux[k++] = arr2[j++];
    for (i = 0; i < s1+s2; i++) arr1[i] = aux[i];
    return c;
}
int MergeSort(int arr[], int n, int aux[])
{
    int cnt = 0;
    if (n > 1) {
        int s1 = n/2, s2 = n-s1;
        int *arr1 = arr, *arr2 = arr+s1;
        cnt += MergeSort(arr1, s1, aux);
        cnt += MergeSort(arr2, s2, aux);
        cnt += Merge(arr1, s1, arr2, s2, aux);
    }
    return cnt;
}
int CountInversion(int arr[], int n)
{
    int cnt, *aux = malloc(sizeof(int)*n);
    assert(aux);
    cnt = MergeSort(arr, n, aux);
    free(aux);
    return cnt;
}
int main(int argc, char *argv[])
{
    int i, n, *arr;
    if (1 == argc) return 0;
    n = argc - 1;
    arr = malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) arr[i] = atoi(argv[i + 1]);
    printf("%d\n", CountInversion(arr, n));
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}

