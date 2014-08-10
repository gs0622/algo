/*refer to http://www.geeksforgeeks.org/rotate-bits-of-an-integer*/
#include <stdio.h>
#include <stdlib.h>

#define INTBITS (sizeof(int)*8)

/*Left rotate n by d bits*/
int RotateLeftNoCarry(int n, int d)
{
    /*<---d bits*/
    return (n << d) | (n >> (INTBITS - d));
}
/*Right rotate n by d bits*/
int RotateRightNoCarry(int n, int d)
{
    /*d bits--->*/
    return (n >> d) | (n << (INTBITS - d)); 
}
int main(int argc, char *argv[])
{
    int n, d;
    if (3 > argc) return 0;
    n = atoi(argv[1]), d = atoi(argv[2]);
    printf("%d rol %d = %d\n", n, d, RotateLeftNoCarry(n, d));
    printf("%d ror %d = %d\n", n, d, RotateRightNoCarry(n, d));
    return 0;
}

