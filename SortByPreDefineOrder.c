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

/*O(n*m)*/
void SortByOrder1(void)
{
    int a1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}; /*sz=m*/
    int a2[] = {2, 1, 8, 3}; /*sz=n*/
    int i, j, k;
    for (i = k = 0; i < sizeof(a2)/sizeof(int); i++) {
        for (j = 0; j < sizeof(a1)/sizeof(int); j++) {
            if (a2[i] == a1[j]) swap(&a1[j], &a1[k]), k++;
        }
    }
    qsort(&a1[k], sizeof(a1)/sizeof(int)-k, sizeof(int), cmp);
    for (i = 0; i < sizeof(a1)/sizeof(int); i++) printf("%d ", a1[i]);
    puts("");
}

int main(void)
{
    SortByOrder1();
    return 0;
}

