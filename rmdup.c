/*Algorithm: efficient way to remove duplicate integers from an array*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static void print_array(int arr[], int sz)
{
    int n = sz;
    assert(arr);
    for (;n>0;n--, arr++) {
        if (n!=sz) printf(" ");
        printf("%d", *arr);
    }
    printf("\n");
}

int rmdup_select(int arr[], int sz)
{
    int *cur, *end;
    assert(arr);
    for (cur=arr+1,end=arr+sz-1;arr<end; arr++,cur=arr+1) {
        while (cur<end) {
            if (*cur == *arr) *cur = *end--, sz--;
            else cur++;
        }
    }
    return sz;
}

static int cmp(const void *p, const void *q)
{
    int i=*((int *)p), j=*((int *)q);
    return (i-j);
}

int rmdup_sort(int arr[], int sz)
{
    int i, j, *tmp;
    assert(arr);
    tmp = malloc(sizeof(int)*sz);
    memcpy(tmp, arr, sz*sizeof(int));
    qsort(tmp, sz, 4, cmp);
    for (i=1,j=1,arr[0]=tmp[0];i<sz;i++) {
        if (tmp[i]==tmp[i-1]) continue;
        arr[j++]=tmp[i];
    }
    free(tmp);
    return j;
}

int main(int argc, char *argv[])
{
    const int arr[] =  {4, 8, 4, 1, 1, 2, 9};
    const int sz = sizeof(arr)/sizeof(int);
    int n, *dst = malloc(sizeof(int)*sz);
    memcpy(dst, arr, sz*sizeof(int));
    print_array(dst, sz);
    n = rmdup_select(dst, sz);
    printf("n=%d\n", n);
    print_array(dst, sz);
    print_array(dst, n);
    memcpy(dst, arr, sz*sizeof(int));
    n = rmdup_sort(dst, sz);
    printf("n=%d\n", n);
    print_array(dst, sz);
    print_array(dst, n);
    free(dst);
    return 0;
}

