/* Queue implementation in C style
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *back;
};

void size(struct queue *q)
{}
void empty(struct queue *q)
{}
int front(struct queue *q)
{ return 0; }
int back(struct queue *q)
{ return 0; }
void push(struct queue *q, int v)
{}
void pop(struct queue *q)
{}

