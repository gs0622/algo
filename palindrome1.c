#include <stdio.h>

int palindrome(char *s)
{
	char *p;
	int i, len, map[256];
	for (i = 0, len = 0, p = s; *p; i+=1, p+=1)
		len += 1;
	for (i = 0; i < len/2; i+=1) {
		printf("%c : %c\n", s[i], s[len-i-1]);
		if (s[i] != s[len-i-1]) return 0;
	}
	return 1;
}

int main(int argc, char **argv)
{
	if (argc < 2) return 0;
	printf("%d\n", palindrome(argv[1]));
	return 0;
}
