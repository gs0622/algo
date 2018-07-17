#include <stdio.h>
#include <stdlib.h>
int rand5(void)
{
	return rand() % 5;
}
int rand2(void)
{
	int x = rand5();
	if (x == 4) return rand2();
	return x % 2;
}
int rand7()
{
	int x = rand2() * 4 + rand2() * 2 + rand2();
	if (7 == x) return rand7();
	return x;
}
int main(void)
{
	int i, x, cnt[7] = {};
	srand(time(NULL));
	for (i = 0; i < 10000; i += 1) {
		x = rand7();
		cnt[x] += 1;
		//printf("%d\n", x);
	}
	for (i = 0; i < 7; i += 1) printf("%d ", cnt[i]);
	printf("\n");
	return 0;
}
