/*gcc -Wl,--no-as-needed,-lrt shuffle2.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
long long profile_us(void (*foo)(int*, int), int *const arg1, const int arg2)
{
    struct timespec s, e;
    long long us;
    assert(foo);
    clock_gettime(CLOCK_MONOTONIC, &s);
    foo(arg1, arg2);
    clock_gettime(CLOCK_MONOTONIC, &e);
    //printf("foo(%p, %d) t=%lus %luns\n", arg1, arg2, (e.tv_sec-s.tv_sec), (e.tv_nsec-s.tv_nsec));
    us = (e.tv_sec-s.tv_sec) * 1000000;
    us += (e.tv_nsec-s.tv_nsec)/1000;
    return us;
}
void print_array(int *p, int n)
{
    for (;p&&n>0;n--,p++) {
        printf("%.2d%s", *p, ((n-1)>0)? " ":"\n");
    }
}
void swap(int *p, int *q)
{
    int tmp;
    assert(p&&q);
    tmp = *p;
    *p = *q;
    *q = tmp;
}
/*shuffle with O(n) time complexity*/
void shuffle(int a[], int n)
{
    int i, j;
    srand(time(NULL));
    for (i=n-1;i>0;i--) {
        j = rand()%(i+1);
        swap(&a[i], &a[j]);
    }
}
//void getShuffleList(unsigned int* shuffleList, const unsigned int shuffleNumber)
void getShuffleList(int* shuffleList, int shuffleNumber)
{
    asm volatile (
        "lea     63(%rsi), %rcx\r\n"
        "xor     %rax, %rax\r\n"
        "test    %rsi, %rsi\r\n"
        "je,pn   0f\r\n"
        "shr     $6, %rcx\r\n"
        "mov     %rsp, %r9\r\n"
        "lea     (,%rcx,8), %r8\r\n"
        "sub     %r8, %rsp\r\n"
        "mov     %rsp, %rdx\r\n"
        "64:\r\n"
        "mov     %rax, (%rdx)\r\n"
        "add     $8, %rdx\r\n"
        "loopne,pt   64b\r\n"
        "mov     %rsi, %rcx\r\n"
        "xor     %r8, %r8\r\n"
        "1:\r\n"
        "rdrand  %rax\r\n"
        "inc     %r8\r\n"
        "jnc,pn  1b\r\n"    /*  rdrand failed to get a number   */
        "xor     %rdx, %rdx\r\n"
        "div     %rsi\r\n"
        "bts     %rdx, (%rsp)\r\n"
        "jc      1b\r\n"    /*  number has been assigned    */
        "mov     %edx, (%rdi)\r\n"
        "add     $4, %rdi\r\n"
        "loopne,pt   1b\r\n"
        "mov     %r9, %rsp\r\n"
        "mov     %r8, %rax\r\n"
        "0:\r\n"
    );
}
static void help(char *name)
{
    printf(" usage: %s elements(default 10) loops(default 100)\r\n", name);
    exit(0);
}
int main(int argc, char **argv)
{
    int i, n, loop, *arr;
    long long us;
    if (argc>1 && 0==strcmp(argv[1], "--help")) help(argv[0]);
    n = (argc>1)? atoi(argv[1]) : 10;
    loop = (argc>2)? atoi(argv[2]) : 100;
    arr = malloc(sizeof(int)*n);
    for (i=0;i<n;i++) arr[i] = i;
    for (i=0,us=0;i<loop;i++) us += profile_us(shuffle, arr, n);
    printf("HP's shuffle arr[%d] %d loops takes %lld us, avg in %3.2f ms\n", n, loop, us, (double)us/(double)loop);
    for (i=0,us=0;i<loop;i++) us += profile_us(getShuffleList, arr, n);
    printf("YT's shuffle arr[%d] %d loops takes %lld us, avg in %3.2f ms\n", n, loop, us, (double)us/(double)loop);
    if (n<50) printf("arr[%d]=", n), print_array(arr, n);
    free(arr);
    return 0;
}

