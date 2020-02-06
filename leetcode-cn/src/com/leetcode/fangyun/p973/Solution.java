package com.leetcode.fangyun.p973;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Solution {
	class Point {
		double distance;
		int[] xy = new int[2];

		Point(int x, int y) {
			this.xy[0] = x;
			this.xy[1] = y;
			this.distance = Math.sqrt(x * x + y * y);
		}
	}

	public int[][] kClosest(int[][] points, int K) {
		if (points.length == K) {
			return points;
		}
		List<Point> ls = new ArrayList<>(points.length);
		for (int i = 0; i < points.length; i++) {
			ls.add(new Point(points[i][0], points[i][1]));
		}
		Collections.sort(ls, new Comparator<Point>() {

			@Override
			public int compare(Point o1, Point o2) {
				return Double.compare(o1.distance, o2.distance);
			}
		});
		int[][] res = new int[K][2];
		for (int i = 0; i < K; i++) {
			res[i] = ls.get(i).xy;
		}
		return res;
	}
}
