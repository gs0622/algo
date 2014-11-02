/* Queue implementation in C style
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *back;
    int size;
};

int size(struct queue *q)
{
    return q->size;
}

int empty(struct queue *q)
{
    return (0 == size(q))? 1/*true*/: 0;
}

int front(struct queue *q)
{
    return q->front->data;
}

int back(struct queue *q)
{
    return q->back->data;
}

void push(struct queue *q, int v)
{
    struct node *tmp = calloc(1, sizeof(struct node));

    tmp->data = v;
    if (empty(q))
        q->front = q->back = tmp;
    else
        q->back->next = tmp, q->back = tmp;
    q->size += 1;
}

void pop(struct queue *q)
{
    struct node *tmp = q->front;
    if (empty(q)) return;
    else if (1 == size(q)) q->front = q->back = NULL;
    else q->front = q->front->next;
    q->size -= 1;
    free(tmp);
}

void show(struct queue *q)
{
    int i;
    struct node *tmp;
    printf("size: %d: ", q->size);
    for (i = 0, tmp = q->front; i < q->size; i++, tmp = tmp->next)
        printf("%d%s", tmp->data, (i == q->size - 1)? "": " ");
    if (0 == i) puts("null"); else puts("");
}

int main(void)
{
    struct queue q = {};
    push(&q, 1);
    push(&q, 7);
    push(&q, 2);
    show(&q);
    printf("front: %d, back=%d, pop\n", front(&q), back(&q));
    pop(&q);
    printf("front: %d, back=%d, pop x2\n", front(&q), back(&q));
    pop(&q);
    pop(&q);
    show(&q);
    return 0;
}

