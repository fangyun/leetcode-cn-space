/*
 * solution.h
 *
 *  Created on: Feb 2, 2020
 *      Author: yunfang
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* sortList(struct ListNode *head);

#endif /* SOLUTION_H_ */
