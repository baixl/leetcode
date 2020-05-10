/*
 * @lc app=leetcode.cn id=118 lang=cpp
 https://leetcode-cn.com/problems/pascals-triangle/
 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * [118] 杨辉三角
 */
class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows <= 0) {
            return result;
        }

        for (auto i = 1; i <= numRows; i++) {
            vector<int> cur_vec;
            for (auto j = 0; j < i; j++) {
                if (j == 0 || j == i - 1) {
                    cur_vec.push_back(1);
                } else {
                    vector<int> last_vec = result[result.size() - 1];
                    cur_vec.push_back(last_vec[j - 1] + last_vec[j]);
                }
            }
            result.push_back(cur_vec);
        }
        return result;
    }
};
