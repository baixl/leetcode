/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间

给出一个区间的集合，请合并所有重叠的区间。
示例 1:
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 */
#include <vector>
class Solution {
   public:
	// 按照区间的第1个元素排序
	static bool compare(vector<int> a, vector<int> b) {
		if (a.size() != 2 || b.size() != 2) {
			return false;
		}
		return a[0] < b[0];
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() <= 1) {
			return intervals;
		}

		sort(intervals.begin(), intervals.end(), compare);
		vector<vector<int>> res;
		vector<int> pre = intervals[0];

		for (auto i = 1; i < intervals.size(); i++) {
			vector<int> cur = intervals[i];
			if (pre[1] < cur[0]) {
				res.push_back(pre);
				pre= cur;
			} else {
				pre[1] =max(pre[1], cur[1]); // 更新区间的结尾 
			}
		}

		res.push_back(pre);
		return res;
	}
};
