package com.leetcode.fangyun.p148;

public class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}

	public static ListNode asList(int... a) {
		ListNode h = new ListNode(a[0]);
		ListNode p = h;
		for (int i = 1; i < a.length; i++) {
			ListNode n = new ListNode(a[i]);
			p.next = n;
			p = p.next;
		}
		return h;
	}
}
