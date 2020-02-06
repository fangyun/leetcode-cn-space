package com.leetcode.fangyun.p973;

import java.util.Arrays;

public class KClosestPointsToOrigin {

	public static void main(String[] args) {
		Solution s = new Solution();
		int[][] points = { { 3, 3 }, { 5, -1 }, { -2, 4 } };
		int[][] res = s.kClosest(points, 2);
		assert Arrays.equals(new int[] { 3, 3 }, res[0]);
		assert Arrays.equals(new int[] { -2, 4 }, res[1]);
	}

}
