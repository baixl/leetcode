/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
class Solution {
   public:
    // 动态规划：dp[i]表示跳到第i阶时花费的代价，
    // 最后爬完楼梯花费代价是dp[n]，注意不是n-1，因为需要爬完整个楼梯
    //状态转移方程：dp[i] = min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1])
    //因为i阶要么从i-1跳过来，要么从i-2跳到i
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() <= 2) {
            return 0;
        }
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        for (auto i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};
