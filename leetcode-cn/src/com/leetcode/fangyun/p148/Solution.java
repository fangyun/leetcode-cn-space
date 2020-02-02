package com.leetcode.fangyun.p148;

class Solution {
	public ListNode sortList(ListNode head) {
		ListNode h, h1, h2, pre, res;
		h = head;
		int length = 0, intv = 1;
		while (h != null) {
			h = h.next;
			length++;
		}
		res = new ListNode(0);
		res.next = head;
		while (intv < length) {
			pre = res;
			h = res.next;
			while (h != null) {
				// begin
				int i = intv;
				h1 = h;
				while (i > 0 && h != null) {
					h = h.next;
					i--;
				}
				if (i > 0) {
					break; // 在找h2过程中，如果链表剩余元素个数少于intv，则无需合并环节，直接break，执行下一轮合并；
				}
				// end:根据intv找到合并单元1的头部h1

				// begin
				i = intv;
				h2 = h;
				while (i > 0 && h != null) {
					h = h.next;
					i--;
				}
				// end:根据intv找到合并单元2的头部h2

				int c1 = intv;
				int c2 = intv - i; // 若h2存在，但以h2为头部的剩余元素个数少于intv，也执行合并环节，h2单元的长度为c2 = intv - i

				while (c1 > 0 && c2 > 0) {
					if (h1.val < h2.val) {
						pre.next = h1;
						h1 = h1.next;
						c1--;
					} else {
						pre.next = h2;
						h2 = h2.next;
						c2--;
					}
					pre = pre.next;
				} // h1和h2排序合并

				// begin
				pre.next = c1 == 0 ? h2 : h1;
				while (c1 > 0 || c2 > 0) {
					pre = pre.next;
					c1--;
					c2--;
				} // end: 合并单元尾部同时也作为下次合并的辅助头部pre

				pre.next = h; // 合并完后，需要修改新的合并单元的尾部pre指针指向下一个合并单元头部h。（在寻找h1, h2环节中，h指针已经被移动到下一个单元头部）
			}
			intv *= 2; // 每轮合并完成后将单元长度×2，切换到下轮合并
		}
		return res.next;
	}
}
