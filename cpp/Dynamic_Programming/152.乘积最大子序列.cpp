/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 给定一个整数数组 nums
，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。 示例 1: 输入:
[2,3,-2,4] 输出: 6 解释: 子数组 [2,3] 有最大乘积 6。 示例 2: 输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 */
#include <vector>
class Solution {
   public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		if (nums.size() == 1) {
			return nums[0];
		}
		int pos = nums[0];     // 正的最大值
		int neg = nums[0];     // 负的最大值
		int result = nums[0];  // 返回结果

		// 可能存在负数
		for (auto i = 1; i < nums.size(); i++) {
			int last_pos = pos;
			int last_neg = neg;
			pos = max(nums[i], max(last_pos * nums[i], last_neg * nums[i]));
			// 由于存在负数，还需要保留当前的最小值，因为负数
			// 乘以一个负数，可能就变成最大值了
			neg = min(nums[i], min(last_pos * nums[i], last_neg * nums[i]));

			result = max(pos, result);
		}
		return result;
	}
};
