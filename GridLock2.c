#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int adj[9][9] = {
    { 0, 1, 0, 1, 1, 0, 0, 0, 0},
    { 1, 0, 1, 1, 1, 1, 0, 0, 0},
    { 0, 1, 0, 0, 1, 1, 0, 0, 0},
    { 1, 1, 0, 0, 1, 0, 1, 0, 0},
    { 1, 1, 1, 1, 0, 1, 1, 1, 1},
    { 0, 1, 1, 0, 1, 0, 1, 1, 1},
    { 0, 0, 0, 1, 1, 0, 0, 1, 1},
    { 0, 0, 0, 1, 1, 1, 1, 0, 1},
    { 0, 0, 0, 0, 1, 1, 0, 1, 0}
};

int visit[9];
int parent[9];
int pattern = 0;

struct node {
	int data; struct node *next;
};
struct queue {
	struct node *front, *rear;
	int sz;
};
void enqueue(struct queue *q, int data)
{
	assert(q);
	struct node *n = malloc(sizeof(struct node));
	n->data = data, n->next = NULL;
	q->sz++;
	if (!q->front) {
		q->front = q->rear = n;
		return;
	}
	q->rear->next = n;
	q->rear = n;
}
int dequeue(struct queue *q)
{
	assert(q);
	struct node *n = q->front;
	int data = n->data;
	q->front = q->front->next;
	free(n);
	q->sz--;
	if (!q->front) q->rear = NULL;
	return data;
}
void dfs(int s)
{
    int i;
    visit[s] = 1;
    for (i = 0; i < 9; i++) {
        if (adj[s][i] == 1 && !visit[i])
            pattern++, dfs(i);
    }
    visit[s] = 0;
}
int empty(struct queue *q)
{
	assert(q);
	return (q->front == NULL);
}
void bfs(int s)
{
	int i, u;
	struct queue q = {};
	visit[s] = 1;
	parent[s] = s;
	enqueue(&q, s);
	while (!empty(&q)) {
		u = dequeue(&q);
		for (i = 0; i < 9; i++) {
			if (adj[s][i] == 1 && !visit[i])
			{
				visit[i] = 1;
				parent[i] = u;
				enqueue(&q, i);
			}
		}
	}
	while (u != s) {
		printf("%d ", u);
		u = parent[u];
	}
	printf("\n");
}
int main(int argc, char **argv)
{
    int i;
    for (i = 0; i < 9; i++) {
        memset(visit, 0, 9*sizeof(int));
        memset(parent, 0, 9*sizeof(int));
        //dfs(i);
	bfs(i);
    }
    printf("%d\n", pattern);
    return 0;
}
