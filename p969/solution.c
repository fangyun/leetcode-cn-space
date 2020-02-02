#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int*) a - *(int*) b;
}

void reverse(int start, int end, int *A) {
	while (start < end) {
		int tmp = A[start];
		A[start] = A[end];
		A[end] = tmp;
		start++;
		end--;
	}
}

int* pancakeSort(int *A, int ASize, int *returnSize) {
	if (!A || ASize == 1) {
		return NULL;
	}

	*returnSize = 0;

	//因为每个数只需要两次翻转，且第一个数不需要翻转，实际取 ASize*2-1就可以.
	int *ret = (int*) calloc(ASize * 2, sizeof(int)); //保持最后元素置为'\0'不用，所以使用ASize.
	int *B = (int*) calloc(ASize + 1, sizeof(int));
	for (int i = 0; i < ASize; i++) {
		B[i] = A[i];
	}
	qsort(B, ASize, sizeof(int), cmp);
	for (int i = ASize - 1; i > 0; i--) {
		int maxPos;
		for (maxPos = 0; maxPos < ASize; maxPos++) {
			if (A[maxPos] == B[i]) {
				break;
			}
		}
		if (maxPos == i) { // 已经是最大值位置，不用翻转.
			continue;
		}
		/* 第一次翻转，从0到j*/
		ret[(*returnSize)++] = maxPos + 1;
		reverse(0, maxPos, A);
		/* 第二次翻转，从0到(i=排序的位置)*/
		ret[(*returnSize)++] = i + 1;
		reverse(0, i, A);
	}
	return ret;
}
