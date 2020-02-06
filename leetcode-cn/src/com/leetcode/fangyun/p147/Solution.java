package com.leetcode.fangyun.p147;

class Solution {
	public ListNode insertionSortList(ListNode head) {
		if (head == null || head.next == null) {
			return head;
		}
		ListNode pre = new ListNode(Integer.MIN_VALUE);
		ListNode min = pre;
		ListNode next = new ListNode(Integer.MAX_VALUE);
		pre.next = next; // sorted
		ListNode curr = head;
		ListNode newCurr;
		while (curr != null) {
			newCurr = curr.next;
			while (next != null) {
				// 到达合适位置，插入进去：[min,...,pre,next...,max] --> [min,...,pre,curr,next...,max]
				if (pre.val <= curr.val && curr.val <= next.val) {
					pre.next = curr;
					curr.next = next;
					break;
				} else {// 如果没有卡到合适的位置，pre和next就往后移动
					pre = next;
					next = next.next;
				}
			}
			pre = min;
			next = min.next;
			curr = newCurr;
		}
		head = pre.next;
		while (head.next != null) {
			pre = head;
			head = head.next;
		}
		pre.next = null;
		return min.next;
	}
}
