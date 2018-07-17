#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *right;
	struct node *left;
};

int insert(struct node **ref, int data)
{
	int goright = 0;
	struct node *p = *ref;
	if (p == NULL) {
		struct node *n = malloc(sizeof(struct node));
		n->right = n->left = NULL;
		n->data = data;
		*ref = n;
		return 0;
	}

	if (data == p->data) {
		// assert(0);
		return 0;
	}
	goright = (data > p->data)? 1: 0;
	goright += insert((goright)? &(p->right): &(p->left), data);
	return goright;
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

