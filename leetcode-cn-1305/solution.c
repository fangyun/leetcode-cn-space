#include "solution.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _LinkNode {
	int val;
	struct _LinkNode *next;
} List;

List* lastNode(List *ls) {
	List *p = ls;
	if (p) {
		while (p->next) {
			p = p->next;
		}
	}
	return p;
}

List* append(List *ls, int val) {
	List *newList = (List*) malloc(sizeof(List));
	newList->val = val;
	newList->next = NULL;
	if (ls) {
		List *last = lastNode(ls);
		last->next = newList;
		return ls;
	}
	return newList;
}

int* toArray(List *ls, int *returnSize) {
	int size = 0;
	List *p = ls;
	while (p != NULL) {
		size++;
		p = p->next;
	}
	*returnSize = size;
	if (size > 0) {
		p = ls;
		int *r = (int*) malloc(size * sizeof(int));
		for (int i = 0; i < size; i++) {
			r[i] = p->val;
			p = p->next;
		}
		return r;
	}
	return NULL;
}

List* inorderWalk(struct TreeNode *node, List *ls) {
	if (node != NULL) {
		ls = inorderWalk(node->left, ls);
		ls = append(ls, node->val);
		ls = inorderWalk(node->right, ls);
	}
	return ls;
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAllElements(struct TreeNode *root1, struct TreeNode *root2, int *returnSize) {
	List *ls = inorderWalk(merge(root1, root2), NULL);
	return toArray(ls, returnSize);
}
