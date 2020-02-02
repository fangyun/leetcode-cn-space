#include <stdlib.h>

int min(int a, int b) {
	return a < b ? a : b;
}

int comparator(const void *a, const void *b) {
	return (*(int*) a - *(int*) b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** diagonalSort(int **mat, int matSize, int *matColSize, int *returnSize, int **returnColumnSizes) {
	if (matSize == 0) {
		return mat;
	}
	int m = matSize;
	int n = *matColSize;
	for (int col = 0; col < n; col++) {
		int arrSize = min(m, n - col);
		if (arrSize == 1) {
			break;
		}
		int *a = malloc(arrSize * sizeof(int));
		for (int i = 0; i < arrSize; i++) {
			a[i] = mat[i][i + col];
		}
		qsort(a, arrSize, sizeof(int), comparator);
		for (int i = 0; i < arrSize; i++) {
			mat[i][i + col] = a[i];
		}
	}
	for (int row = 1; row < m; row++) {
		int arrSize = min(m - row, n);
		if (arrSize == 1) {
			break;
		}
		int *a = malloc(arrSize * sizeof(int));
		for (int i = 0; i < arrSize; i++) {
			a[i] = mat[i + row][i];
		}
		qsort(a, arrSize, sizeof(int), comparator);
		for (int i = 0; i < arrSize; i++) {
			mat[i + row][i] = a[i];
		}
	}
	*returnSize = matSize;
	*returnColumnSizes = matColSize;
	return mat;
}
