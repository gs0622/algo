/*Sort an array according to the order defined by another array*/
#include <stdio.h>
#include <stdlib.h>

static void swap(int *p, int *q)
{
    int tmp = *p;
    *p = *q, *q = tmp;     
}

static int cmp(const void *p, const void *q)
{
    return (*(int *)p) - (*(int *)q);
}

int main(void)
{
    int a1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}; 
    int a2[] = {2, 1, 8, 3};
    int i, j, k;
    qsort(a1, sizeof(a1)/sizeof(int), sizeof(int), cmp);
    for (i = 0; i < sizeof(a1)/sizeof(int); i++) printf("%d ", a1[i]);
    puts("");
    for (i = j = k = 0; i < sizeof(a1)/sizeof(int); i++) {
        if (a1[i] == a2[j]) swap(&a1[i], &a1[k]), k++;
        if (a1[i] > a2[j]) j++;
    }
    for (i = 0; i < sizeof(a1)/sizeof(int); i++) printf("%d ", a1[i]);
    puts("");
}

