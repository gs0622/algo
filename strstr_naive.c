#include <stdio.h>
#include <string.h>
/*Brute-force, time:O(m*n)*/
char *strstr_naive(const char *str, const char *pat)
{
    int i, j, m, n;
    if (!str||!pat) return NULL;
    m = strlen(str), n = strlen(pat);
    for (i=0;i<m-n+1;i++) {
        int match = 1;
        for (j=0;j<n;j++) {
            if (str[i+j]!=pat[j]) {
                match = 0;
                break;
            }
        }
        if (match) return (char *)(str+i);
    }
    return NULL;
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
    s = strstr_naive(argv[1], argv[2]); /*argv[1]=string, argv[2]=pattern*/
    if (s)
        printf("2: pattern \"%s\" is found in string \"%s\" offset %ld\n", argv[2], argv[1], s-argv[1]);
    else 
        printf("2: pattern \"%s\" is not found in string \"%s\"\n", argv[2], argv[1]);
    return 0;
}

