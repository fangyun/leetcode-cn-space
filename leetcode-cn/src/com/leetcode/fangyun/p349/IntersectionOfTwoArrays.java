package com.leetcode.fangyun.p349;

public class IntersectionOfTwoArrays {

	public static void main(String[] args) {
		int nums1[] = { 1, 4, 4, 8, 2 };
		int nums2[] = { 4, 8, 0, 2, 6, 7, 55, 3 };
		int[] a = new Solution().intersection(nums1, nums2);
		for (int i = 0; i < a.length; i++) {
			System.out.printf("%d ", a[i]);
		}
	}

}
