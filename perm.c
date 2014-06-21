#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ((t)=(x),(x)=(y),(y)=(t))
void perm(char list[], int i, int n)
{
    int j, k;
    if (i==n) {
        for (j=0;j<=n;j++) printf("%c", list[j]); 
        printf(" ");
    } else {
        for (j=i;j<=n;j++) {
            SWAP(list[i], list[j], k);
            perm(list, i+1, n);
            SWAP(list[i], list[j], k);
        }
    }
}

int main(int argc, char *argv[])
{
    if (1==argc) return 0;
    else {
        char *list = malloc(sizeof(char)*(argc-1));
        int i;
        for (i=0;i<argc-1;i++) list[i]=argv[i+1][0];
        perm(list, 0, argc-2);
        printf("\n");
        free(list);
    }
    return 0;
}

