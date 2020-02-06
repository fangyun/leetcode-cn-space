#include <stdio.h>
#include <stdlib.h>

#include "solution.h"

int main() {
	int returnSize;
	int **returnColumnSizes = (int**) malloc(sizeof(int*));
	int **a = allCellsDistOrder(2, 3, 1, 2, &returnSize, returnColumnSizes);
	for (int i = 0; i < returnSize; i++) {
		printf("[");
		for (int j = 0; j < **returnColumnSizes; j++) {
			printf("%d,", a[i][j]);
		}
		printf("]");
	}
}
