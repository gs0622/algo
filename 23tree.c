
struct node {
	int key[2];
	struct node *parent;
	struct node *child[3];
};

struct node *newnode(int key)
{
	struct node *n = calloc(1, size(struct node));
	assert(n);
	n->key[0] = key; /* all others are 0/null */
	return n;
}

enum { LEAF, 2_NODE, 3_NODE } node_type;

node_type type(struct node *n)
{
	assert(n);
	if (n->child[0] == NULL) return LEAF;
	else if (n->child[2] == NULL) return 2_NODE;
	else return 3_NODE;
}
void insert(struct node **ref, int key)
{
	struct node *p = *ref;
}

