package com.leetcode.fangyun.p1122;

import java.util.Arrays;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Map.Entry;

class Solution {
	public int[] relativeSortArray(int[] arr1, int[] arr2) {
		Map<Integer, Integer> map2 = new LinkedHashMap<>();
		for (int a : arr2) {
			map2.put(a, 0);
		}
		for (int i = 0; i < arr1.length; i++) {
			if (map2.containsKey(arr1[i])) {
				int count = map2.get(arr1[i]);
				map2.put(arr1[i], ++count);
				arr1[i] = -1;
			}
		}
		Arrays.sort(arr1);
		int i = 0;
		for (Entry<Integer, Integer> e : map2.entrySet()) {
			for (int j = i; j < i + e.getValue(); j++) {
				arr1[j] = e.getKey();
			}
			i += e.getValue();
		}
		return arr1;
	}
}
