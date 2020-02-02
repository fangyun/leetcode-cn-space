int* sortArrayByParityII(int *A, int ASize, int *returnSize) {
	int j = 1;
	for (int i = 0; i < ASize; i += 2) {
		if (A[i] % 2 == 1) {
			while (A[j] % 2 == 1) {
				j += 2;
			}
			int tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	*returnSize = ASize;
	return A;
}
