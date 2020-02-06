#include "solution.h"
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#define NDEBUG 1

typedef struct ListNode ListNode_t;

ListNode_t* insertionSortList(ListNode_t *head) {
	ListNode_t *min = (ListNode_t*) calloc(1, sizeof(ListNode_t));
	min->val = INT_MIN;
	ListNode_t *max = (ListNode_t*) calloc(1, sizeof(ListNode_t));
	max->val = INT_MAX;
	min->next = max;
	ListNode_t *curr = head;
	ListNode_t *pre = min;
	ListNode_t *next = max;

	ListNode_t *newCurr;
	while (curr) {
		newCurr = curr->next;
		while (next) {
			if (pre->val <= curr->val && curr->val <= next->val) {
				pre->next = curr;
				curr->next = next;
				break;
			} else {
				pre = next;
				next = next->next;
			}
		}
		pre = min;
		next = min->next;
		curr = newCurr;
	}
	assert(pre == min);
	assert(next == min->next);
	while (next->next) {
		pre = next;
		next = next->next;
	}
	pre->next = NULL;
	return min->next;
}
