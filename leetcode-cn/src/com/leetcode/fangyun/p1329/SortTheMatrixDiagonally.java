package com.leetcode.fangyun.p1329;

public class SortTheMatrixDiagonally {

	public static void main(String[] args) {
		int[][] mat = { { 3, 3, 1, 1 }, { 2, 2, 1, 2 }, { 1, 1, 1, 2 } };
		print(mat);
		mat = new Solution().diagonalSort(mat);
		print(mat);
	}

	static void print(int[][] mat) {
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[i].length; j++) {
				System.out.print(mat[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}

}
