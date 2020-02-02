#include <stdlib.h>
#include <stdbool.h>

int* intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
	int temp = nums1Size > nums2Size ? nums2Size : nums1Size;
	int *array = (int*) malloc(sizeof(int) * temp);
	int size = 0;
	for (int i = 0; i < nums1Size; i++) {
		for (int j = 0; j < nums2Size; j++) {
			if (nums1[i] == nums2[j]) {
				bool added = false;
				for (int k = 0; k < size; k++) {
					if (array[k] == nums1[i]) {
						added = true;
					}
				}
				if (!added) {
					array[size++] = nums1[i];
				}
			}
		}
	}
	*returnSize = size;
	return array;
}
