#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
unsigned int hash(void *key, int len)
{
    const unsigned BASE = 257;
    const unsigned MOD = 1000000007;
    unsigned char *p = key;
    unsigned int h = 0;
    int i;
    for (i=0;i<len;i++) h=h*BASE+p[i], h%=MOD;
    return h;
}
/*Rabin-Karp algo, time: O(m+n)*/
char *strstr_rp(const char *str, const char *pat)
{
    unsigned int i, j, m, n, hs, hp;
    if (!str||!pat) return NULL;
    m = strlen(str), n = strlen(pat);
    hp = hash((void *)pat, n);
    for (i=0;i<m-n+1;i++) {
        hs = hash((void *)(str+i), n);
        if (hs==hp) {
            for (j=0;(j<n)&&(str[i+j]==pat[j]);j++);
            if (j==n) return (char *)(str+i); /*found*/
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

