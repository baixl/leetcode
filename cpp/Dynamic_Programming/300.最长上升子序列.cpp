/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
示例:
输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:
可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 */
class Solution {
   public:
    // 思路： 动态规划
    // dp[i]表示以i结尾的元素的最长上升子序列长度
    //  状态转移方程：
    // dp[i] =  max(dp[i], dp[j]+1) ; (0<=j <i; nums[j] < nums[i])
    // 计算dp[i]时，遍历之前的元素，依次计算dp[i]
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        int result = dp[0];
        for (auto i = 1; i < nums.size(); i++) {
            for (auto j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    result = max(result, dp[i]);
                }
            }
        }
        return result;
    }
};
