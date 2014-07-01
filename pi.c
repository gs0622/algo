#include <stdio.h>

int main(void)
{
    double sum = 1.0;
    double denominator = 3.0;
    double numerator = 1.0;
    double temp;
    unsigned long counter = 0;
    
    while (1) {
        numerator = -numerator;
        temp = numerator;
        temp /= denominator;
        sum += temp;
        denominator += 2;
        counter++;
        if ( counter > 10000000 ) {
            printf("1/%.0f - %19.17f\n", denominator, sum);
            counter = 0;
        }
    }
    return 0;
}

