/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (59.59%)
 * Likes:    194
 * Dislikes: 0
 * Total Accepted:    28.7K
 * Total Submissions: 48.2K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 *
 * 说明：解集不能包含重复的子集。
 *
 * 示例:
 *
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 *
 */

// @lc code=start
class Solution {
   public:
    // 方法2: 递归
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> out;
        sort(nums.begin(), nums.end());
        helper(nums, 0, out, res);
        return res;
    }
    void helper(vector<int> &nums, int pos, vector<int> &out,
                    vector<vector<int>> &res) {
        res.push_back(out);
        for (int i = pos; i < nums.size(); ++i) {
            // 和上一个数字相同，则跳过
            if (i > pos && nums[i] == nums[i - 1]) {
                continue;
            }
            out.push_back(nums[i]);
            helper(nums, i + 1, out, res);
            out.pop_back();
        }
    }
};

// @lc code=end
