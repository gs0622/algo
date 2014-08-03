/*Find the Number Occurring Odd Number of Times*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i, ans;
    if (1==argc) return 0;
    for (i=1,ans=0;i<argc;i++) {
        ans^=atoi(argv[i]);
    }
    printf("%d\n", ans);
    return 0;
}

