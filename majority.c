/*Majority Element by Moore’s Voting Algorithm*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int FindMajority(int arr[], int sz)
{
    int i, maj=0,cnt=1;
    for (i=1;i<sz;i++) {
        if (arr[maj]==arr[i]) cnt++;
        else cnt--;
        if (0==cnt) {
            maj=i, cnt=1;
        }
    }
    return arr[maj];
}
int IsMajority(int arr[], int sz, int cand)
{
    int i, cnt=0;
    for (i=0;i<sz;i++)
        if (arr[i]==cand) cnt++;
    return (cnt>sz/2)? 1: 0;
}
int main(int argc, char *argv[])
{
    int i, n, m, *arr;
    if (1==argc) return 0;
    n = argc-1;
    arr = malloc(sizeof(int)*n);
    assert(arr);
    for (i=0;i<n;i++) arr[i]=atoi(argv[i+1]);
    m = FindMajority(arr, n);
    if (IsMajority(arr, n, m))
        printf("%d\n", m);
    else
        printf("no majority found\n");
    return 0;
}

