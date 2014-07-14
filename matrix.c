#include <stdio.h>
#include <stdlib.h>
void mprint(int *x, int row, int col)
{
    int r, c;
    for (r=0;r<row;r++)
        for (c=0;c<col;c++)
            printf("%d%s", *x++, c==(col-1)?"\n":" ");
}
int **make2darr(int row, int col)
{
    int **arr, i;
    arr = malloc(row*sizeof(*arr));
    for (i=0;i<row;i++) {
        arr[i] = malloc(col*sizeof(**arr));
    }
    return arr;
}

/*Matrix addition*/
void madd(int *x, int *y, int *z, int row, int col)
{
    int r, c;
    for (r=0;r<row;r++)
        for (c=0;c<col;c++)
            *z++=(*x++)+(*y++);
}
/*Matrix Transpose*/
void mtranspose(int *x, int *y, int row, int col)
{
    int r, c;
    for (r=0;r<col;r++)
        for (c=0;c<row;c++)
            *y++=*(x+((c*col)/*new row*/+r/*new col*/));
}


int main(void)
{
    int a[2][3]={{1,3,1},{1,0,0}};
    int b[2][3]={{0,0,5},{7,5,0}};
    int c[2][3]={};
    int d[2][3]={{1,2,3},{0,-6,7}};
    int e[3][2]={};
    int **f=make2darr(2, 3);
    free(f);
    madd((int *)a, (int *)b, (int *)c, 2, 3);
    mprint((int *)c, 2, 3);
    printf("\n");
    mtranspose((int *)d, (int *)e, 2, 3);
    mprint((int *)e, 3, 2);
    return 0;
}

