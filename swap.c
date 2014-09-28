#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap1(int *x, int *y)
{
    assert(x && y);
    *x = *x + *y;
    *y = *x - *y; /*(x+y)-y*/
    *x = *x - *y; /*(x+y)-x*/
}

void swap2(int *x, int *y)
{
    assert(x && y);
    *x = *x * *y;
    *y = *x / *y; /*(x*y)/y*/
    *x = *x / *y; /*(x*y)/x*/
}

void swap3(int *x, int *y)
{
    assert(x && y);
    if (*x == *y) return;
    *x = *x ^ *y;
    *y = *x ^ *y; /*(x^y)^y*/
    *x = *x ^ *y; /*(x^y)^x*/
}

int main(int argc, char *argv[])
{
    int a, b;
    if (3 != argc) return 0;
    a = atoi(argv[1]), b = atoi(argv[2]);
    swap1(&a, &b);
    printf("a=%d b=%d\n", a, b);
    swap2(&a, &b);
    printf("a=%d b=%d\n", a, b);
    swap3(&a, &b);
    printf("a=%d b=%d\n", a, b);
    return 0;
}

