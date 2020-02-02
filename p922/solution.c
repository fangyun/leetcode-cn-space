int* sortArrayByParityII(int *A, int ASize, int *returnSize) {
	int odd[ASize / 2];
	int even[ASize / 2];
	int o = 0;
	int e = 0;
	for (int i = 0; i < ASize; i++) {
		if (A[i] % 2 == 0) {
			even[e++] = A[i];
		} else {
			odd[o++] = A[i];
		}
	}
	for (int i = 0; i < ASize / 2; i++) {
		A[2 * i] = even[i];
		A[2 * i + 1] = odd[i];
	}
	*returnSize = ASize;
	return A;
}
