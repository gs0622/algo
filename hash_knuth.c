#include <stdio.h>
#include <stdlib.h>
unsigned int hash(long long key)
{
	/*Knuth's multiplicative method*/
	return (unsigned int)((key * 2654435761) % 4294967296);
}

int main(int argc, char *argv[])
{
	if (argc < 2) return 0;
	long long key = atoll(argv[1]);
	printf("h(%lld)=%u\n", key, hash(key));
	return 0;
}

