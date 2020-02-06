package com.leetcode.fangyun.p1030;

import java.util.Arrays;

public class MatrixCellsInDistanceOrder {

	public static void main(String[] args) {
		Solution s = new Solution();
		int[][] a = s.allCellsDistOrder(2, 3, 1, 2);
		for (int i = 0; i < a.length; i++) {
			System.out.printf("%s, ", Arrays.toString(a[i]));
		}
	}
}
