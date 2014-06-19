#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randrange(int i, int j)
{
    return i+rand()/(RAND_MAX/(j-i)+1);
}

int main(int argc, char *argv[])
{
    int i, j, n = (argc>1)? atoi(argv[1]): 10;
    srand(time(NULL));
    for (i=0;i<n-1;i++) {
        //j = i+rand()/(RAND_MAX/(n-i)+1);
        j = randrange(i, n);
        printf("%.2d: %.2d: %s\n", i, j, (j<n&&j>=i)?"pass":"fail");
    }
    return 0;
}