#include <stdio.h>
#include <stdlib.h>
unsigned int hash(long long key)
{
	/*Knuth's multiplicative method*/
	return (unsigned int)((key * 2654435761) % 4294967296);
}
unsigned int hash2(unsigned int v)
{
        return v * (2654435761UL);
}
int main(int argc, char *argv[])
{
	if (argc < 2) return 0;
	long long key = atoll(argv[1]);
	unsigned int key2 = key;
	printf("h(%lld)=%u\n", key, hash(key));
	printf("h(%lld)=%u\n", key, hash2(key2));
	return 0;
}

