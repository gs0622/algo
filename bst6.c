#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node {
	int data;
	struct node *left, *right;
};
void insert(struct node **ref, int data)
{
	assert(ref);
	struct node *n = *ref;
	if (!n) {
		struct node *m = calloc(1, sizeof(struct node));
		m->data = data;
		*ref = m;
		return;
	}
	insert((data > n->data)? &(n->right): &(n->left), data);
}
struct node *lca(struct node *n, int x, int y)
{
	if (!n) return NULL;
	while ((x < n->data && y < n->data) ||
		(x > n->data && y > n->data)) {
		if (x < n->data && y < n->data) n = n->left;
		else n = n->right;
	}
	printf("lca: %d\n", n->data);
	return n;
}
int main(void)
{
	int i, arr[] = { 18, 36, 9, 6, 12, 10, 1, 8 };
	struct node *root = NULL;
	for (i = 0; i < sizeof(arr)/sizeof(int); i += 1) {
		insert(&root, arr[i]);
	}
	lca(root, 1, 10);
	lca(root, 1, 8);
	lca(root, 1, 36);
	lca(root, 6, 8);
	return 0;
}
