#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
	int data;
	struct node *next;
};
void push(struct node **ref, int data)
{
	assert(ref);
	struct node *n = malloc(sizeof(struct node));
	n->data = data, n->next = *ref;
	*ref = n;
}
static int visit[10];
void dfs_r(int u, struct node **adj)
{
	struct node *n = adj[u];  
	visit[u] = 1;
	printf("%d ", u);
	while (n) {
		int v = n->data; 
		if (!visit[v]) {
			dfs_r(v, adj);
		}
		n = n->next;
	}
}
int main(void)
{
	int i;
	struct node **tail, *adj[10] = {};
	for (i = 0; i < 10; i += 1) visit[i] = 0;

	tail = &adj[0];
	push(tail, 1);
	tail = &((*tail)->next);
	push(tail, 2);

	tail = &adj[1];
	push(tail, 3);
	tail = &((*tail)->next);
	push(tail, 4);

	tail = &adj[2];
	push(tail, 5);
	tail = &((*tail)->next);
	push(tail, 6);
	tail = &((*tail)->next);
	push(tail, 7);

	tail = &adj[4];
	push(tail, 8);

	dfs_r(0, adj);
	return 0;
}

