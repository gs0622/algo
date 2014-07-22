#include <stdio.h>

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
    for (p=s; *p && *p!=' '; ++p);
    if (*p!=' ') return; /*no space*/
    for (q=s; *q; ++q);  /*to tail*/
    --q, strrev(s, q);
    for (p=s; *p && *p!=' '; ++p);
    *p='\0';
    strrev(s, p-1);
    strrev(p+1, q);
    *p=' ';
}

int main(int argc, char *argv[])
{
    if (1==argc) return 0;
    printf("in : %s\n", argv[1]);
    strswap(argv[1]);
    printf("out: %s\n", argv[1]);
    return 0;
}
