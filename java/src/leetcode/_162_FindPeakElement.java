package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/18
 * <p>
 * description:
 * A peak element is an element that is greater than its neighbors.
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 * You may imagine that num[-1] = num[n] = -∞.
 * For example, in array [1, 2, 3, 1], 3 is a peak element
 * and your function should return the index number 2.
 * click to show spoilers.
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 */
public class _162_FindPeakElement {
    public int findPeakElement(int[] nums) {
        if (nums == null || nums.length == 0) return -1;
        if (nums.length == 1) return 0;
        int start = nums[0];
        int end = Integer.MIN_VALUE;


        int index = 0;
        for (int i = 1; i < nums.length; i++) {
            if (i == 1 && nums[i] < nums[i - 1]) {
                return i - 1;
            } else if (i < nums.length - 1) {
                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                    return i;
                }

            } else if (i == nums.length - 1) {
                if (nums[i] > nums[i - 1])
                    return i;

            }
        }

        return -1;
    }

    public static void main(String[] args) {
        _162_FindPeakElement object = new _162_FindPeakElement();
        int[] nums = {2, 1};
        System.out.println(object.findPeakElement(nums));
    }
}
