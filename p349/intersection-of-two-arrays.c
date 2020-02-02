#include <stdio.h>
#include "solution.h"

int main() {
	int nums1[] = { 1, 4, 4, 8, 2 };
	int nums2[] = { 4, 8, 0, 2, 6, 7, 55, 3 };
	int returnSize = 0;
	int *a = intersection(nums1, 5, nums2, 8, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", a[i]);
	}
}
