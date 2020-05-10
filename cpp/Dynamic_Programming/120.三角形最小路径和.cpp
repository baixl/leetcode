/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * Medium (61.77%)
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 *
 * 例如，给定三角形：
 *
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 *
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 说明：
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 *
 */
class Solution {
   public:
    /*
    动态规划： 计算每一行 到达每个位置时的最小路径。
    每次只能移动到下一行同样列以及下一列
    下一行的相邻数字是：triangle[i][j] ==>和它相邻的数字triangle[i+1][j]和triangle[i+1][j+1]。
    不用记录全局的空间，只需记录上一行的最小值即可
    */
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        if (triangle.size() == 1) return triangle[0][0];  //
        int row = triangle.size();                        // 最下面一行的数组长度
        vector<int> pre(row, 0);
        vector<int> cur(row, 0);
        // 从第2行开始
        cur[0] = triangle[0][0] + triangle[1][0];
        cur[1] = triangle[0][0] + triangle[1][1];
        pre = cur;
        for (auto i = 2; i < row; i++) {  // 从第3行开始
            int column = triangle[i].size();
            for (auto j = 0; j < column; j++) {
                int temp = triangle[i][j];
                if (j == 0) {  // 第1列
                    cur[j] =  pre[j] + temp;
                } else if (j == column - 1) {
                    cur[j] = pre[j - 1] + temp;
                } else {
                    cur[j] = min(pre[j - 1] + temp, pre[j] + temp);
                } 
            }

            pre = cur;
        }
        int result = INT_MAX;
        for (auto i = 0; i < cur.size(); i++) {
            result = min(result, cur[i]);
        }
        return result;
    }
};
