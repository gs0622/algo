#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct queue {
	struct dlist *head;
	struct dlist *tail;
};

/* push to head */
void push(struct queue *q, int data)
{
	struct dlist *n = calloc(1, sizeof(struct dlist));
	n->data = data, n->next = q->head;
	if (q->head) q->head->prev = n;
	else q->tail = n;
	q->head = n;
}

/* enqueue to tail */
void enqueue(struct queue *q, int data)
{
	struct dlist *n = calloc(1, sizeof(struct dlist));
	n->data = data, n->prev = q->tail;
	if (NULL == q->head) q->head = n;
	if (q->tail) q->tail->next = n;
	q->tail = n;
}

/* pop from head */
int pop(struct queue *q)
{
	assert(q->head);
	struct dlist *n = q->head;
	int data = n->data;
	q->head = q->head->next;
	q->head->prev = NULL;
	free(n);
	return data;
}

/* dequeue from tail */
int dequeue(struct queue *q)
{
	assert(q->tail);
	struct dlist *n = q->tail;
	int data = n->data;
	q->tail = q->tail->prev;
	q->tail->next = NULL;
	free(n);
	return data;
}

void dump(struct queue *q)
{
	struct dlist *cur = q->head;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void rdump(struct queue *q)
{
	struct dlist *cur = q->tail;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->prev;
	}
	printf("\n");
}

int main(void)
{
	struct queue q = {};
	enqueue(&q, 4);
	enqueue(&q, 5);
	enqueue(&q, 6);
	dump(&q);
	rdump(&q);
	push(&q, 3);
	push(&q, 2);
	push(&q, 1);
	printf("dequeue: %d\n", dequeue(&q));
	printf("pop:     %d\n", pop(&q));
	dump(&q);
	rdump(&q);
	//printf("len=%d\n", length(head));
}
