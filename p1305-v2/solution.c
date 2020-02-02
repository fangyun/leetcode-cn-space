/*
 * solution.c
 *
 *  Created on: Jan 31, 2020
 *      Author: yunfang
 */

#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "solution.h"

void arraryCopy(void *dest, int dIndex, const void *src, int sIndex, int len, int destLen, size_t size) {
	uint8_t *udest = (uint8_t*) dest;
	uint8_t *usrc = (uint8_t*) src;
	dIndex *= size;
	sIndex *= size;
	len *= size;
	destLen *= size;

	if (src != dest) {
		memcpy(&udest[dIndex], &usrc[sIndex], len);
	} else {
		if (dIndex > sIndex) {
			uint8_t *tmp = (uint8_t*) calloc(destLen, size);
			memcpy(tmp, &udest[dIndex], (destLen - dIndex));
			memcpy(&udest[dIndex], &usrc[sIndex], len);
			memcpy(&udest[dIndex + len], tmp, (destLen - dIndex));
			free(tmp);
		} else if (sIndex > dIndex) {
			memcpy(&udest[dIndex], &usrc[sIndex], (destLen - sIndex) + 1);
		} else
			return;
	}
}

typedef struct {
	int current;
	int size;
	int increment_rate;
	int *elements;
} List;

void init(List *const list) {
	list->size = 100;
	list->increment_rate = 50;
	list->elements = (int*) calloc(sizeof(int), list->size);
	list->current = -1;
}

void wide(List *const list) {
	list->size += list->increment_rate;
	int *newArr = (int*) calloc(sizeof(int), list->size);
	arraryCopy(newArr, 0, list->elements, 0, list->current, list->size, sizeof(int));
	free(list->elements);
	list->elements = newArr;
}

bool add(List *const list, int e) {
	if (++list->current < list->size) {
		list->elements[list->current] = e;
		return true;
	} else {
		wide(list);
		list->elements[list->current] = e;
		return true;
	}
}

void inorderWalk(struct TreeNode *node, List *const ls) {
	if (node != NULL) {
		inorderWalk(node->left, ls);
		add(ls, node->val);
		inorderWalk(node->right, ls);
	}
}

struct TreeNode* merge(struct TreeNode *r1, struct TreeNode *r2) {
	if (r1 == NULL) {
		return r2;
	}
	if (r2 == NULL) {
		return r1;
	}
	if (r1->val > r2->val) { //r1.left=loc_r1(min(r1.left)>r2>r2.left)
		struct TreeNode *keep = r2->right;
		r2->right = NULL;
		r1->left = merge(r1->left, r2);
		return merge(r1, keep);
	} else { //r2.left=loc_r2(min(r2.left)>r1>r1.left)
		struct TreeNode *keep = r1->right;
		r1->right = NULL;
		r2->left = merge(r1, r2->left);
		return merge(keep, r2);
	}
}

int* getAllElements(struct TreeNode *root1, struct TreeNode *root2, int *returnSize) {
	List list;
	init(&list);
	inorderWalk(merge(root1, root2), &list);
	*returnSize = list.current + 1;
	return list.elements;
}
