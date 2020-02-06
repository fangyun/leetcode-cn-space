package com.leetcode.fangyun.p1030;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Solution {
	class Node {
		int distance;
		int[] n = new int[2];

		Node(int d, int r, int c) {
			this.distance = d;
			this.n[0] = r;
			this.n[1] = c;
		}
	}

	public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
		List<Node> nodes = new ArrayList<>(R * C);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				Node n = new Node(Math.abs(i - r0) + Math.abs(j - c0), i, j);
				nodes.add(n);
			}
		}
		Collections.sort(nodes, new Comparator<Node>() {

			@Override
			public int compare(Node o1, Node o2) {
				return o1.distance - o2.distance;
			}

		});
		int[][] res = new int[nodes.size()][2];
		int i = 0;
		for (Node node : nodes) {
			res[i++] = node.n;
		}
		return res;
	}
}
