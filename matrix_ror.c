#include <stdio.h>
#include <stdlib.h>
void matrix_dump(int *arr, int row, int col)
{
	int r, c, *p = arr;
	for (r = 0; r < row; r += 1)
		for (c = 0; c < col; c += 1)
			printf("%d%s", *p++, (c == col - 1)? "\n": " ");
}
void matrix_ror(int *arr, int n)
{
	int i, layer, tail, offset, tmp;
	for (layer = 0; layer < n/2; layer += 1) {
		tail = n - layer - 1;
		for (i = layer; i < tail; i += 1) {
			offset = i - layer;
			tmp = arr[layer*n + i];
			arr[layer*n +i] = arr[(tail-offset)*n + layer];
			arr[(tail-offset)*n + layer] = arr[tail*n + (tail-offset)];
			arr[tail*n + (tail-offset)] = arr[i*n + tail];
			arr[i*n + tail] = tmp;
		}
	}
}

int main(void)
{
	int i, *p;
	int arr[4][4] = {};
	for (i = 0, p = (int *)arr; i < 16; i += 1) *p++ = i+1;
	matrix_dump((int *)arr, 4, 4);
	matrix_ror((int *)arr, 4);
	printf("%0*d\n", 20, 0);
	matrix_dump((int *)arr, 4, 4);
	return 0;
}
