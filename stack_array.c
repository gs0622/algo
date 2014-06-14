#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX]={};
int top=-1;
void push(int v)
{
    if ((MAX-1)>top) stack[++top]=v; else printf("full\n");
}
int pop(void)
{
    if (top>=0) return stack[top--]; else printf("empty\n");
    return 0;
}
void show(void)
{
    int i;
    for (i=top;i>=0;i--) printf("%d ", stack[i]);
    printf("\n");
}
int main(void)
{
    int i, j;
    while (1) {
        printf("0. push 1.pop\n");
        if (scanf("%d", &i)!=1) break;
        if (0==i) printf("push? "), scanf("%d", &j), push(j);
        if (1==i) printf("pop %d\n", pop());
        show();
    }
    return 0;
}