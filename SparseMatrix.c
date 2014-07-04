#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int row;
    int col;
    int val;
} smatrix;
int SparseMatrix(int *a, int row, int col, smatrix **s)
{
    int i, j, k, cnt;
    smatrix *q;
    if (!a || !s) return 0;
    for (i=0,cnt=0;i<row;i++)
        for (j=0;j<col;j++)
            if (a[i*col+j]!=0) cnt++;
    printf("cnt=%d\n", cnt);
    q = malloc(sizeof(smatrix)*cnt);
    if (!q) {
        perror("no memory");
        return -1;
    }
    for (i=0,k=0;i<row;i++)
        for (j=0;j<col;j++)
            if (a[i*col+j]!=0)
                q[k].row = i, q[k].col = j, q[k++].val = a[i*col+j];
    *s = q;
    return cnt;
} 
int main(void)
{
    int i, j, sz, arr[2][3] = { {1, 0, 2}, {0, -1, 3} };
    smatrix *s;
    for (i=0;i<2;i++) {
        for (j=0;j<3;j++)
            printf("%.2d ", arr[i][j]);
        printf("\n");
    }
    sz = SparseMatrix((int *)arr, 2, 3, &s);
    for (i=0;i<sz;i++) printf("r:%d c:%d v:%d\n", s[i].row, s[i].col, s[i].val);
    return 0;
}

