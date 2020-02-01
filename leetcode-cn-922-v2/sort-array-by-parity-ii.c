#include "solution.h"
#include <stdio.h>

int main() {
	int a[] = { 4, 2, 5, 7 };
	int returnSize = 0;
	int *b = sortArrayByParityII(a, 4, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}
