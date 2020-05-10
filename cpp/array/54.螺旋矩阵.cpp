/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * [54] 螺旋矩阵
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 * Medium (37.09%)
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 示例 1:
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 示例 2:
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 */
class Solution {
   public:
    /*
    <剑指offer>第22题：
    逐层打印即可

    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int row = matrix.size();  // 行数
        int column = matrix[0].size();
        int r1 = 0, r2 = row - 1;
        int c1 = 0, c2 = column - 1;
        while (r1 <= r2 && c1 <= c2) {
            for (auto c = c1; c <= c2; c++) {  // 从左到右
                res.push_back(matrix[r1][c]);
            }
            for (auto r = r1 + 1; r <= r2; r++) {  // 从上到下
                res.push_back(matrix[r][c2]);
            }
            if (r1 < r2) {  // 加这个条件，是避免最后中间只剩下一行，上面从左到右已经遍历能这一行
                for (auto c = c2 - 1; c >= c1; c--) {  // 从右向左
                    res.push_back(matrix[r2][c]);
                }
            }
            if (c1 < c2) {                            // 同上，避免只有一列的情况
                for (auto r = r2 - 1; r > r1; r--) {  // 下向上
                    res.push_back(matrix[r][c1]);
                }
            }

            r1++;
            r2--;
            c1++;
            c2--;
            cout << r1 << " " << r2 << " " << c1 << " " << c2;
        }
        return res;
    }
};
