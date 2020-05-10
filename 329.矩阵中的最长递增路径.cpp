/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (40.12%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    10.7K
 * Total Submissions: 26.7K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个整数矩阵，找出最长递增路径的长度。
 *
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
 *
 * 示例 1:
 *
 * 输入: nums =
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ]
 * 输出: 4
 * 解释: 最长递增路径为 [1, 2, 6, 9]。
 *
 * 示例 2:
 *
 * 输入: nums =
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ]
 * 输出: 4
 * 解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 *
 *
 */

// @lc code=start
class Solution {
   public:
    /* 方法3：********************************
       动态规划TODO
   */
    /*************************************************
     * 方法1：
        传统DFS+记忆化搜索，
）      DFS中，遍历时每个位置其实已经存放了每个位置的最长递增路径， dfs中，不需要每个位置都从头开始
    **************************************************/
    int result = 0, row = 0, col = 0;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        if (row == 0) return 0;
        col = matrix[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));  // visited[i][j] 记录了当前位置的最长递增序列的长度

        for (auto i = 0; i < row; i++) {
            for (auto j = 0; j < col; j++) {
                result = max(result, dfs_new(matrix, visited, i, j, INT_MIN));
            }
        }
        return result;
    }

    int dfs_new(vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j, int last_value) {
        if (i < 0 || i >= row || j < 0 || j >= col) return 0;
        int cur_value = matrix[i][j];
        if (cur_value <= last_value) {
            return 0;
        }

        if (visited[i][j] != 0) return visited[i][j];  // 记忆化搜索， 剪枝
        int u, r, l, d;
        u = dfs_new(matrix, visited, i + 1, j, cur_value);
        r = dfs_new(matrix, visited, i - 1, j, cur_value);
        l = dfs_new(matrix, visited, i, j + 1, cur_value);
        d = dfs_new(matrix, visited, i, j - 1, cur_value);
        visited[i][j] = 1 + max(max(u, r), max(l, d));

        return visited[i][j];
    }

    /************************************************* 
     * 方法2：
        传统DFS 会超时

        传统的DFS中， 这个visited矩阵也不需要，因为序列dfs中，就已经保留了已读的关系（逐步增大）
    **************************************************/
    /*
     int longestIncreasingPath2(vector<vector<int>>& matrix) {
         if (matrix.empty() || matrix[0].empty()) return 0;
         row = matrix.size();
         col = matrix[0].size();
         vector<vector<bool>> visited(row, vector<bool>(col, 0));
         int cur_len = 0;
         for (auto i = 0; i < row; i++) {
             for (auto j = 0; j < col; j++) {
                 dfs(matrix, visited, i, j, INT_MIN, 0);
             }
         }
         return result;
     }
     void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j, int last_value, int cur_num) {
         if (i < 0 || i >= row || j < 0 || j >= col || visited[i][j] == true) {
             return;
         }
         if (matrix[i][j] > last_value) {
             cur_num += 1;
             result = max(result, cur_num);
         } else {
             return;
         }
         if (visited[i][j]) return;
         visited[i][j] = true;
         dfs(matrix, visited, i + 1, j, matrix[i][j], cur_num);
         dfs(matrix, visited, i - 1, j, matrix[i][j], cur_num);
         dfs(matrix, visited, i, j + 1, matrix[i][j], cur_num);
         dfs(matrix, visited, i, j - 1, matrix[i][j], cur_num);
         visited[i][j] = false;
     }
     */
};
// @lc code=end
