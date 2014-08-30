#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[128] = {};
    unsigned long long v;
    while (scanf("%s", str) != EOF) {
        v = strtoull(str, NULL, 10);
        printf("%llu\n", v);
    }
    return 0;
}

