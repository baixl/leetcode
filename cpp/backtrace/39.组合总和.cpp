/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates中的数字可以无限制重复被选取。
说明：所有数字（包括 target）都是正整数。解集不能包含重复的组合。
 
示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[[7],
[2,2,3]]
示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:
[[2,2,2,2],
 [2,3,3], 
 [3,5]]
 */
#include <vector>
class Solution {
   public:
	// 回溯法，这里可以重复使用元素， 关键是递归退出条件
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		if (candidates.empty()) {
			return res;
		}
		vector<int> out;
		// sort(candidates.begin(), candidates.end());
		backtrack(candidates, target, 0, out, res);
		return res;
	}
	void backtrack(vector<int>& candidates, int target, int start, vector<int>& out,
				   vector<vector<int>>& res) {
		if (target < 0) { // 递归退出
			return;
		}
		if (target == 0) {
			res.push_back(out);
			return;
		}
		for (auto i = start; i < candidates.size(); i++) {
			out.push_back(candidates[i]);
			// 下一次递归的 开始位置还是start， 这里允许重复元素
			backtrack(candidates, target - candidates[i], i, out, res);
			out.pop_back();
		}
	}
};
