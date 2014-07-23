#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 10
typedef struct {
    int data[MAX];
    int size; /*element size*/
} heap;
static void swap(int *p, int *q)
{
    int tmp;
    assert(p&&q);
    tmp=*p, *p=*q, *q=tmp;
}
static int less(int x, int y)
{
    return (x<y)? 1: 0;
}
static int greater(int x, int y)
{
    return (x>y)? 1: 0;
}
static int empty(heap *h)
{
    assert(h);
    return (0==h->size)? 1/*true*/: 0/*false*/;
}
static void show(heap *h)
{
    int i;
    assert(h);
    for (i=0;i<h->size;i++) printf("%d ", h->data[i]);
    printf("\n");
}
static void MinHeapify(heap *h)
{
    int i, left, right;
    assert(h);
    for (i=h->size/2;i>0;i--) {
        left = (2*i), right = (2*i+1);
        if (greater(h->data[i-1], h->data[left-1]))
            swap(&h->data[i-1], &h->data[left-1]);
        if ((0==h->size%2)&&(i==h->size/2))
            continue;/*skip complete binary tree empty right node*/
        if (greater(h->data[i-1], h->data[right-1]))
            swap(&h->data[i-1], &h->data[right-1]);
    }
}
static void MaxHeapify(heap *h)
{
    int i, left, right;
    assert(h);
    for (i=h->size/2;i>0;i--) {
        left = (2*i), right = (2*i+1);
        if (less(h->data[i-1], h->data[left-1]))
            swap(&h->data[i-1], &h->data[left-1]);
        if ((0==h->size%2)&&(i==h->size/2))
            continue;/*skip complete binary tree empty right node*/
        if (less(h->data[i-1], h->data[right-1]))
            swap(&h->data[i-1], &h->data[right-1]);
    }
}
void insert(heap *h, int val)
{
    assert(h);
    h->data[h->size++] = val;
//#define MINHEAP
#ifdef MINHEAP /*min-heap proprity queue*/
    MinHeapify(h);
#else
    MaxHeapify(h);
#endif
}
int delete(heap *h)
{
    int root;
    assert(h);
    root = h->data[0];
    h->data[0] = h->data[h->size-1];
    h->size--;
#ifdef MINHEAP /*min-heap proprity queue*/
    MinHeapify(h);
#else
    MaxHeapify(h);
#endif
    return root;
}
int main(void)
{
    int i, j;
    heap h = {};
    while (1) {
        printf("0. insert 1. delete(TBD)\n");
        if (scanf("%d", &i)!=1) break;
        if (0==i) printf("insert? "), scanf("%d", &j), insert(&h, j);
        else if (1==i) printf("delete %d\n", delete(&h));
        show(&h);
    }
    return 0;
}
