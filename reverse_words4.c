#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
/* trim leading non-alpha chars */
char *strtrim(char *s)
{
	while (*s && !isalpha(*s)) s += 1;
	return s;
}
/* step to next non-alpha chars */
char *strcut(char *s)
{
	while (*s && isalpha(*s)) s += 1;
	return s;
}
void _reverse(char *s, int i, int j)
{
	while (i < j) {
		char c = s[i];
		s[i] = s[j], s[j] = c;
		i += 1, j -= 1;
	}
}
void __reverse(char *s)
{
	char *p;
	s = strtrim(s); /* save _reverse calling when it comes to non-alpha */
	p = strcut(s);
	_reverse(s, 0, (int)(p-s-1));
	if (*p) __reverse(p+1);
}
/* one-pass, O(n) time, O(1) space */
char *reverse(char *s)
{
	int sz = strlen(s);
	_reverse(s, 0, sz-1);
	__reverse(s);
	return s;
}
int main()
{
	char s0[] = "the sky is blue";
	char s1[] = "  the sky is blue";
	char s2[] = "the sky is blue  ";
	char s3[] = "the sky is  blue";
	printf("%s\n", reverse(s0));
	printf("%s\n", reverse(s1));
	printf("%s\n", reverse(s2));
	printf("%s\n", reverse(s3));
	return 0;
}
