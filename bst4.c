#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *right;
	struct node *left;
};

struct node *search(struct node *p, int data)
{
	if (NULL == p) return NULL;
	if (data == p->data) return p;
	return search((data < p->data)? p->left: p->right, data); 
}
/*inorder predecessor*/
struct node *floor(struct node *p, int data)
{
	struct node *q = search(p, data);
	if (NULL == q->left) return NULL;
	q = q->left;
	while (q->right) q = q->right;
	return q;
}
/*inorder successor*/
struct node *ceil(struct node *p, int data)
{
	if (NULL == p) return NULL;
	struct node *cur = p, *parent = NULL;
	while (data != cur->data) {
		parent = cur;
		cur = (data < cur->data)? cur->left: cur->right;
	}
	if (data != cur->data) return NULL;
	if (NULL == cur->right) return parent;
	else {
		cur = cur->right;
		while (cur->left) cur = cur->left;
		return cur;
	}
}

insert(struct node **ref, int data)
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

void inorder(struct node *src)
{
	if (!src) return;
	inorder(src->left);
	printf("%d ", src->data);
	inorder(src->right);
}

#define MAX(a,b)	((a>b)?a:b)
int main(void)
{
	struct node *href = NULL;
	int i, lis = 0;
	//int data[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	//int data[] = {60, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int data[] = {0, 8, 4, 50, 2, 10, 6, 54, 1, 9, 5, 11, 3, 13, 7, 15};
	for (i=0; i<sizeof(data)/sizeof(int); i++) {
		//printf("%d ", data[i]);
		lis = MAX(lis, insert(&href, data[i]));
	}
	printf("%d\n", lis+1);
	inorder(href);
	printf("\n");
}

