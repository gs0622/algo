/*
Implement strstr(). Returns the index of the first occurrence of needle in haystack, or –1
if needle is not part of haystack.
*/
#include <stdio.h>
#include <string.h>

int strstr_naive1(char *haystack, char *needle)
{
	char *p = haystack, *q = needle;
	int len_p = strlen(p), len_q = strlen(q);
	int i, j;

	for (i = 0; ; i += 1) {
		for (j = 0; ; j += 1) {
			//if (j == len_q) return i; // found
			if (i+j == len_p) return -1;
			if (j == len_q) return i; // found
			if (p[i+j] != q[j]) break;
		}
	}
	return -1;
}
int strstr_naive(char *haystack, char *needle)
{
	char *p = haystack, *q = needle;
	int len = strlen(needle), found, i;

	while (*p) {
		while (*p && *p != *q) p++;
		found = 1;
		for (i = 0; i < len; i += 1) {
			if (p[i] != q[i]) {
				found = 0;
				break;
			}
		}
		if (found) return (int)(p - haystack);
		p += 1;
	}
	return -1; /* not found */
}

int main(void)
{
	char s1[] = "1234567", s2[] = "765"; // -1
	char s3[] = "1234567", s4[] = "567"; // 5
	char s5[] = "aaaba", s6[] = "ba"; // 4
	char s7[] = {} , s8[] = {};
	char s9[] = "567", s10[] = "1234567"; // -1, needle is longer than haystack
	char s11[] = "mississippi", s12[] = "issi";
	char s13[] = "1234567" , s14[] = {};
	int p;
#define TEST(s1, s2)	\
printf("%-12s: %-12s: %2d: %2d\n", s1, s2, p = strstr_naive(s1, s2), strstr_naive1(s1, s2))

	TEST(s1, s2);
	TEST(s3, s4);
	TEST(s5, s6);
	TEST(s7, s8);
	TEST(s9, s10);
	TEST(s11, s12);
	TEST(s13, s14);
	TEST(s14, s13);
}
