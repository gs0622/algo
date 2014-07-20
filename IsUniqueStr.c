/*algo to check whether input string contents unique char or not*/
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i, bitmap[256] = {}, unique=1;
    if (1==argc) return 0;
    for (i=0;i<strlen(argv[1]);i++) {
        int bit = argv[1][i]-'0';
        /*printf("bit=%d\n", bit);*/
        if (bitmap[bit]) {
            unique=0;
            break;
        }
        bitmap[bit] = 1;
    }
    printf("%s\n", unique? "true": "false");
    return 0;
}

