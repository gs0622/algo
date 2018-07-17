struct node
{
	int data;
	struct node *next;
}
typedef struct node Node;
int listcmp(Node *p, Node* q)
{
	while (p && q) {
		if (p->data != q->data) return 0;
		p = p->next, q = q->next;
	}
	if (p == NULL && q == NULL) return 1;
	return 0;
}

