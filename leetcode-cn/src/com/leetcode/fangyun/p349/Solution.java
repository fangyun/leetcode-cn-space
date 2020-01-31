package com.leetcode.fangyun.p349;

import java.util.HashSet;
import java.util.Set;

class Solution {
	public int[] intersection(int[] nums1, int[] nums2) {
		Set<Integer> n1 = new HashSet<>();
		Set<Integer> n2 = new HashSet<>();
		for (int i = 0; i < nums1.length; i++) {
			n1.add(nums1[i]);
		}
		for (int i = 0; i < nums2.length; i++) {
			n2.add(nums2[i]);
		}
		n1.retainAll(n2);
		int[] a = new int[n1.size()];
		int i = 0;
		for (Integer n : n1) {
			a[i++] = n;
		}
		return a;
	}
}
