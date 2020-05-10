package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/3
 * <p>
 * description:
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest product.
 * <p>
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 * <p>
 * 解题思路：http://www.cnblogs.com/grandyang/p/4028713.html
 * 动态规划：和53题最大连续子序列和相似，但比求和复杂的是，乘积遇到负数时需要缓存当前的最小负数，因为当下次遇到负数时可能会成为最大值
 * 当遇到0时，乘积也会变为0
 */
public class _152_MaximumProductSubarray {
    public int maxProduct(int[] nums) {
        int reult = 0;
        if (nums == null || nums.length == 0) return reult;
        if (nums.length == 1) return nums[0];

        int[] dpMax = new int[nums.length];
        int[] dpMin = new int[nums.length];
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.length; i++) {
            // 状态转移公式
            dpMax[i] = Math.max(Math.max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]), nums[i]);
            dpMin[i] = Math.min(Math.min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]), nums[i]);
            result = Math.max(dpMax[i], result);
        }
        return result;
    }

    public static void main(String[] args) {
        _152_MaximumProductSubarray object = new _152_MaximumProductSubarray();
        System.out.println(object.maxProduct(new int[]{2, -1, 1, 1}));
    }
}
