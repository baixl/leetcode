/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
示例:
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
 */
class Solution {
   public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() <= 0) {
			return 0;
		}
		int row = grid.size();        // 行
		int column = grid[0].size();  //列
		vector<vector<int>> dp(row, vector<int>(column, 0));
		dp[0][0] = grid[0][0];
		// 第1列
		for (auto i = 1; i < row; i++) {
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}
		// 第1行
		for (auto i = 1; i < column; i++) {
			dp[0][i] = dp[0][i - 1] + grid[0][i];
		}

		for (auto i = 1; i < row; i++) {
			for (auto j = 1; j < column; j++) {
				dp[i][j] =
					min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
			}
		}

		return dp[row - 1][column - 1];
	}
};
