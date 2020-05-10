/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 * https://leetcode-cn.com/problems/combination-sum-iii/description/
 *
 * Medium (68.69%)
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 * 说明：
 *
 * 所有数字都是正整数。
 * 解集不能包含重复的组合。 
 *
 * 示例 1:
 *
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 *
 * 示例 2:
 *
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 *
 */
class Solution {
   public:
    /*
    回溯法
    */
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k <= 0 || n <= 0) return res;
        vector<int> out;
        back_trace(k,n, 1, 0, 0, out);
        return res;
    }
    void back_trace(int k, int n, int index, int sum, int count, vector<int>& out) {
        if (count == k && sum == n) {
            res.push_back(out);
            return;
        }
        if (count >= k) {
            return;
        }
        for (auto i = index; i < 10; i++) {
            if (sum +i <=n) {
                out.push_back(i);
                back_trace(k, n, i+1, sum +i, count+1, out);
                out.pop_back();
            }
        }

    }
};
