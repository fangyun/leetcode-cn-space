package com.leetcode.fangyun.p147;

class InsertionSortList {
	public static void main(String[] args) {
		Solution sol = new Solution();
		ListNode ls = ListNode.asList(4, 2, 1, 3);
		ListNode res = sol.insertionSortList(ls);
		assertEquals(1, res.val);
		assertEquals(2, res.next.val);
		assertEquals(3, res.next.next.val);
		assertEquals(4, res.next.next.next.val);

		ls = ListNode.asList(-1, 5, 3, 4, 0);
		res = sol.insertionSortList(ls);
		assertEquals(-1, res.val);
		assertEquals(0, res.next.val);
		assertEquals(3, res.next.next.val);
		assertEquals(4, res.next.next.next.val);
		assertEquals(5, res.next.next.next.next.val);

		ls = ListNode.asList(2147483647, 2147483646);
		res = sol.insertionSortList(ls);
		assertEquals(2147483646, res.val);
		assertEquals(2147483647, res.next.val);
	}

	static boolean assertEquals(int a, int b) {
		return a == b;
	}
}
