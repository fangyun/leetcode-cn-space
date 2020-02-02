/*
 * sort-the-matrix-diagonally.c
 *
 *  Created on: Jan 31, 2020
 *      Author: yunfang
 */
#include "solution.h"

int main() {
	int r1[] = { 3, 3, 1, 1 };
	int r2[] = { 2, 2, 1, 2 };
	int r3[] = { 1, 1, 1, 2 };
	int *mat[] = { r1, r2, r3 };

	int m = 3;
	int n = 4;
	int returnSize = 0;
	int *returnColumnSizes = 0;
	diagonalSort(mat, m, &n, &returnSize, &returnColumnSizes);
}
