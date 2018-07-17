/* BFS adjacency list */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
	int data;
	struct node *next;
};
/* add edge into adjacency list: queue */
void add_v1(struct node **ref, int v)
{
	assert(ref);
	struct node dummy, *n = &dummy;
	struct node *m = calloc(1, sizeof(struct node));
	m->data = v;
	dummy.next = *ref;
	while (n->next) n = n->next;
	n->next = m;
	*ref = dummy.next;
}
/* add edge into adjacency list: stack */
void add_v2(struct node **ref, int v)
{
	assert(ref);
	struct node *m = malloc(sizeof(struct node));
	m->data = v, m->next = *ref;
	*ref = m;
}
struct queue {
	//int data;
	struct node *front, *rear;
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
int dequeue(struct queue *q)
{
	assert(q->front);
	struct node *n = q->front;
	int data = n->data;
	q->front = q->front->next;
	free(n);
	if (!q->front) q->rear = NULL; /* need? */
	return data;
}
int empty(struct queue *q)
{
	assert(q);
	return !(q->front);
}
int visited[10];
/* helper only, no check */
void visit(int s)
{
	visited[s] = 1;
	printf("%d ", s);
}
void bfs(struct node **list, int u)
{
	struct queue q = {};
	visit(u);
	enqueue(&q, u);
	while (!empty(&q)) {
		int v = dequeue(&q);
		struct node *n = list[v];
		while (n) {
			int w = n->data;
			if (0 == visited[w]) {
				visit(w);
				enqueue(&q, w);
			}
			n = n->next;
		}
	}
}
int main(void)
{
	int i;
	struct node *l[10] = {};
	for (i = 0; i < 10; i += 1) {
		visited[i] = 0;
	}
#define add	add_v2
	add(&l[0], 1);
	add(&l[0], 2);
	add(&l[1], 3);
	add(&l[1], 4);
	add(&l[2], 5);
	add(&l[2], 6);
	add(&l[2], 7);
	bfs(l, 0);
	printf("\n");
	return 0;
}
