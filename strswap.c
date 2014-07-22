#include <stdio.h>
static char *strend(char *s)
{
    while (*s) ++s;
    return s-1;
}
static char *strspace(char *s)
{
    while (*s && *s!=' ') ++s;
    return (s=='\0')? NULL: s;
}
static void strrev(char *p, char *q)
{
    while (p < q) {
	    if (*p!=*q) *p^=*q, *q^=*p, *p^=*q;
        ++p, --q;
    }
}
static void strswap(char *s)
{
    register char *p, *q;
    if (!strspace(s)) return;
    strrev(s, strend(s));
    strrev(s, strspace(s)-1);
    strrev(strspace(s)+1, strend(s));
}
int main(int argc, char *argv[])
{
    if (1==argc) return 0;
    printf("in : %s\n", argv[1]);
    strswap(argv[1]);
    printf("out: %s\n", argv[1]);
    return 0;
}
