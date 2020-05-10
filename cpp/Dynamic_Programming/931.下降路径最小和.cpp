/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */
#include <vector>
class Solution {
   public:
	// 动态规划， 每个位置 只能是上一行 最多相差一列的值下降
	int minFallingPathSum(vector<vector<int>>& A) {
		if (A.empty()) {
			return 0;
		}

		int row = A.size();
		int column = A[0].size();

		vector<vector<int>> dp(row, vector<int>(column, INT_MAX));
		for (auto i = 0; i < column; i++) {
			dp[0][i] = A[0][i];
		}

		for (auto i = 1; i < row; i++) {
			for (auto j = 0; j < column; j++) {
				if (j == 0) {
					if (j + 1 < column) {
						dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + A[i][j];
					} else {
						dp[i][j] = dp[i - 1][j] + A[i][j];
					}
				} else if (j == column - 1) {
					if (j - 1 >= 0) {
						dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + A[i][j];
					} else {
						dp[i][j] = dp[i - 1][j] + A[i][j];
					}

				} else {
					int min_temp = min(dp[i - 1][j - 1], dp[i - 1][j + 1]);
					dp[i][j] = min(dp[i - 1][j], min_temp) + A[i][j];
				}
			}
		}
		int result = INT_MAX;
		for (auto j = 0; j < column; j++) {
			cout << dp[row - 1][j] << "  ";
			result = min(dp[row - 1][j], result);
		}
		return result;
	}
};
