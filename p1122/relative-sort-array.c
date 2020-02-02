/*
 * relative-sort-array.c
 *
 *  Created on: Feb 1, 2020
 *      Author: yunfang
 */
#include "solution.h"
#include <stdio.h>

int main() {
	int arr1[] = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
	int arr2[] = { 2, 1, 4, 3, 9, 6 };
	int returnSize = 0;
	int *b = relativeSortArray(arr1, 11, arr2, 6, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}

