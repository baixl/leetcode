/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
class Solution {
public:
 // dp[i]表示组成钱数i的不同方法。
 int change(int amount, vector<int>& coins) {
	  if (amount <=0) {
		 return 1;
	 }
	 if (coins.empty()) {
		 return 0;
	 }

	 vector<int> dp(amount + 1, 0);
	 dp[0] = 1;
	 for (int coin : coins) {
		 for (int i = coin; i <= amount; ++i) {
			 dp[i] += dp[i - coin];
		 }
	 }
	 return dp[amount];
	}
};

