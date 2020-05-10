/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
示例:
输入:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4
 */
class Solution {
   public:
    /*动态规划*/
    /*
    1、关键： 找到以某个1 为右下角的正方形的边长
    2、假设某个右下角的点为正方形的右下角，则其左、左上、上应该都是正方形，否则右下角就只有自己构成正方形。
    3、该点为右下角的正方形的最大边长，最多比它的上方，左方和左上方为右下角的正方形的边长多1，
    4、最好的情况是是它的上方，左方和左上方为右下角的正方形的大小都一样的，这样加上该点就可以构成一个更大的正方形。
    但如果它的上方，左方和左上方为右下角的正方形的大小不一样，合起来就会缺了某个角落，
    这时候只能取那三个正方形中最小的正方形的边长加1了。

    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
    */
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        // 第1列
        int result = 0;
        for (auto i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                result = 1;
            }
        }

        // 第1行
        for (auto i = 0; i < matrix[0].size(); i++) {
            if (matrix[0][i] == '1') {
                dp[0][i] = 1;
                result = 1;
            }
        }

        for (auto i = 1; i < matrix.size(); i++) {
            for (auto j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    int min1 = min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = min(min1, dp[i - 1][j - 1]) + 1;
                    result = max(dp[i][j], result);
                }
            }
        }


        return result * result;
    }
};
