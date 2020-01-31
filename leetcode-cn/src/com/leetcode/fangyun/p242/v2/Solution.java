package com.leetcode.fangyun.p242.v2;

class Solution {

	public boolean isAnagram(String s, String t) {
		if (s.length() != t.length()) {
			return false;
		}
		int[] counters = new int[26];
		for (int i = 0; i < s.length(); i++) {
			counters[s.charAt(i) - 'a']++;
			counters[t.charAt(i) - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (counters[i] != 0) {
				return false;
			}
		}
		return true;
	}
}
