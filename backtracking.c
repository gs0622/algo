/*string permutation*/
#include <stdio.h>
#include <string.h>
void backtracking(char arr[], int idx, int len)
{
    if (len-1==idx) printf("%s\n", arr);/*accept*/
    else {
        char *p = &arr[idx], *q=p;
        while (*p) {
            if (*p!=*q) *p^=*q, *q^=*p, *p^=*q;/*select arr[idx]*/
            backtracking(arr, idx+1, len);
            if (*p!=*q) *p^=*q, *q^=*p, *p^=*q;
            ++p;
        }
    }
}
int main(int argc, char *argv[])
{
    if (1==argc) return 0;
    backtracking(argv[1], 0, strlen(argv[1]));
    return 0;
}

