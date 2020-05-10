package leetcode;

import java.util.Arrays;
import java.util.HashSet;

/**
 * author：baixiaoling
 * date: 2017/12/25
 * <p>
 * description:
 * Given an unsorted integer array, find the first missing positive integer.
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * Your algorithm should run in O(n) time and uses constant space.
 */
public class _41_FirstMissingPositive {
    /*
    要求O(n)和常数时间  下面方式是O(n)的空间，常数空间需要使用桶排序的思想？
     */
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            set.add(nums[i]);
        }

        int result = nums.length + 1;
        for (int i = 1; i <= nums.length; i++) {
            if (!set.contains(i)) {
                return i;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        _41_FirstMissingPositive object = new _41_FirstMissingPositive();
        int[] nums = {1, 2, 0};
        System.out.println(object.firstMissingPositive(nums));
    }
}
