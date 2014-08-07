#include <stdio.h>
/* 9x9 multiplication table with ANSI escape code*/
int main(void)
{
    int i, j;
    printf("%c[%dm", 27, 0); /*reset*/
    printf("%c[%dm", 27, 44);
    //printf("%c[%d;4m", 27, 31);
    printf("   ");
    for (i = 1; i <= 9; i++)
        printf("%2d%s", i, (i==9)? "\n": " ");
    printf("%c[%dm", 27, 0); /*reset*/
    for (i = 1; i <= 9; i++) {
        //printf("%2d ", i);
        printf("%c[%dm%2d%c[%dm ", 27, 44, i, 27, 0);
        //printf("%c[%d;4m%2d%c[%dm ", 27, 31, i, 27, 0);
        for (j = 1; j <= 9; j++)
            printf("%2d%s", i*j, (j==9)? "\n":" ");
    }
    return 0;
}

