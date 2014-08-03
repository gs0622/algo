#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*naive solution, time: O(n^3)*/
void ThreeSumNaive(int arr[], int n)
{
    int i, j, k, *p=arr;
    for (i=0;i<n-2;i++)
        for (j=i;j<n-1;j++)
            for (k=j;k<n;k++)
                if (p[i]+p[j]+p[k]==0 && i<j && j<k)
                    printf("%d %d %d\n", p[i], p[j], p[k]);
}
int main(int argc, char *argv[])
{
    int *arr, i, n;
    if (1==argc) return 0;
    n = argc-1;
    if (n<3) return 0;
    arr = malloc(sizeof(int)*n);
    assert(arr);
    for (i=0;i<n;i++) arr[i]=atoi(argv[i+1]);
    //for (i=0;i<n;i++) printf("%d%s", arr[i], (i==n-1)?"\n":" ");
    ThreeSumNaive(arr, n);
    free(arr);
    return 0;
}

