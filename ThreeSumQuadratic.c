/*test case:
-25 -10 -7 -3 2 4 8 10
-1 0 1 2 -1 -4
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int cmp(const void *p, const void *q)
{
    int m = *(int *)p, n = *(int *)q;
    return (m-n); /*+:greater, 0:equal, -:less*/
}
/*quadratic solution with unique triplet, time O(n^2)*/
void ThreeSumQuadratic(int arr[], int n)
{
    int i, j, k, a, b ,c, sum;
    int map[32]={}, ii=0, jj, hash, skip;/*assume n<32*/
    for (i=0;i<n-3;i++) {
        a=arr[i], j=i+1, k=n-1;
        while (k>j) {
            b=arr[j], c=arr[k];
            sum = a+b+c;
            if (sum==0) {
                hash = a*2+b*3+c*5; /*simple hash to skip duplicate*/
                for (jj=ii,skip=0;jj>=0;jj--) {
                    if (hash==map[jj]) {
                        skip=1;
                        break;
                    }
                }
                if (!skip) {
                    printf("%d %d %d\n", a, b, c);
                    map[ii++]=hash;
                }
                ++j, --k;
            }
            else if (sum<0) ++j;
            else /*sum>0*/ --k;
        }
    }
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
    qsort(arr, n, sizeof(int), cmp);
    //for (i=0;i<n;i++) printf("%d%s", arr[i], (i==n-1)?"\n":" ");
    ThreeSumQuadratic(arr, n);
    return 0;
}

