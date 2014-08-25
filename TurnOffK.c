#include <stdio.h>

int TurnOffK(int n, unsigned int k)
{
    return (k > 0)? (n & ~(1 << (k - 1))): n;
}
int main(int argc, char *argv[])
{
    int n;
    unsigned int k;
    while (scanf("%d %u", &n, &k) == 2) {
        printf("%d\n", TurnOffK(n, k));
    }
    return 0;
}

