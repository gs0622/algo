#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>
struct node {
	struct node *left, *right;
	char *s;
};
void insert(struct node **ref, char *s)
{
	assert(ref && s);
	struct node *n = *ref;
	if (!n) {
		struct node *m = calloc(1, sizeof(struct node));
		m->s = s; 
		*ref = m;
		return;
	}
	if (strcmp(s, n->s) > 0)
		insert(&(n->right), s);
	else /* less or equal */
		insert(&(n->left), s); 
}
void inorder(struct node *n)
{
	if (!n) return;
	inorder(n->left);
	printf("%s\n", n->s);
	inorder(n->right);
}
void delete(struct node **ref)
{
	if (!*ref) return;
	struct node *n = *ref;
	delete(&(n->left));
	delete(&(n->right));
	free(n);
}
int main(void)
{
	char strs[5][200] = {
		"zoo", "bar", "bletch", "successful", "shell"
	};
	struct node *root = NULL;
	int i;
	for (i = 0; i < 5; i +=1 ) {
		insert(&root, strs[i]);
	}
	inorder(root);
	delete(&root);
	return 0;
}
