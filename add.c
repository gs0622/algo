int add(int a, int b)
{
	if (0 == b) return a;
	int sum, carry;
	sum = a ^ b;
	carry = (a & b) << 1;
	return add(sum, carry);
}
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	if (3 > argc) return 0;
	printf("%d\n", add(atoi(argv[1]), atoi(argv[2])));
	return 0;
}
