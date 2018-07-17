#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
	int data; int visit; struct node *next;
};
/* add edge into adjacent list */
void add(struct node **ref, struct node *n)
{
	assert(n && ref);
	struct node *m = *ref;
	while (m->next) m = m->next;
	m->next = n;
}
/* dump list */
void dump_list(struct node *n)
{
	while (n) {
		printf("%d ", n->data);
		n = n->next;
	}
}
struct stack {
	struct node *top;
};
void push(struct stack *s, int data)
{
	assert(s);
	struct node *n = malloc(sizeof(struct node));
	n->data = data;
	n->next = s->top;
	s->top = n;
}
int pop(struct stack *s)
{
	assert(s && s->top);
	struct node *n = s->top;
	int data = n->data;
	s->top = n->next;
	free(n);
	return data;
}
int empty_s(struct stack *s)
{
	assert(s);
	return !(s->top);
}
struct queue {
	int data; struct node *front, *rear;
};
void enqueue(struct queue *q, int data)
{
	assert(q);
	struct node *n = calloc(1, sizeof(struct node));
	n->data = data;
	if (!q->front) {
		q->front = q->rear = n;
		return;
	}
	q->rear->next = n;
	q->rear = n;
}
void dequeue(struct queue *q)
{
	assert(q->front);
	struct node *n = q->front;
	q->front = q->front->next;
	free(n);
	if (!q->front) q->rear = NULL; /* need? */
}
int front(struct queue *q)
{
	assert(q && q->front);
	return q->front->data;
}
int empty_q(struct queue *q)
{
	assert(q);
	return !(q->front);
}
/* helper only, no check */
void dump_queue(struct queue *q)
{
	struct node *n = q->front;
	while (n) {
		printf("%d ", n->data);
		n = n->next;
	}
}
/* helper only, no check */
void visit(struct node *n)
{
	n->visit = 1;
	printf("%d ", n->data);
}
void dfs(struct node **list, struct node *u)
{
	struct stack s = {};
	visit(u);
	push(&s, u->data);
	while (!empty_s(&s)) {
		int v = pop(&s);
		struct node *n = list[v];
		while (n) {
			if (0 == n->visit) {
				push(&s, n->data);
			}
			n = n->next;
		}
		visit(n);
	}
}
void bfs(struct node **list, struct node *s)
{
	struct queue q = {};
	visit(s);
	enqueue(&q, s->data);
	while (!empty_q(&q)) {
		int u = front(&q);
		dequeue(&q);
		struct node *n = list[u];
		while (n) {
			if (0 == n->visit) {
				visit(n);
				enqueue(&q, n->data);
			}
			n = n->next;
		}
	}
}
int main(void)
{
	struct node v[10] = {};
	struct node *list[10] = {};
	struct queue q = {};
	int i;
	for (i = 0; i < 9; i += 1) {
		v[i].data = i;
		list[i] = &v[i];
	}
	add(&list[0], &v[1]);
	add(&list[0], &v[2]);
	add(&list[1], &v[3]);
	add(&list[1], &v[4]);
	add(&list[2], &v[5]);
	add(&list[2], &v[6]);
	bfs(list, &v[0]);
	printf("\n");
	for (i = 0; i < 9; i += 1) v[i].visit = 0;
	dfs(list, &v[0]);
	return 0;
}
