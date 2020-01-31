package com.leetcode.fangyun.p922;

class Solution {
	public int[] sortArrayByParityII(int[] A) {
		int[] odd = new int[A.length / 2];
		int[] even = new int[A.length / 2];
		int o = 0;
		int e = 0;
		for (int i = 0; i < A.length; i++) {
			if (A[i] % 2 == 0) {
				even[e++] = A[i];
			} else {
				odd[o++] = A[i];
			}
		}
		for (int i = 0; i < A.length / 2; i++) {
			A[2 * i] = even[i];
			A[2 * i + 1] = odd[i];
		}
		return A;
	}
}
