/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 *
 * https://leetcode-cn.com/problems/range-sum-query-2d-immutable/description/
 * Medium (40.85%)
 * 给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。
 *
 *
 * 上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。
 *
 * 示例:
 *
 * 给定 matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 *
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 *
 *
 * 说明:
 *
 *
 * 你可以假设矩阵不可变。
 * 会多次调用 sumRegion 方法。
 * 你可以假设 row1 ≤ row2 且 col1 ≤ col2。
 *
 *
 */

// @lc code=start
class NumMatrix {
   public:
    /*
    方法1， 暴力解法 每一次都使用一个双重循环，
    方法2：缓存累积和，
     1、数组dp和matrix大小一致， dp[i][j]表示 从左上角远点[0][0]到[i][j]区域的元素总和
     2、 sumRegion(int row1, int col1, int row2, int col2)
     sum = dp[row2][col2] -dp[row1-1][col2] -dp[row2][col1-1] +  dp[row1-1][col1-1]
     注意当下标<0时， dp==0
    */
    vector<vector<int>> dp;

    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        
        int row = matrix.size();
        int col = matrix[0].size();
        dp = vector<vector<int>>(row, vector<int>(col, 0));

        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < col; j++) {
                int val = matrix[i][j];
                if (i == 0 && j == 0) {
                    dp[i][j] = val;
                } else if (i == 0) {
                    dp[0][j] = dp[0][j - 1] + val;
                } else if (j == 0) {
                    dp[i][0] = dp[i - 1][0] + val;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + val;
                }
            }
        }
    }
    // 方法2： 动态规划
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        if (row1 == 0 && col1 == 0) {
            res = dp[row2][col2];
        } else if (row1 == 0) {
            res = dp[row2][col2] - dp[row2][col1 - 1];
        } else if (col1 == 0) {
            res = dp[row2][col2] - dp[row1 - 1][col2];
        } else {
            res = dp[row2][col2] - dp[row2][col1 - 1] - dp[row1 - 1][col2] + dp[row1 - 1][col1 - 1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
