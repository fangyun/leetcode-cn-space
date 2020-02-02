#include "solution.h"
#include <stdlib.h>

typedef struct ListNode ListNode_t;

struct ListNode* sortList(struct ListNode *head) {
	if (!head || !head->next) {
		return head;
	}
	//begin
	ListNode_t *slow = head, *fast = head->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	} //end:找中点

	//begin
	ListNode_t *tmp = slow->next;
	slow->next = NULL;
	//end:截断成两个List

	ListNode_t *left = sortList(head);
	ListNode_t *right = sortList(tmp);
	ListNode_t *p = (ListNode_t*) malloc(sizeof(ListNode_t));
	ListNode_t *h = p;
	while (left && right) {
		if (left->val < right->val) {
			p->next = left;
			left = left->next;
		} else {
			p->next = right;
			right = right->next;
		}
		p = p->next;
	} //合并排序

	p->next = left ? left : right;
	return h->next;
}
