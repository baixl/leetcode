/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 *
 * https://leetcode-cn.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (38.63%)
 * Likes:    549
 * Dislikes: 0
 * Total Accepted:    79.1K
 * Total Submissions: 204.7K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 判断你是否能够到达最后一个位置。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,1,1,4]
 * 输出: true
 * 解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,1,0,4]
 * 输出: false
 * 解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
	// 动态规划， 超时， 时间复杂度，o(n2)
	bool canJump2(vector<int>& nums) {
		if (nums.empty()) {
			return false;
		}
		vector<bool> vec(nums.size(), false);
		vec[0] = true;
		for (auto i = 1; i < nums.size(); i++) {
			for (auto j = 0; j < i; j++) {
				if (vec[j] && j + nums[j] >= i) {
					vec[i] = true;
					break;
				}
			}
		}

		return vec[nums.size() - 1];
	}

	// 贪心算法
	// 1、定义变量 farIndex：为当前能到达最右侧的最大索引
	bool canJump(vector<int>& nums) {
		if (nums.empty()) {
			return false;
		}

		int size = nums.size();
		int farIndex = 0;
		for (auto i = 0; i < size; i++) {
			if (farIndex < i) {
				return false;
			}
			if (farIndex >= size - 1) {
				return true;
			}
			farIndex = max(nums[i] + i, farIndex);
		}

		return false;
	}
};
// @lc code=end

