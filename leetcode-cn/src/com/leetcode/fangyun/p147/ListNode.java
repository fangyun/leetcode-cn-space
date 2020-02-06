package com.leetcode.fangyun.p147;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
	}

	static ListNode asList(int... a) {
		ListNode h = new ListNode(a[0]);
		ListNode res = h;
		for (int i = 1; i < a.length; i++) {
			h.next = new ListNode(a[i]);
			h = h.next;
		}
		return res;
	}

	public String toString() {
		List<Integer> a = new ArrayList<>();
		ListNode p = this;
		while (p != null) {
			a.add(p.val);
			p = p.next;
		}
		return Arrays.toString(a.toArray());
	}
}
