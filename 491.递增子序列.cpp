/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 *
 * https://leetcode-cn.com/problems/increasing-subsequences/description/
 *
 * Medium (46.34%)
 * 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
 * 示例:
 * 输入: [4, 6, 7, 7]
 * 输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 *
 * 说明:
 * 给定数组的长度不会超过15。
 * 数组中的整数范围是 [-100,100]。
 * 给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
 *
 *
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        vector<int> cur_vec;
        // set<vector<int>> res;
        dfs(nums, 0, cur_vec, res);
        // return vector<vector<int>>(res.begin(), res.end());
        return res;
    }
    void dfs(vector<int>& nums, int start, vector<int>& cur_vec, vector<vector<int>>& res) {
        if (cur_vec.size() >= 2) res.push_back(cur_vec);
        unordered_set<int> s;
        for (auto i = start; i < nums.size(); i++) {
            if (!cur_vec.empty() && nums[i] < cur_vec.back()) {
                continue;
            }
            if (s.find(nums[i]) != s.end()) continue; // 剪枝
            s.insert(nums[i]);
            cur_vec.push_back(nums[i]);
            dfs(nums, i + 1, cur_vec, res);
            cur_vec.pop_back();
        }
    }
};
// @lc code=end
