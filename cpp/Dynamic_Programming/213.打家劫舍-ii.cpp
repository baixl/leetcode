/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
示例 1:
输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）,
因为他们是相邻的。 示例 2: 输入: [1,2,3,1] 输出: 4 解释: 你可以先偷窃 1
号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。 偷窃到的最高金额 = 1 + 3 = 4
。
 */
class Solution {
   public:
	// 动态规划， 和打家劫舍1 不同的是，这里首尾是相连的。
	// 拆成两个动态规划数组， 1、从第1个位置到倒数第2个位置。
	// 2、从第2个位置到最后一个位置
	int rob(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		} else if (nums.size() == 1) {
			return nums[0];
		} else if (nums.size() == 2) {
			return max(nums[0], nums[1]);
		}

		vector<int> dp1(nums.size() - 1, 0);  // 0到 nums.size() - 2
		vector<int> dp2(nums.size() - 1, 0);  // 1到 nums.size() - 1
		dp1[0] = nums[0];
		dp1[1] = max(nums[0], nums[1]);

		for (auto i = 2; i < nums.size() - 1; i++) {
			dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
		}

		dp2[0] = nums[1];
		dp2[1] = max(nums[1], nums[2]);
		for (auto i = 3; i < nums.size(); i++) {
			dp2[i - 1] = max(dp2[i - 3] + nums[i], dp2[i - 2]);
		}
		return max(dp1[nums.size() - 2], dp2[nums.size() - 2]);
	}
};
