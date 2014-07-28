#include <stdio.h>
/*Given val, return whtther bit i on or off*/
int GetBit(int val, int i)
{
    return !!((1<<i) & val);
}
/*Given val, return val plus bit i set*/
int SetBit(int val, int i)
{
    return ((1<<i) | val);
}
/*Given val, clear bit i*/
int ClearBit(int val, int i)
{
    return val & ~(1<<i);
}
/*Given val, clear from MSB to bit i*/
int ClearMSB(int val, int i)
{
    int mask = (1<<i)-1;/*mask to leave LSB to i*/
    return val & mask;
}
/*Given val, clear from LSB to bit i*/
int ClearLSB(int val, int i)
{
    int mask = ~((1<<i)-1);
    return val & mask;
}
int main(void)
{
    int x = 0xfffffff0;
    x=SetBit(x, 1);
    printf("SetBit(1)=%.8x\n", x);
    printf("GetBit(1)=%.8x, x=%.8x\n", GetBit(x, 1), x);
    x=ClearBit(x, 1);
    printf("ClearBit(1)=%.8x\n", x);
    x=ClearMSB(x, 28);
    printf("ClearMSB(28)=%.8x\n", x);
    x=ClearLSB(x, 8);
    printf("ClearLSB(8)=%.8x\n", x);
    return 0;
}

