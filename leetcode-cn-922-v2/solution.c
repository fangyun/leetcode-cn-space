#include <stdlib.h>

int* sortArrayByParityII(int *A, int ASize, int *returnSize) {
	int *result = (int*) malloc(ASize * sizeof(int));
	int o = 1;
	int e = 0;
	for (int i = 0; i < ASize; i++) {
		if (A[i] % 2 == 0) {
			result[e] = A[i];
			e += 2;
		} else {
			result[o] = A[i];
			o += 2;
		}
	}
	*returnSize = ASize;
	return result;
}
