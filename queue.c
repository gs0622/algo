/* Queue implementation in C style
 */
#include <stdio.h>
#include <stdlib.h>
//#include <assert.h>

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

