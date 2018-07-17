#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
const long long BASE = 257;
const long long MOD = 1000000007;
long long hash(void *key, int len)
{
	long long h = 0;
	unsigned char *p = key;
	int i;
	for (i=0;i<len;i++) h=h*BASE+p[i], h%=MOD;
	return h;
}
void append(long long *h, char c)
{
	*h = (*h * BASE + c) % MOD;
}
void skip(long long *h, long long pow, char c)
{
	*h -= (pow * c);
	if (*h < 0) *h += MOD;

}
/*Rabin-Karp algo, time: O(m+n)*/
char *strstr_rp(const char *str, const char *pat)
{
	unsigned int i, j, m, n;
	long long hs, hp, power;
	if (!str||!pat) return NULL;
	m = strlen(str), n = strlen(pat);
	if (n > m) return NULL;
	hp = hash((void *)pat, n);
	for (i=0, power=1;i<n;i++) power = (power * BASE) % MOD;
	for (i=0, hs=0;i<m;i++) {
		//hs = (hs * BASE + str[i]) % MOD;
		//if (i>=n) hs -= (power * str[i-n]);
		//if (hs < 0) hs += MOD;
		append(&hs, str[i]);
		if (i>=n) skip(&hs, power, str[i-n]);
		if (hs==hp) {
			for (j=0;(j<n)&&(str[i-n+1+j]==pat[j]);j++);
			if (j==n) return (char *)(str+i-n+1); /*found*/
		}
	}
	return NULL; /*not found*/
}
int main(int argc, char *argv[])
{
	char *s;
	if (argc<3) return 0;
	s = strstr(argv[1], argv[2]); /*argv[1]=string, argv[2]=pattern*/
	if (s)
		printf("1: pattern \"%s\" is found in string \"%s\" offset %ld\n", argv[2], argv[1], s-argv[1]);
	else 
		printf("1: pattern \"%s\" is not found in string \"%s\"\n", argv[2], argv[1]);
	s = strstr_rp(argv[1], argv[2]); /*argv[1]=string, argv[2]=pattern*/
	if (s)
		printf("2: pattern \"%s\" is found in string \"%s\" offset %ld\n", argv[2], argv[1], s-argv[1]);
	else 
		printf("2: pattern \"%s\" is not found in string \"%s\"\n", argv[2], argv[1]);
	return 0;
}

