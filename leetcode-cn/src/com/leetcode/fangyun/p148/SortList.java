package com.leetcode.fangyun.p148;

public class SortList {

	public static void main(String[] args) {
		ListNode n1 = ListNode.asList(4, 2, 1, 3);
		Solution s = new Solution();
		ListNode h = s.sortList(n1);
		while (h != null) {
			System.out.printf("%d ", h.val);
			h = h.next;
		}
	}
}
