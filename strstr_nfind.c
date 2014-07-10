#include <stdio.h>
#include <string.h>
/*time: O(m), worst O(m*n)*/
char *strstr_nfind(const char *str, const char *pat)
{
    int i, j, k, m, n;
    if (!str||!pat) return NULL;
    m = strlen(str), n = strlen(pat);
    for (i=0,j=n-1;j<m;i++,j++) {
        if (str[j]==pat[n-1]) { /*last char matched*/
            for (k=0;k<n-1;k++) /*last one already matched*/
                if (str[i+k]!=pat[k]) break;
            if (k==n-1) return (char *)&str[i];
        }
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
    s = strstr_nfind(argv[1], argv[2]); /*argv[1]=string, argv[2]=pattern*/
    if (s)
        printf("2: pattern \"%s\" is found in string \"%s\" offset %ld\n", argv[2], argv[1], s-argv[1]);
    else 
        printf("2: pattern \"%s\" is not found in string \"%s\"\n", argv[2], argv[1]);
    return 0;
}

