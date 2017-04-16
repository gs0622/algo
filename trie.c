#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define SZ_TRIE	26
#define SZ_ARR(a)	(sizeof(a)/sizeof(a[0]))

struct trie {
	struct trie *next[SZ_TRIE];
	int leaf; /*$*/
};
void insert(struct trie *root, const char *key)
{
	assert(key);
	int lvl, idx, len = strlen(key);
	struct trie *p = root;
	for (lvl = 0; lvl < len; lvl += 1) {
		idx = (int)key[lvl] - (int)'a';
		if (!p->next[idx]) {
			struct trie *n = calloc(1, sizeof(struct trie));
			assert(n);
			p->next[idx] = n;
		}
		p = p->next[idx];
	}
	p->leaf = 1;
}
int search(struct trie *root, const char *key)
{
	assert(key);
	int lvl, idx, len = strlen(key);
	struct trie *p = root;
	for (lvl = 0; p && lvl < len; lvl += 1) {
		idx = (int)key[lvl] - (int)'a';
		if (!p->next[idx]) return 0;
		p = p->next[idx];
	}
	return (p && p->leaf);
}
static int isfree(struct trie *p)
{
	assert(p);
	int idx;
	for (idx = 0; idx < SZ_TRIE; idx += 1) {
		if (p->next[idx]) return 0;
	}
	return 1;
}
static int delete_r(struct trie *p, const char *key, int lvl, int len)
{
	if (!p) return 0;
	if (lvl == len) {
		if (p->leaf) p->leaf = 0;
		if (isfree(p)) return 1;
	} else {
		int idx = (int)key[lvl] - (int)'a';
		if (delete_r(p->next[idx], key, lvl+1, len)) {
			free(p->next[idx]);
			p->next[idx] = NULL;
			return (!(p->leaf) && isfree(p));
		}
	}
	return 0;
}
void delete(struct trie *root, const char *key)
{
	assert(key);
	int len = strlen(key);
	delete_r(root, key, 0, len);
}
int main(void)
{
	int i;
	char keys[][8] = { "the", "a", "there", "answer",
		"any", "by", "bye", "their", "shell" };
	char outs[][8] = { "no", "yes" };
	struct trie *root = calloc(1, sizeof(struct trie));
	assert(root);
	for (i = 0; i < SZ_ARR(keys); i += 1) {
		printf("%s\n", keys[i]);
		insert(root, keys[i]);
	}
	printf("%-8s:%8s\n", "the", outs[search(root, "the")] );
	printf("%-8s:%8s\n", "these", outs[search(root, "these")] );
	printf("%-8s:%8s\n", "their", outs[search(root, "their")] );
	printf("%-8s:%8s\n", "thaw", outs[search(root, "thaw")] );
	printf("%-8s:%8s\n", "shall", outs[search(root, "shall")] );
	printf("%-8s:%8s\n", "shell", outs[search(root, "shell")] );
	for (i = 0; i < SZ_ARR(keys); i += 1) {
		delete(root, keys[i]);
	}
	free(root);
	return 0;
}
