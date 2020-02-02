/*
 * solution.c
 *
 *  Created on: Jan 31, 2020
 *      Author: yunfang
 */

#include<stdlib.h>
#include"solution.h"

void inorderWalk(struct TreeNode *node, int *elements, int *size) {
	if (node != NULL) {
		inorderWalk(node->left, elements, size);
		elements[(*size)++] = node->val;
		inorderWalk(node->right, elements, size);
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

#define NODE_SIZE 10000
int elements[NODE_SIZE];

int* getAllElements(struct TreeNode *root1, struct TreeNode *root2, int *returnSize) {
	int size = 0;
	inorderWalk(merge(root1, root2), elements, &size);
	*returnSize = size;
	return elements;
}
