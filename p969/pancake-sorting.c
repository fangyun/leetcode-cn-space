/*
 * pancake-sorting.c
 *
 *  Created on: Feb 2, 2020
 *      Author: yunfang
 */

#include "solution.h"
#include "stdio.h"

int main() {
	int a[] = { 3, 2, 4, 1, 5 };
	int returnSize = 0;
	int *b = pancakeSort(a, 5, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", b[i]);
	}
}

