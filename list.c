#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

void dump(struct node *src)
{
	struct node *cur = src;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

/* Given an int and a reference to the head pointer (i.e. a struct
node** pointer to the head pointer), add a new node at the head of the
list with the standard 3-step-link-in: create the new node, set its .next to
point to the current head, and finally change the head to point to the new
node.
*/
void push(struct node **href, int data)
{
	struct node *n = malloc(sizeof(struct node));
	assert(n);
	n->data = data;
	n->next = *href;
	*href = n;
}

/* Pop() takes a non-empty list, deletes
the head node, and returns the head node's data.*/
int pop(struct node **href)
{
	struct node *h = *href;
	assert(h);
	int data = h->data;
	*href = h->next;
	free(h);
	return data;
}

int length(struct node *head)
{
	struct node *cur = head;
	int cnt = 0;
	while (cur) cnt++, cur = cur->next;
	return cnt;
}

void remove_duplicates(struct node *head)
{
	if (head == NULL) return;
	struct node *cur = head;
	while (cur->next) {
		if (cur->next->data == cur->data) {
			struct node *tmp = cur->next->next;	// save next->next
			free(cur->next);			// free next
			cur->next = tmp;			// set next
		} else
			cur = cur->next;
	}
}

void move_node(struct node **dstref, struct node **srcref)
{
	if (!srcref || !dstref) return;
	struct node *tmp = *srcref;	// save
	assert(tmp);
	*srcref = tmp->next;		// shift source
	tmp->next = *dstref;		// push to dest
	*dstref = tmp;
}

int getnth(struct node *src, int n)
{
	assert(src);
	struct node *cur = src;
	int cnt = 0;
	while (cur) {
		if (cnt == n) return cur->data;
		cnt += 1, cur = cur->next;
	}
	assert(0);
}

void delete(struct node **href)
{
	struct node *cur = *href, *tmp;
	while (cur) {
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	*href = NULL;
}

/* insert to the nth */
int insert(struct node **href, int n, int data)
{
	if (0 != n) {
		struct node dummy = {};
		struct node *cur = &dummy;
		dummy.next = *href;
		int i;
		for (i=0; i<n; i++) {
			assert(cur);
			cur = cur->next;
		}
		assert(cur);
		push(&(cur->next), data);
	} else
		push(href, data);
}
void sorted_insert(struct node **href, struct node *n)
{
	assert(href);
	struct node dummy, *cur = &dummy;
	dummy.next = *href;
	while (cur->next && cur->next->data < n->data)
		cur = cur->next;
	n->next = cur->next;
	cur->next = n;
	*href = dummy.next;
}
void insertion_sort(struct node **href)
{
	assert(href);
	struct node *res = NULL, *cur = *href, *next;
	while (cur) {
		next = cur->next;
		sorted_insert(&res, cur);
		cur = next;
	}
	*href = res;
}
void reverse(struct node **href)
{
	assert(href);
	struct node *res = NULL, *cur = *href;
	while (cur)
		move_node(&res, &cur);
	*href = res;
}
int main(void)
{
	struct node *head = NULL;
	push(&head, 5);
	push(&head, 4);
	push(&head, 2);
	push(&head, 1);
	insert(&head, 2, 3);
	insert(&head, 0, 0);
	dump(head);
	reverse(&head);
	dump(head);
	insertion_sort(&head);
	dump(head);

	return 0;
}
