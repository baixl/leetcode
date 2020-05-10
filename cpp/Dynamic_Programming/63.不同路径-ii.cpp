/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty()) {
			return 0;
		}

		int row  = obstacleGrid.size();
		int column = obstacleGrid[0].size();
		if (obstacleGrid[0][0] == 1) {
			return 0;
		}
		long dp[row][column];
		dp[0][0] = 1;
		// 第1行初始化
		for (int i = 1; i < column; i++) {
			if (obstacleGrid[0][i]==1) {
				dp[0][i] =0;
			} else {
				if (dp[0][i-1] ==1) {
					dp[0][i] =1;
				} else {
					dp[0][i] = 0;
				}
			}
		}
		// 第1列初始化
		for (int i = 1; i < row; i++) {
			if (obstacleGrid[i][0]==1) {
				dp[i][0] =0;
			} else {
				if (dp[i-1][0] ==1) {
					dp[i][0] =1;
				} else {
					dp[i][0] = 0;
				}
			}
		}

		for (int i = 1; i < row; i++) {
			for (int j = 1; j < column; j++) {
				if (obstacleGrid[i][j] ==1) {
					dp[i][j] = 0;
				}else {
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
				}
				
			}
		}
		return dp[row-1][column-1];
	}
};

