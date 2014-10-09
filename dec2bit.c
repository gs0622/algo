/*calculate decimal to bits in binary*/
#include <stdio.h>

int main(void)
{
    int dec;
       
    while (scanf("%d", &dec) != EOF) {
        while (dec) {
            printf("%d", dec & 1);
            dec >>= 1;
        }
    }
}
