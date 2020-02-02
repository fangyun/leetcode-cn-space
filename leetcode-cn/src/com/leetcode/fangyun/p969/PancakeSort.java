package com.leetcode.fangyun.p969;

import java.util.List;

public class PancakeSort {

	public static void main(String[] args) {
		int a[] = { 3, 2, 4, 1, 5 };
		Solution s = new Solution();
		List<Integer> b = s.pancakeSort(a);
		for (int i = 0; i < b.size(); i++) {
			System.out.printf("%d ", b.get(i));
		}
	}
}
