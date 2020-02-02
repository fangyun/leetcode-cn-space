int* relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size, int *returnSize) {
	int map[1001] = { 0 };
	for (int i = 0; i < arr1Size; i++) {
		map[arr1[i]] += 1;
	}
	int k = 0;
	for (int i = 0; i < arr2Size; i++) {
		for (int j = 0; j < map[arr2[i]]; j++) {
			arr1[k++] = arr2[i];
		}
		map[arr2[i]] = 0;
	}
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < map[i]; j++) {
			arr1[k++] = i;
		}
	}
	*returnSize = arr1Size;
	return arr1;
}
