/*
 Find the maximally intersecting subset of ranges
 http://stackoverflow.com/questions/15013800/find-the-maximally-intersecting-subset-of-ranges
*/
#include <stdio.h>
static int cmp(const void *p, const void *q)
{
	int i = ((int *)p)[0], j = ((int *)q)[0];
	return (i-j);
}

int main(void)
{
	int start[7] = {12, 14, 15, 17, 20, 62, 64};
	int end[7]   = {25, 27, 22, 21, 65, 70, 80};
	int tmp[14][2];
	int curmax = 0, max = 0;
	int i = 0, j = 0, k = 0;
	while (1) {
		if (start[i] < end[j]) {
			tmp[k][0] = start[i++];
			tmp[k][1] = 1;
		} else if (start[i] >= end[j]) {
			tmp[k][0] = end[j++];
			tmp[k][1] = -1;
		}
		k++;
		if (i>6 && j>6) break; /* tricky: OBOB error */
	}
	//for (k=0; k<14; k++)
	//	printf("%d, %d\n", tmp[k][0], tmp[k][1]);
	qsort(tmp, 14, sizeof(int)*2, cmp);
	//printf("--------------\n");
	//for (k=0; k<14; k++)
	//	printf("%d, %d\n", tmp[k][0], tmp[k][1]);
	for (k=0; k<14; k++) {
		if (tmp[k][1]==1) {
			curmax++;
			if (curmax > max) max = curmax;
		} else {
			curmax--;
		}
		printf("%d, %d, %d, %d\n", tmp[k][0], tmp[k][1], curmax, max);
	}
}

