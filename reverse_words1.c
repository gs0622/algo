/*
Given an input string s, reverse the string word by word.
(string return version)
*/
#include <stdio.h>
#include <ctype.h>
char *reverse(char *s)
{
	char *p, *q;
	int i, len = strlen(s);
	//while (*q && !isspace(*q)) q += 1;
	//if (*q) reverse(q + 1);
	//printf("%.*s ", (int)(q-p), p);
}

int main(void)
{
	char s1[] = "the sky is blue";
	char s2[] = "  the sky is blue";
	char s3[] = "the sky	is blue";
	printf ("%s\n", reverse(s1));
}
