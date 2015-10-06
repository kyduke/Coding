// http://www.careercup.com/question?id=5737921569095680

import java.util.*;

public class KthSortedSubarray {
	public static int getKthElementFromSortedSubarray(int[] arr, int a, int b, int k) {
		int[] subarray;
		
		if (a < 0 || b < 0 || a >= b || k > (b - a) || a >= arr.length || b > arr.length) return -1;
		
		subarray = new int[b - a];
		System.arraycopy(arr, a, subarray, 0, b - a);
		Arrays.sort(subarray);
		
		return subarray[k];
	}

	public static void main(String[] args) {
		int[] arr = {3, 4, 5, 0, 1, 2};
		
		System.out.println(getKthElementFromSortedSubarray(arr, 2, 5, 2));
	}
}
