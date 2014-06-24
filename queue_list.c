/*queue by link list*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
    int data;
    struct node *next;
};
typedef struct {
    struct node *front; /*head*/
    struct node *rear;  /*tail*/
    int size;           /*elements*/
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
    return q->front->data;
}
void push(queue *q, int val)
{
    struct node *p = calloc(1, sizeof(struct node));
    assert(q && p);
    p->data = val;
    if (0 == q->size) q->front = q->rear = p;
    else q->rear->next = p, q->rear = p;
    q->size+=1;
}
void pop(queue *q)
{
    struct node *p;
    assert(q);
    if (empty(q)) return;
    p = q->front;
    if (1==q->size) q->front = q->rear = NULL;
    else q->front = q->front->next;
    q->size-=1; /*size must greter or equal than 1 before here*/
    free(p);
}
static void show(queue *q)
{
    struct node *p;
    assert(q);
    if (empty(q)) return;
    for (p=q->front;NULL!=p;p=p->next) printf("%d ", p->data);
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

