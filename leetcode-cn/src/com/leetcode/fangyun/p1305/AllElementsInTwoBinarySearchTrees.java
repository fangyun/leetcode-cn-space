package com.leetcode.fangyun.p1305;

import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.List;

public class AllElementsInTwoBinarySearchTrees {
	public static TreeNode insert(TreeNode root, int a) {
		if (root == null)
			return new TreeNode(a);
		if (root.val > a)
			root.left = insert(root.left, a);
		if (root.val < a)
			root.right = insert(root.right, a);
		return root;
	}

	public static void main(String[] args) throws IOException {
		InputStream is = AllElementsInTwoBinarySearchTrees.class
				.getResourceAsStream("/com/leetcode/fangyun/p1305/testcase.txt");
		String[] t = new String(is.readAllBytes()).split("\n");
		t[0] = t[0].substring(1);
		t[0] = t[0].substring(0, t[0].length() - 1);
		t[1] = t[1].substring(1);
		t[1] = t[1].substring(0, t[1].length() - 1);
		String[] v0 = t[0].split(",");
		String[] v1 = t[1].split(",");
		TreeNode r1 = null;
		for (String v : v0) {
			try {
				int a = Integer.parseInt(v);
				if (r1 == null) {
					r1 = new TreeNode(a);
				} else {
					r1 = insert(r1, a);
				}
			} catch (NumberFormatException e) {
				// ignore
			}
		}
		TreeNode r2 = null;
		for (String v : v1) {
			try {
				int a = Integer.parseInt(v);
				if (r2 == null) {
					r2 = new TreeNode(a);
				} else {
					r2 = insert(r2, a);
				}
			} catch (NumberFormatException e) {
				// ignore
			}
		}
		List<Integer> ls = new Solution().getAllElements(r1, r2);
		System.out.println(Arrays.toString(ls.toArray()));
	}
}
