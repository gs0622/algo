#include <stdio.h>
#include <string.h>
#include <ctype.h>

void _reverse(char *s, int i, int j)
{
	int c;
	for (; j > i; i += 1, j -= 1)
		c = s[i], s[i] = s[j], s[j] = c;
}
char *reverse(char *s)
{
	int i, j, sz = strlen(s);
	_reverse(s, 0, sz-1);
	for (i = 0; i < sz; i += 1) {
		while (i < sz && !isalpha(s[i])) // scan-1 for head
			i += 1;
		for (j = i + 1; j < sz; j += 1)  // scan-2 for tail
			if (!isalpha(s[j]))
				break;
		_reverse(s, i, j-1); // reverse head-tail
		i = j;
	}
	return s;
}
int main(void)
{
	char s0[] = "the sky is blue";
	char s1[] = "  the sky is blue";
	char s2[] = "the sky is blue  ";
	printf("%s\n", s0);
	printf("%s\n", reverse(s0));
	printf("%s\n", reverse(s1));
	printf("%s\n", reverse(s2));
	return 0;
}
