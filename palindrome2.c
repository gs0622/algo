/* Given a string, determine if it is a palindrome,
 * considering only alphanumeric characters and ignoring cases.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int palidrome(char *s)
{
	int i;
	int len = strlen(s);
	char *p, *q, *tmp = malloc(len+10);
	for (i=0; i<=len; i+=1) tmp[i] = s[i];
	for(p = s, q = s+len-1; q>p; p++, q--) {
		while (p < q && !isalpha(*p)) p++;
		while (p < q && !isalpha(*q)) q--;
		if (tolower(*p) != tolower(*q)) return 0;
	}
	return 1;
}

int main(void)
{
	char str1[] = "race a car";
	char str2[] = "A man, a plan, a canal: Panama";
	char str3[] = "hanah";
	char str4[] = {};
	printf("%5s: %s\n", palidrome(str1)? "true": "false", str1);
	printf("%5s: %s\n", palidrome(str2)? "true": "false", str2);
	printf("%5s: %s\n", palidrome(str3)? "true": "false", str3);
	printf("%5s: %s\n", palidrome(str4)? "true": "false", str4);
	return 0;
}
