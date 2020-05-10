package leetcode;

/**
 * author：baixiaoling
 * date: 2018/1/8
 * <p>
 * description:
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed,
 * the only constraint stopping you from robbing each of them is that adjacent houses have security system connected
 * and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * <p>
 * Given a list of non-negative integers representing the amount of money of each house,
 * determine the maximum amount of money you can rob tonight without alerting the police.
 * <p>
 * Credits:
 * Special thanks to @ifanchu for adding this problem and creating all test cases.
 * Also thanks to @ts for adding additional test cases.
 * 动态规划：
 * 1 使用dp数组 dp[num.length]表示每个元素对应的当前最大值，
 * 2 初始化：dp[0]= num[0], dp[1] = max(dp[0],num[1]);
 * 3 从2开始遍历： dp[i] = max( dp[i-2]+num[i], dp[i-1])
 */


public class _198_HouseRobber {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        dp[1] = Math.max(dp[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            dp[i] = Math.max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.length - 1];
    }

}
