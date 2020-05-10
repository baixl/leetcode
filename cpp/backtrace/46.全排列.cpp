/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
给定一个没有重复数字的序列，返回其所有可能的全排列。
示例:
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */
class Solution {
   public:
	// 方法1：  递归， 使用vistied数组保持是否已访问
	vector<vector<int>> permute2(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> out, visited(nums.size(), 0);
		dfs(nums, 0, visited, out, res);
		return res;
	}
	void dfs(vector<int>& nums, int level, vector<int>& visited,
			 vector<int>& out, vector<vector<int>>& res) {
		if (level == nums.size()) {
			res.push_back(out);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (visited[i] == 1) {
				continue;
			}
			visited[i] = 1;
			out.push_back(nums[i]);
			dfs(nums, level + 1, visited, out, res);
			out.pop_back();  // 递归后恢复现场，用于下一个数字计算
			visited[i] = 0;
		}
	}

	// 方法2：插空法 思路：

	// 当n=1时，数组中只有一个数a1，其全排列只有一种，即为a1
	// 当n=2时，数组中此时有a1a2，其全排列有两种，a1a2和a2a1，那么此时我们考虑和上面那种情况的关系，我们发现，其实就是在a1的前后两个位置分别加入了a2
	// 当n=3时，数组中有a1a2a3，此时全排列有六种，分别为a1a2a3, a1a3a2, a2a1a3,
	// a2a3a1, a3a1a2, 和
	// a3a2a1。那么根据上面的结论，实际上是在a1a2和a2a1的基础上在不同的位置上加入a3而得到的。
	// _ a1 _ a2 _ : a3a1a2, a1a3a2, a1a2a3
	// _ a2 _ a1 _ : a3a2a1, a2a3a1, a2a1a3

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0) return res;

		vector<int> first;
		first.push_back(nums[0]);
		res.push_back(first);

		//依次添加元素num[i]
		for (int i = 1; i < nums.size(); i++) {
			vector<vector<int>> newRet;
			//处理上一个结果集合
			for (int j = 0; j < res.size(); j++) {
				vector<int> cur(res[j]);
				for (int k = 0; k < cur.size() + 1; k++) {
					vector<int> item(cur);
					item.insert(item.begin() + k, nums[i]);
					newRet.push_back(item);
				}
			}
			res = newRet;
		}

		return res;
	}
};
