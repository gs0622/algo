#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define SZ_TRIE	26
#define SZ_ARR(a)	(sizeof(a)/sizeof(a[0]))
#define INDEX(c)	((int)c - (int)'a')

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
		idx = INDEX(key[lvl]);
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
		idx = INDEX(key[lvl]);
		if (!p->next[idx]) return 0;
		p = p->next[idx];
	}
	return (p && p->leaf);
}
struct trie *prefix(struct trie *root, const char *key)
{
	assert(key);
	int lvl, idx, len = strlen(key);
	struct trie *p = root;
	for (lvl = 0; p && lvl < len; lvl += 1) {
		idx = INDEX(key[lvl]);
		if (!p->next[idx]) return 0;
		p = p->next[idx];
	}
	return p;
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
		int idx = INDEX(key[lvl]);
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
void traverse(struct trie *p, char *buf, int lvl, int off)
{
	if (!p) return;
	int i;

	if (p->leaf) {
		buf[lvl+off] = '\0';
		printf("%s\n", buf);
	}
	for (i = 0; i < SZ_TRIE; i += 1) {
		if (p->next[i]) {
			buf[lvl+off] = 'a' + i;
			traverse(p->next[i], buf, lvl+1, off);
		}
	}
}
int main(void)
{
	int i;
	char keys[][8] = { "the", "a", "there", "answer",
		"any", "by", "bye", "their", "shell" };
	char outs[][8] = { "no", "yes" };
	char buf[8];
	struct trie *p, *root = calloc(1, sizeof(struct trie));
	assert(root);
	for (i = 0; i < SZ_ARR(keys); i += 1) {
		//printf("%s\n", keys[i]);
		insert(root, keys[i]);
	}
	traverse(root, buf, 0, 0);
	p = prefix(root, "th");
	printf("p=%p\n", p);
	if (p) {
		strcpy(buf, "th");
		traverse(p, buf, 0, 2);
	}
	p = prefix(root, "ca");
	printf("p=%p\n", p);
	for (i = 0; i < SZ_ARR(keys); i += 1) {
		delete(root, keys[i]);
	}
	free(root);
	return 0;
}
