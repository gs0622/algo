#include <stdio.h>
struct node {
	int data;
	struct node *next;
};
void push(struct node **pp, struct node *q)
{
	q->next = *pp;
	*pp = q;
}
int main(void)
{
	int i;
	struct node *p = NULL, *c;
	struct node q[4] = {{1,0}, {2,0}, {3,0}, {4,0}};
	for (i = 0; i < sizeof(q)/sizeof(struct node); i += 1)
		push(&p, &q[i]);
	for (c = p; c; c = c->next)
		printf("%d ", c->data);
}
