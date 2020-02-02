package com.leetcode.fangyun.p1122;

import java.util.Arrays;

public class RelativeSortArray {

	public static void main(String[] args) {
		int[] a1 = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
		int[] a2 = { 2, 1, 4, 3, 9, 6 };
		System.out.print(Arrays.toString(new Solution().relativeSortArray(a1, a2)));
	}

}
