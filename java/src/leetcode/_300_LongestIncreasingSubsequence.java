package leetcode;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * author：baixiaoling
 * date: 2018/1/9
 * <p>
 * description:
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 * <p>
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101],
 * therefore the length is 4. Note that there may be more than one LIS combination,
 * it is only necessary for you to return the length.
 * <p>
 * Your algorithm should run in O(n2) complexity.
 * <p>
 * Follow up: Could you improve it to O(n log n) time complexity?
 * <p>
 * Credits:
 * Special thanks to @pbrother for adding this problem and creating all test cases.
 * <p>
 * 解题思路：
 * 求最长诋谮子序列的长度
 * 方法1 ：转化为求最长公共子序列，
 * 将数组排序，然后求原数组和排序后的数组的最长公共子序列
 * 方法2： 动态规划
 * http://www.cnblogs.com/felixfang/p/3875141.html
 * http://www.cnblogs.com/liyukuneed/archive/2013/05/26/3090402.html
 * <p>
 * 如何做到 O(n log n)？
 */
public class _300_LongestIncreasingSubsequence {
    /*
    方法1 ：利用LCS最长公共子序列
    这种方法空间利用率挺大，时间效率也不好，在leetcode上只超越了2.8%
     */
    public int lengthOfLIS(int[] nums) {
        if (nums == null) return 0;
        if (nums.length <= 1) {
            return nums.length;
        }
        // 为保证递增，需要去除数组中的重复元素，比如，数组是[2,2]不去重的结果就是2，去重的结果是1
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (set.contains(nums[i])) {
                continue;
            } else {
                set.add(nums[i]);
            }
        }
        int[] numsNew = new int[set.size()];
        int i = 0;
        for (Integer integer : set) {
            numsNew[i++] = integer;
        }
        Arrays.sort(numsNew);
        return longestCommonSubsequence(nums, numsNew);
    }

    public int longestCommonSubsequence(int[] s1, int[] s2) {
        if (s1 == null || s1.length == 0 || s2 == null || s2.length == 0) return 0;
        int length1 = s1.length;
        int length2 = s2.length;
        int[][] dp = new int[length1 + 1][length2 + 1];
        for (int i = 1; i < length1 + 1; i++) {
            for (int j = 1; j < length2 + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }

        }
        return dp[length1][length2];
    }

    /*
    动态规划法：关键是求解子问题
     */
    public int lengthOfLIS2(int[] nums) {
        if (nums == null) return 0;
        if (nums.length <= 1) return nums.length;

        int[] dp = new int[nums.length];
        dp[0] = 1;
        int max = 1;
        for (int i = 1; i < nums.length; i++) {

            int currentMax = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                } else {
                    dp[i] = Math.max(dp[i], currentMax);
                }
                max = Math.max(dp[i], max);
            }
        }

//        int max = 0;
//        for (int i = 0; i <dp.length ; i++) {
//            if (dp[i]> max){
//                max =  dp[i];
//            }
//        }
//        System.out.println(Arrays.toString(dp));
        return max;
    }

    public static void main(String[] args) {
        _300_LongestIncreasingSubsequence object = new _300_LongestIncreasingSubsequence();
        int[] nums = {10, 9, 2, 5, 3, 4};
        System.out.println(object.lengthOfLIS2(nums));
    }
}
