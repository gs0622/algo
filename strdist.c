#include <stdio.h>
#include <string.h>
int dist(char *s1, char *s2)
{
	unsigned int m1 = 0, m2 = 0;
	for (; *s1; s1 += 1)
		m1 |= 1 << (*s1 - 'a');
	for (; *s2; s2 += 1)
		m2 |= 1 << (*s2 - 'a');
	printf("0x%x 0x%x 0x%x\n", m1, m2, m1 ^ m2);
}

int main(void)
{
	char s1[] = "cat";
	char s2[] = "cut";
	dist(s1, s2);
}
