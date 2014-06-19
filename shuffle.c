#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
void swap(int *p, int *q)
{
    int tmp;
    assert(p && q);
    tmp = *p;
    *p = *q;
    *q = tmp;
}
/*shuffle with O(n) time complexity*/
void shuffle(int a[], int n)
{
    int i, j;
    srand(time(NULL));
#if 0
    for (i=0;i<n-1;i++) {
        j = i+rand()/(RAND_MAX/(n-i)+1);
        swap(&a[i], &a[j]);
    }
#else
    for (i=n-1;i>0;i--) {
        j = rand()%(i+1);
        swap(&a[i], &a[j]);
    }
#endif
}
int main(int argc, char *argv[])
{
    int i, *p, n = (argc>1)? atoi(argv[1]):10; /*default 10*/
    p = malloc(sizeof(int)*n);
    assert(p);
    for (i=0;i<n;i++) p[i] = i;
    shuffle(p, n);
    for (i=0;i<n;i++) printf("%d%s", p[i], (i==n-1)?"\n":" ");
    free(p);
    return 0;
}
