#include <stdio.h>
typedef struct {
    int Y[3];
    char Z[12];
} X;

int main(void)
{
    printf("A: sizeof(X)=%d\n", (int)(sizeof(X)));
    printf("B: sizeof(X)=%d\n", (X *)0+1);
    return 0;
}
