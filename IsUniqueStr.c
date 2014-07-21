/*algo to check whether input string contents unique char or not*/
#include <stdio.h>
#include <string.h>
#if 0 /*time: O(n), space: O(1)*/
int main(int argc, char *argv[])
{
    int i, bitmap[256] = {}, unique=1;
    if (1==argc) return 0;
    for (i=0;i<strlen(argv[1]);i++) {
        int bit = argv[1][i]-'0';
        if (bitmap[bit]) {
            unique=0;
            break;
        }
        bitmap[bit] = 1;
    }
    printf("%s\n", unique? "true": "false");
    return 0;
}
#else /*time: O(n^2)*/
int main(int argc, char *argv[])
{
    char *p;
    int i, j, n, unique=1;
    if (1==argc) return 0;
    n = strlen(argv[1]);
    p = argv[1];
    for (i=0;i<n;i++) {
        for (j=i+1;j<n;j++) {
            if (p[i]==p[j]) {
                unique=0;
                break;
            }
        }
    }
    printf("%s\n", unique? "true": "false");
    return 0;
}
#endif
