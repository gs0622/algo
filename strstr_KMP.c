#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/*Knuth, Morris, Pratt algo, time: O(m+n)*/
static int *failure = NULL;
static void fail(const char *pat, int n)
{
    int i, j;

    assert(failure);

    failure[0]=-1;

    for (j = 1; j < n; j++) {
        i = failure[j-1];
        while (pat[j] !=bpat[i+1] && i >= 0)
            i = failure[i];
        if (pat[j] == pat[i+1]) failure[j]=i+1; 
        else failure[j]=-1;
    }
}
char *strstr_kmp(const char *str, const char *pat)
{
    int i, j, m, n;
    if (!str||!pat) return NULL;
    i = j = 0;
    m = strlen(str), n = strlen(pat);
    failure = calloc(n, sizeof(int));
    assert(failure);
    fail(pat, n);
    while (i<m && j<n) {
        if (str[i]==pat[j]) i++, j++;
        else if (j==0) i++;
        else j = failure[j-1]+1;
    }
    free(failure), failure=NULL;
    return (j==n)? (char *)(str+(i-n)):NULL;
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
    s = strstr_kmp(argv[1], argv[2]); /*argv[1]=string, argv[2]=pattern*/
    if (s)
        printf("2: pattern \"%s\" is found in string \"%s\" offset %ld\n", argv[2], argv[1], s-argv[1]);
    else 
        printf("2: pattern \"%s\" is not found in string \"%s\"\n", argv[2], argv[1]);
    return 0;
}

