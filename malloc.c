#include <stdio.h>
#include <stdlib.h>
void *malloc_aligned(size_t size, size_t alignment)
{
	int off = alignment -1 + sizeof(void *);
	void *p1 = malloc(size + off);
	void **p2 = (void **)(((size_t)p1 + off) & ~(alignment - 1));
	printf("m: %d: %d: %d: %p %p\n", size + off, (int)p2 - (int)p1, off, p1, p2);
	p2[-1] = p1;
	return p2;
}
void free_aligned(void *p1)
{
	void **p2 = p1;
	printf("f: %p %p %p\n", p1, p2, p2[-1]);
	free(p2[-1]);
}
int main(void)
{
	void *p = malloc_aligned(1000, 128);
	printf("%p\n", p);
	free_aligned(p);
	return 0;
}
