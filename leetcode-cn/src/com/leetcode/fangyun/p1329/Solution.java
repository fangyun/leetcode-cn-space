package com.leetcode.fangyun.p1329;

import java.util.Arrays;

class Solution {
	public int[][] diagonalSort(int[][] mat) {
		if (mat.length == 0) {
			return mat;
		}
		int m = mat.length;
		int n = mat[0].length;
		for (int col = 0; col < n; col++) {
			int arrSize = Integer.min(m, n - col);
			if (arrSize == 1) {
				break;
			}
			int[] a = new int[arrSize];
			for (int i = 0; i < arrSize; i++) {
				a[i] = mat[i][i + col];
			}
			Arrays.sort(a);
			for (int i = 0; i < arrSize; i++) {
				mat[i][i + col] = a[i];
			}
		}
		for (int row = 1; row < m; row++) {
			int arrSize = Integer.min(m - row, n);
			if (arrSize == 1) {
				break;
			}
			int[] a = new int[arrSize];
			for (int i = 0; i < arrSize; i++) {
				a[i] = mat[i + row][i];
			}
			Arrays.sort(a);
			for (int i = 0; i < arrSize; i++) {
				mat[i + row][i] = a[i];
			}
		}
		return mat;
	}
}
