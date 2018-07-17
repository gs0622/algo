/*
Given an input string s, reverse the string word by word.
(print out version)
*/
#include <stdio.h>
#include <ctype.h>
void reverse(char *s)
{
	char *p = s, *q = s;
	while (*q && !isspace(*q)) q += 1;
	if (*q) reverse(q + 1);
	printf("%.*s ", (int)(q-p), p);
}

int main(void)
{
	char s1[] = "the sky is blue";
	char s2[] = "  the sky is blue";
	char s3[] = "the sky	is blue";
	printf("%s\n", s1);
	reverse(s1);
	putchar('\n');
	//reverse(s2);
	//putchar('\n');
	//reverse(s3);
	//putchar('\n');
}
