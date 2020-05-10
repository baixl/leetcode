/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (77.16%)
 * Likes:    533
 * Dislikes: 0
 * Total Accepted:    78.2K
 * Total Submissions: 101.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
class Solution {
   public:
	// 方法1： 遍历
	vector<vector<int>> subsets1(vector<int> &nums) {
		vector<vector<int>> res(1);
		// sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			int size = res.size();
			for (int j = 0; j < size; ++j) {
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
		}
		return res;
	}

	// 方法2: 递归
	vector<vector<int>> subsets(vector<int> &nums) {
		vector<vector<int>> res;
		vector<int> out;
		// sort(nums.begin(), nums.end());
		helper(nums, 0, out, res);
		return res;
	}
	void helper(vector<int> &nums, int pos, vector<int> &out,
					vector<vector<int>> &res) {
		res.push_back(out);
		for (int i = pos; i < nums.size(); ++i) {
			out.push_back(nums[i]);
			helper(nums, i + 1, out, res);
			out.pop_back();
		}
	}
};

// @lc code=end

