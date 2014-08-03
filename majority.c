/*Majority Element by Moore’s Voting Algorithm*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int majority(int arr[], int sz)
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
int main(int argc, char *argv[])
{
    int i, n, m, *arr;
    if (1==argc) return 0;
    n = argc-1;
    arr = malloc(sizeof(int)*n);
    assert(arr);
    for (i=0;i<n;i++) arr[i]=atoi(argv[i+1]);
    m = majority(arr, n);
    printf("%d\n", m);
    return 0;
}

