/* BFS adjacency matrix */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int adj[10][10] = {}; 
/* add edge into adjacency matrix */
void add(int u, int v)
{
	adj[u][v] = 1;
}
struct node {
	int data;
	struct node *next;
};
struct queue {
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
void bfs(int u)
{
	struct queue q = {};
	visit(u);
	enqueue(&q, u);
	while (!empty(&q)) {
		int i, v = dequeue(&q);
		for (i = 0; i < 10; i++) {
			if (adj[v][i] == 1 && !visited[i]) {
				visit(i);
				enqueue(&q, i);
			}
		}
	}
}
int main(void)
{
	int i;
	for (i = 0; i < 10; i += 1) {
		visited[i] = 0;
	}
	add(0, 1);
	add(0, 2);
	add(0, 8);
	add(1, 3);
	add(1, 4);
	add(2, 5);
	add(2, 6);
	add(2, 7);
	bfs(0);
	printf("\n");
	return 0;
}
