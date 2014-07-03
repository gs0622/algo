/*Only use plus operator*/
#include <stdio.h>
int negative(int operand)
{
    int neg = 0, delta = (operand >= 0)? -1: 1;
    while (operand != 0) {
        neg += delta, operand += delta;
    }
    return neg;
}

int main(void)
{
    printf("3-4=%d\n", 3+negative(4));
    return 0;
}

