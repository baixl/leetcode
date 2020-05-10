/*
 * @lc app=leetcode.cn id=74 lang=cpp
 * [74] 搜索二维矩阵
 * https://leetcode-cn.com/problems/search-a-2d-matrix/description/
 * Medium (35.91%)
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 * 示例 1:
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * 输出: true
 * 示例 2:
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * 输出: false
 *
 */
class Solution {
   public:
    // 二分查找的变形， 主要是区分mid节点的位置即可
    int row = 0, column = 0;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        row = matrix.size();        //行数
        column = matrix[0].size();  // 列数
        return binary_search(matrix, target, 0, row * column - 1);
    }

    bool binary_search(vector<vector<int>>& matrix, int target, int left, int right) {
        if (left > right) return false;
        if (left == right && matrix[left / column][left % column] == target) return true;
        
        int mid = left + (right - left);
        int i = mid / column;
        int j = mid % column;
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        return binary_search(matrix, target, left, right);
    }
};
