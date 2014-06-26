#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
    int i, c, n = (argc>1)? atoi(argv[1]): 100;
    double x, y;
    srand(time(NULL));
    for (i=0,c=0;i<n; i++) {
        x = ((double)rand())/RAND_MAX;
        y = ((double)rand())/RAND_MAX;
        if (x*x+y*y < 1) c++;
    }
    printf("PI = %lf\n", (double)4*c/n);
    return 0;
}
