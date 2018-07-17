#include <stdio.h>
#include <stdlib.h>
unsigned int hash(unsigned int v)
{
        return v * (2654435761UL);
}
struct node {
	int data;
	struct node *next;
	struct node *prev;
};
struct table {
	struct node *arr;
	int m;
	int n; /*slots*/
};
void push(struct node **ref, int data)
{
	assert(ref);
	struct node *n = malloc(sizeof(struct node));
	n->data = data;
	n->prev = NULL;
	n->next = *ref;
	if (*ref) *ref->prev = n;
	*ref = n;
}
int pop(struct node **ref)
{
	assert(ref);
	struct node n = *ref;
	int data = n->data;
	*ref = n->next;
	free(n);
	return data;
}
#define SZ_TABLE	4
void insert(struct table *t, int key, int data)
{
	assert(t);
	int m = t->m;
	unsigned int h = hash(key);
	push(&(t->arr[h % m]), data);
	t->n++;
	if (t->n == m) {
		// do amortization
	}
}
int main(int argc, char *argv[])
{
	if (argc < 2) return 0;
	struct table *t = calloc(1, sizeof(struct table));
	t->arr = calloc(SZ_TABLE, sizeof(struct node));
	t->n = SZ_TABLE, t->m = 1;
	return 0;
}

