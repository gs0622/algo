/*count the number of disjoint objects in a bitmap*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    unsigned long bitmap[1024];
    int i, j, n=0, disjoint=0;
    freopen("disjoint.in", "r", stdin);
    while (scanf("%lx", &bitmap[n%1023])==1) n++;
    printf("n=%d c%d|2=%d\n", n, n, n*(n-1)/2);
    for (i=0;i<n;i++) {
        int u = 0; /*is unioned?*/
        for (j=0;j<n;j++) {
            if (i==j) continue;
            if ((bitmap[i] & bitmap[j]) > 0) u=1;
        }
        if (u==0) disjoint++;
        if (u==0) printf("0x%lx\n", bitmap[i]);
    }
    printf("disjoint=%d\n", disjoint);
    return 0;
}
