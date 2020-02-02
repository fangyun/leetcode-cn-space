/*
 * sort-list.c
 *
 *  Created on: Feb 2, 2020
 *      Author: yunfang
 */

#include <stdio.h>
#include <stdlib.h>
#include "solution.h"

typedef struct ListNode ListNode_t;

ListNode_t* asList(int *a, int size) {
	ListNode_t *h = NULL;
	if (size == 0) {
		return h;
	}
	h = (ListNode_t*) malloc(sizeof(ListNode_t));
	ListNode_t *p = h;
	p->val = a[0];
	for (int i = 1; i < size; i++) {
		p->next = (ListNode_t*) malloc(sizeof(ListNode_t));
		p = p->next;
		p->val = a[i];
	}
	return h;
}

int main() {
	int a[] = { 4, 2, 1, 3 };
	ListNode_t *n1 = asList(a, 4);
	ListNode_t *h = sortList(n1);
	while (h != NULL) {
		printf("%d ", h->val);
		h = h->next;
	}
}

