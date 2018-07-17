#include <stdio.h>
#include <stdlib.h>

float mysqrt(int val)
{
    double sqrt, old;
    sqrt = 1;
    while (1) {
        sqrt = (sqrt + val / sqrt) / 2; /*Newton's method*/
	printf("%f: %f\n", sqrt, old);
        if (old == sqrt) break; else old = sqrt;
    }
    return sqrt;
}

int main(int argc, char *argv[])
{
    int val;
    if (2 != argc) return 0;
    val = atoi(argv[1]);
    if (0 >= val) return 0;
    printf("%f\n", mysqrt(val));
    return 0;
}

