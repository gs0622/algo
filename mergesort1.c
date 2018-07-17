void merge(int arr_left[], int sz_left, int arr_right[], int sz_right, int aux[])
{
	int  i = 0, j = 0, k = 0;
	while (i < sz_left && j < sz_right)
		aux[k++] = (arr_left[i] < arr_right[j])? arr_left[i++]: arr_right[j++];
	while (i < sz_left) aux[k++] = arr_left[i++];
	while (j < sz_right) aux[k++] = arr_right[j++];
	for (i = 0; i < sz_left + sz_right; i += 1)
		arr_left[i] = aux[i];
}
void mergesort(int arr[], int sz, int aux[])
{
	if (1 >= sz) return;
	int *arr_left, *arr_right, sz_left, sz_right;
	sz_left = sz / 2, sz_right = sz - sz_left;
	arr_left = &arr[0], arr_right = &arr[0+sz_left]; 
	mergesort(arr_left, sz_right, aux);
	mergesort(arr_right, sz_right, aux);
	merge(arr_left, sz_left, arr_right, sz_right, aux);
}
int main(void)
{
	int arr[] = {7, 6, 5, 4, 3, 2, 1, 0};
	int aux[8];
	mergesort(arr, 8, aux);
	return 0;
}
