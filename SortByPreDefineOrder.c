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

int BinarySearch(int arr[], int left, int right, int val)
{
    int mid = (left + right) / 2, tmp = arr[mid];
    if (left > right) return -1; /*not found*/
    if (tmp == val) return mid; /*found*/
    return (tmp > val)? BinarySearch(arr, left, mid-1, val):
        BinarySearch(arr, mid+1, right, val);
}

void SortByOrder2(void)
{
    int a1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}; /*sz=m*/
    int a2[] = {2, 1, 8, 3}; /*sz=n*/
    const int s1 = sizeof(a1)/sizeof(int);
    const int s2 = sizeof(a2)/sizeof(int);
    int i, j, k, r;
    qsort(a1, s1, sizeof(int), cmp);
    for (i = j = k = 0; i < s2; i++) {
        while (-1 < (r = BinarySearch(&a1[j], 0, s1-j, a2[i]))) {
            if (a1[j] == a1[r+j]) j++;
            else swap(&a1[j], &a1[r+j]), j++;
        }
        qsort(&a1[j], s1-j, sizeof(int), cmp);
    }
    for (i = 0; i < s1; i++) printf("%d ", a1[i]);
    puts("");
}

int main(void)
{
    SortByOrder1();
    SortByOrder2();
    return 0;
}

