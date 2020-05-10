package leetcode;

import java.util.Arrays;

/**
 * author：baixiaoling
 * date: 2017/12/21
 * <p>
 * description:
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */
public class _53_MaximumSubarray {
    /*
    动态规划：局部最优与全局最优解法
    基本思路：在每一步，维持两个变量，全局最优和局部最优
     */
    public int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;
        int max = Integer.MIN_VALUE;
        int currentSum = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if (currentSum <= 0) {
                currentSum = nums[i];
            } else {
                currentSum += nums[i];
            }
            if (currentSum > max) {
                max = currentSum;
            }
        }
        return max;
    }

    public int maxSubArray2(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int[] sum = new int[nums.length];

        int max = nums[0];
        sum[0] = nums[0];

        for (int i = 1; i < nums.length; i++) {
            sum[i] = Math.max(nums[i], sum[i - 1] + nums[i]); // 局部最小值
            max = Math.max(max, sum[i]);// 全局最小值
        }
        return max;
    }

    public static void main(String[] args) {
        _53_MaximumSubarray object = new _53_MaximumSubarray();
        System.out.println(object.maxSubArray2(new int[]{-2, 1, -3, 4, -1, 2, 1, -5, 4}));
    }
}
