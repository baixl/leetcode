/*
 * @lc app=leetcode.cn id=73 lang=cpp
 * [73] 矩阵置零
 * https://leetcode-cn.com/problems/set-matrix-zeroes/description/
 * 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 * 示例 1:
 * 输入:
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * 输出:
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 *
 * 示例 2:
 * 输入:
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * 输出:
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 进阶:
 * 一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个常数空间的解决方案吗？
 *
 *
 */
class Solution {
   public:
    /*
    方法1： 使用数组[m][n]依次记录，每一个元素是否为0， 然后遍历二维矩阵
    方法2：优化空间到O(m+n), 依次使用x[m] 和y[n]记录每一行是否需要被置为0

    方法3： 常数空间
     */
    // 先用方法2实现
    void setZeroes2(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size();     // 行数
        int n = matrix[0].size();  // 列数
        vector<int> row_vec(m, 0);
        vector<int> column_vec(n, 0);
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row_vec[i] = 1;
                    column_vec[j] = 1;
                }
            }
        }
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (row_vec[i] == 1 || column_vec[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
    // 方法3： 使用常数空间实现
    // 将第1行 第1列作为标志位，来标记当前行/列（除开第1行 第1列）是否有0
    // 注意需要标记第1行 、第1列是否有0
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size();               // 行数
        int n = matrix[0].size();            // 列数
        bool column0 = false, row0 = false;  // 第1列 第1行书否包含0
        for (auto i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                column0 = true;
                break;
            }
        }
        for (auto i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                row0 = true;
                break;
            }
        }

        for (auto i = 1; i < m; i++) {
            for (auto j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        // 置0
        for (auto i = 1; i < m; i++) {
            for (auto j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (column0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        return;
    }
};
