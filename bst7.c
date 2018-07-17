#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct list {
	int data;
	struct list *next;
};

struct node {
	int data;
	struct node *right, *left;
};

void add(struct list **ref, int data)
{
	assert(ref);
	struct list dummy = {}, *p = &dummy, *n;
	dummy.next = *ref;
	while (p->next) p = p->next;
	n = malloc(sizeof(struct node));
	n->data = data; n->next = NULL;
	p->next = n;
	*ref = dummy.next;
}
void dump(struct list *p)
{
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
}
struct node *newnode(int data)
{
	struct node *n = calloc(1, sizeof(struct node));
	n->data = data;
	return n;
}
void insert(struct node **ref, int data)
{
	assert(ref);
	struct node *p = *ref;
	if (!p) {
		struct node *n = newnode(data);
		*ref = n;
		return;
	}
	insert((data > p->data)? &(p->right): &(p->left), data);
}
int count(struct list *p)
{
	int cnt;
	for (cnt = 0; p; cnt += 1) p = p->next;
	return cnt;
}
struct node *inorder(struct list **ref, int c)
{
	assert(ref);
	if (!c) return NULL;

	/* build left */
	struct node *left = inorder(ref, c/2);

	/* build root */
	struct node *root = newnode((*ref)->data);
	root->left = left;
	*ref = (*ref)->next;

	/* build right */
	root->right = inorder(ref, c-(c/2)-1); 

	return root;
}

void list2bst(struct list *p, struct node **ref)
{
	assert(ref);
	int cnt = count(p);
	*ref = inorder(&p, cnt);
}
int main(void)
{
	struct list *head = NULL;
	struct node *root = NULL;
	add(&head, 1);
	add(&head, 2);
	add(&head, 3);
	add(&head, 4);
	add(&head, 5);
	add(&head, 6);
	add(&head, 7);
	dump(head);
	list2bst(head, &root);
	return 0;
}
