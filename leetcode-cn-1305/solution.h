/*
 * solution.h
 *
 *  Created on: Jan 30, 2020
 *      Author: yunfang
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_
#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int* getAllElements(struct TreeNode *root1, struct TreeNode *root2, int *returnSize);

#endif /* SOLUTION_H_ */
