/*Pascal's Triangle*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i, j, n = (argc > 1)? atoi(argv[1]): 10;
    int d[128][128] = {};
    for (i=0;i<n;i++) d[0][i]=1, d[i][0]=1;
    for (i=1;i<n;i++)
        for (j=1;j+i<n;j++)
            d[i][j]=d[i-1][j]+d[i][j-1];
    for (i=0;i<n;i++) {
        for (j=0;j+i<n;j++) printf("%4d ", d[i][j]);
        printf("\n\n");
    }
    return 0;
}
