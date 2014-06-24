#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 10
typedef struct {
    int elements[MAX];
    int head; /*index of front emement*/
    int size; /*element size*/
} queue;
int empty(queue *q)
{
    assert(q);
    return (q->size==0)? 1/*true*/: 0/*false*/;
}
int front(queue *q)
{
    assert(q);
    if (empty(q)) {
        printf("queue empty\n");
        return 0;
    }
    return q->elements[q->head];
}
void push(queue *q, int val)
{
    assert(q);
    if (q->size >= MAX) {
        printf("queue full\n");
        return;
    }
    q->elements[(q->head+q->size)%MAX] = val; /*append to tail*/
    q->size+=1;
}
void pop(queue *q)
{
    assert(q);
    if (empty(q)) {
        printf("queue empty\n");
        return;
    }
    q->head=(q->head+1)%MAX, q->size-=1;
}
static void show(queue *q)
{
    int i, j;
    assert(q);
    for (i=0,j=q->head;i<q->size;i++) printf("%d ", q->elements[(j+i)%MAX]);
    printf("\n");
}
int main(void)
{
    int i, j;
    queue q = {};
    while (1) {
        printf("0. push 1.pop\n");
        if (scanf("%d", &i)!=1) break;
        if (0==i) printf("push? "), scanf("%d", &j), push(&q, j);
        if (1==i) printf("pop %d\n", front(&q)), pop(&q);
        show(&q);
    }
    return 0;
}

