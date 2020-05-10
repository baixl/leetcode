package leetcode;

import java.util.HashMap;

/**
 * leetcode 第1题 twosum
 * <p>
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * <p>
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * <p>
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * <p>
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * <p>
 * 解题思路：由于不能重复使用数组中的元素，使用一个额外的hashmap来保存已遍历过元素的下标：key：离目标值的差值，val：当前元素的下标
 **/

public class _1_TwoSum {

    /**
     * @param nums
     * @param target
     * @return
     */
    public int[] twoSum(int[] nums, int target) {
        int[] ret = {0, 0};
        if (nums == null || nums.length == 0) return ret;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                ret[0] = map.get(nums[i]);
                ret[1] = i;
                break;
            } else {
                int reset = target - nums[i];
                map.put(reset, i);
            }
        }

        return ret;
    }
}
