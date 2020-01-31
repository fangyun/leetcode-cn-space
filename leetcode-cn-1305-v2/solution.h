/*
 * solution.h
 *
 *  Created on: Jan 31, 2020
 *      Author: yunfang
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int* getAllElements(struct TreeNode *root1, struct TreeNode *root2, int *returnSize);

#endif /* SOLUTION_H_ */
