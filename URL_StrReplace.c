/*replace the space of input to %20*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int main(int argc, char *argv[])
{
    int i, space, len;
    long *p;
    char *q, *r, *str = argv[1];
    if (1==argc) return 0;
    len = strlen(str);
    for (i=0,space=0;i<len;i++)
        if (' '==str[i]) space++;
    len = strlen(str);
    if (0==space) return 0;
    p = malloc(sizeof(long)*(space+1));
    q = malloc(len+2*space+1);
    assert(p && q);
    q[len+2*space+1]='\0';
    for (i=0,space=0;i<len;i++)
        if (' '==str[i]) p[space++]=&str[i]-&str[0]+1;
    p[space]=len+1;
    for (i=space-1;i>=0;i--) {
        r = q+p[i]+2*(i+1);
        memcpy(r, str+p[i], p[i+1]-p[i]-1);
        memcpy(r-3, "%20", 3);
    }
    memcpy(q, str, p[0]-1);
    printf("%s\n", q);
    return 0;
}

