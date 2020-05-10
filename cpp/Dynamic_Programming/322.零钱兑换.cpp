/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
class Solution {
   public:
	// 动态规划， 定义dp数组，数组长度是 amount， int dp[amount]
	// 数组下标表示金额， 数组的值表示达到该金额的最少硬币数
	int coinChange(vector<int>& coins, int amount) {
		if (amount <= 0 || coins.empty()) {
			return 0;
		}
		vector<long> dp(amount + 1, INT_MAX);
		dp[0] = 0;  
		for (int i = 1; i <= amount; i++) {
			for (auto& coin : coins) {
				if (i < coin) {
					continue;
				}
				                                      
			}
		}

		if (dp[amount] == INT_MAX) {
			return -1;
		} else {
			return dp[amount];
		}
	}
};
