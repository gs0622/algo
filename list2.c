#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct dqueue {
	struct dlist *head;
	struct dlist *tail;
	int size;
};

void push(struct dlist **href, int data)
{
	struct dlist *n = malloc(sizeof(struct dlist));
	n->data = data;
	n->next = *href;
	n->prev = NULL;
	if (*href) (*href)->prev = n;
	*href = n;
}

void enqueue(struct dlist **href, int data)
{
	struct dlist *n = calloc(1, sizeof(struct dlist));
	struct dlist d = {}, *m = &d;
	d.next = *href;
	n->data = data;
	while (m->next) m = m->next;
	m->next = n;
	*href = d.next;
}

void move2head(struct dlist **href, struct dlist *n)
{
	struct dlist *p = n->prev, *q = n->next;
	p->next = q, q->prev = p;
	n->prev = NULL, n->next = *href;
	*href = n;
}

int length(struct dlist *head)
{
	struct dlist *cur = head;
	int cnt = 0;
	while (cur) cnt++, cur = cur->next;
	return cnt;
}

void dump(struct dlist *head)
{
	struct dlist *cur = head;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void rdump(struct dlist *tail)
{
	struct dlist *cur = tail;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->prev;
	}
	printf("\n");
}

int main(void)
{
	struct dqueue dq = {};
	struct dlist **href = &dq.head;
	push(href, 1);
	push(href, 2);
	push(href, 3);
	dump(dq.head);
	rdump(dq.tail);
	//printf("len=%d\n", length(head));
}
