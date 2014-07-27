#include <stdio.h>
/*Given val, return whtther bit i on or off*/
int getbit(int val, int i)
{
    return !!((1<<i) & val);
}
/*Given val, return val plus bit i set*/
int setbit(int val, int i)
{
    return ((1<<i) | val);
}

