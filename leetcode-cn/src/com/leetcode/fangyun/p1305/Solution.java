package com.leetcode.fangyun.p1305;

import java.util.LinkedList;
import java.util.List;

class Solution {
	public List<Integer> inorderWalk(List<Integer> ls, TreeNode root) {
		TreeNode current = root;
		if (current != null) {
			inorderWalk(ls, current.left);
			ls.add(current.val);
			inorderWalk(ls, current.right);
		}
		return ls;
	}

	public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
		return inorderWalk(new LinkedList<Integer>(), merge(root1, root2));
	}

	/**
	 * 
	 * @param r1
	 * @param r2
	 * @return sort(r1+r2)
	 */
	public TreeNode merge(TreeNode r1, TreeNode r2) {
		if (r1 == null) {
			return r2;
		}
		if (r2 == null) {
			return r1;
		}
		if (r1.val < r2.val) { // r2.left = loc_r2(r1.left<r1<min(r2.left))
			TreeNode keep = r1.right;
			r1.right = null;
			r2.left = merge(r1, r2.left);
			return merge(keep, r2);
		} else { // r1.left=loc_r1(min(r1.left)>r2>r2.left)
			TreeNode keep = r2.right;
			r2.right = null;
			r1.left = merge(r1.left, r2);
			return merge(r1, keep);
		}
	}
}