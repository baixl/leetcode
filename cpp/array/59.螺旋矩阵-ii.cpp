/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 * Medium (74.84%)
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 示例:
 * 输入: 3
 * 输出:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 *
 */
class Solution {
   public:
    // 和54 螺旋矩阵1相似， 依次从左到右，从上到下， 从右到左，从下到上打印即可
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int r1 = 0, r2 = n - 1, c1 = 0, c2 = n - 1;
        int index = 1;
        while (r1 <= r2 && c1 <= c2) {
            for (auto c = c1; c <= c2; c++) {
                res[r1][c] = index++;
            }

            for (auto r = r1 + 1; r <= r2; r++) {
                res[r][c2] = index++;
            }
            for (auto c = c2 - 1; c >= c1; c--) {
                res[r2][c] = index++;
            }
            for (auto r = r2 - 1; r > r1; r--) {
                res[r][c1] = index++;
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return res;
    }
};
