#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int *p, int n)
{
	for (;p&&n>0;n--,p++) {
		printf("%5d\n", *p);
	}
}

static int cmp(const void *p, const void *q)
{
	int i = *((int *)p), j = *((int *)q);
	return (i-j);
}

int main(int argc, char **argv)
{
	int i, s, m, n = 10000, p[10000], q[10000];
    freopen(argv[1], "r", stdin);
    for (i=0; i<n; i++) {
        if (scanf("%d", &p[i])==EOF) break;
    }
    if (n != i) n = i;
    printf("n=%d\n", n);
    for (i=0, s=0; i<n; i++) {
        memcpy(q, p, sizeof(int)*(i+1));
	    qsort(q, (i+1), 4, cmp);
        m = ((i+1)%2==0)? q[i/2]: q[(i+1)/2];
        s += m;
        //printf("m=%d s=%d\n", m, s);
    }
	//print_array(p, n);
	//qsort(p, n, 4, cmp);
	//print_array(p, n);
    printf("s=%d\n", s%10000);
	return 0;
}
