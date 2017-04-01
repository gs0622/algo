#include <stdlib.h>

struct node {
	int data;
	struct node *right;
	struct node *left;
};

int search(struct node *p, int data)
{
	if (NULL == p) return 0;
	if (data == p->data) return 1;
	return search((data > p->data)? p->right: p->left, data);

}

void insert(struct node **ref, int data)
{
	struct node *p = *ref;
	if (p == NULL) {
		struct node *n = malloc(sizeof(struct node));
		n->right = n->left = NULL;
		n->data = data;
		*ref = n;
		return;
	}

	if (data == p->data) {
		// assert(0);
		return;
	}

	insert((data > p->data)? &(p->right): &(p->left), data);
}

struct node *delete(struct node **ref, int data)
{
	struct node *p = *ref, **q;
	if (!p) return;
	if (data == p->data) {
		if (!(p->left) && !(p->right)) *ref = NULL;
		else if (!(p->left) && (p->right)) *ref = p->right;
		else if ((p->left) && !(p->right)) *ref = p->left;
		else {
			// TBD: replace w/ right min or left max
		}
		free(p);
	}
	delete((data > p->data)? &(p->right): &(p->left), data);
}

int main(void)
{
	struct node *href = NULL;
	int i, data[] = {1, -1, 2, -3, 2, 5};
	for (i=0; i<sizeof(data)/sizeof(int); i++) {
		insert(&href, data[i]);
	}
}

