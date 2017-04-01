#include <stdio.h>
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
	search((data > p->data)? p->right: p->left, data);

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

void delete(struct node **ref, int data)
{
	struct node *p = *ref, **q;
	if (!p) return;
	if (data == p->data) {
		if (!(p->left) && !(p->right)) *ref = NULL;
		else if (!(p->left) && (p->right)) /* one right-child */
			*ref = p->right;
		else if ((p->left) && !(p->right)) /* one left-child */
			*ref = p->left;
		else { /* two children */
			struct node *t = p->right, *q;
			while (t->left) {
				q = t;
				t = t->left;
			}
			//printf("%d\n", t->data);
			q->left = NULL; /* cut parent->left */
			p->data = t->data; /* swap data */
			p = t; /* swap to free */
		}
		free(p);
		return;
	}
	delete((data > p->data)? &(p->right): &(p->left), data);
}

int main(void)
{
	struct node *href = NULL;
	int i, data[] = {1, -1, 3, -3, 6, 2, 4, 9, 8, 7, 10, -5};
	for (i=0; i<sizeof(data)/sizeof(int); i++) {
		//printf("%d ", data[i]);
		insert(&href, data[i]);
	}
	delete(&href, 6);
	printf("\n");
}

