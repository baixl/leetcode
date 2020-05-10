/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */
class Solution {
   public:
	// 递归，回溯， 当遇到重复元素时，需要剪枝
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> out, visited(nums.size(), 0);
		sort(nums.begin(), nums.end());  // 先排序，让相同的元素放一块
		dfs(nums, 0, visited, out, res);
		return res;
	}
	void dfs(vector<int>& nums, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
		if (level == nums.size()) {
			res.push_back(out);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (visited[i] == 1) {
				continue;
			}
			// 剪枝条件
			if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) {
				continue;
			}
			visited[i] = 1;
			out.push_back(nums[i]);
			dfs(nums, level + 1, visited, out, res);
			out.pop_back();  // 递归后恢复现场，用于下一个数字计算
			visited[i] = 0;
		}
	}
};
