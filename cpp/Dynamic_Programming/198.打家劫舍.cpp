/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// 动态规划， 当前位置的最大值：
// max = max(dp[i-2]+ nums[i], dp[i-1]);
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)  return 0;
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0],nums[1]);
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (auto i = 2; i < size; i++) {
            dp[i] = max(dp[i-2]+ nums[i], dp[i-1]);
        }
        return dp[size-1];
    }
};