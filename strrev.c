#include <stdio.h>

static void swap(char *p, char *q)
{
	char tmp = *p;
	*p = *q, *q = tmp;
}

void strrev(char *p)
{
    char *q = p;
    if (NULL==q) return;
    while (*q) ++q; /*move to tail*/
    for (--q/*skip '\0'*/;q>p;++p,--q) swap(p, q);
}

void strrev_utf8(char *p)
{
    char *q = p;
    if (NULL==q) return;
    strrev(p); /*base case*/
    /*now try to fix in case there is utf-8 codes*/
    while (*q) q++; /*move to tail, aka. '\0'*/
    while (--q > p) {
        switch((*q & 0xf0)>>4) {
        case 0xc: case 0xd: /*2-byte, 110xxxxx 10xxxxxx*/
            swap(q, q-1), q-=1;
            break;
        case 0xe: /*3-byte, 1110xxxx 10xxxxxx 10xxxxxx */
            swap(q, q-2), q-=2;
            break;
        case 0xf: /*4-byte, 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx*/
            swap(q, q-3), swap(q-1, q-2), q-=3;
            break;
        }
    }
}

int main(void)
{
    char s[128];
    while (scanf("%s", s)!=EOF) {
        printf("in : %s\n", s);
        strrev(s);
        //strrev_utf8(s);
        printf("out: %s\n", s);
    }
    return 0;
}
