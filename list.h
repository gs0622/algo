/* Designed for various of link-list types.
 */

struct node {
	int data;
	struct node *next;
};

struct slist {
	int data;
	struct slist *next;
};

struct dlist {
	int data;
	struct dlist *prev;
	struct dlist *next;
};

struct btree {
	int data;
	struct btree *left;
	struct btree *right;
};

