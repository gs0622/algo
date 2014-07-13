#include <stdio.h>

void mprint(int *x, int row, int col)
{
    int r, c;
    for (r=0;r<row;r++)
        for (c=0;c<col;c++)
            printf("%d%s", *x++, c==(col-1)?"\n":" ");
}

void madd(int *x, int *y, int *z, int row, int col)
{
    int r, c;
    for (r=0;r<row;r++)
        for (c=0;c<col;c++)
            *z++=(*x++)+(*y++);
}

int main(void)
{
    int a[2][3]={{1,3,1},{1,0,0}};
    int b[2][3]={{0,0,5},{7,5,0}};
    int c[2][3]={};
    madd((int *)a, (int *)b, (int *)c, 2, 3);
    mprint((int *)c, 2, 3);
    return 0;
}

