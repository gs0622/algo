#include <stdio.h>
int priority(char op)
{
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        default: return 0;
    }
}
void infix2postfix(char *in, char *out)
{
    char s[256]={}; /*stack*/
    int i, j, k;
    for (i=0,j=0,k=-1;in[i]!='\0';) {
        switch (in[i]) {
        case '(': s[++k]=in[i++]; break;
        case '+': case '-': case '*': case '/': case '%':
            while (priority(s[k])>=priority(in[i]))
                out[j++]=s[k--];
            s[++k]=in[i++];
            break;
        case ')':
            while (s[k]!='(') out[j++]=s[k--];
            k--,i++;
            break;
        default: out[j++]=in[i++];
        }
    }
    while (k>=0) out[j++]=s[k--];
}

int main(int argc, char *argv[])
{
    char buf[256];
    int i;
    for (i=0;i<argc-1;i++) {
        infix2postfix(argv[i+1], buf);
        printf("%s\n", buf);
    }
    return 0;
}
