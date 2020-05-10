/*
 * @lc app=leetcode.cn id=31 lang=cpp
 * [31] 下一个排列
 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。
以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
 */
#include <vector>
class Solution {
   public:
	// https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode/
	// 思路： 从后往前遍历，找到一个数字,
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) {
			return;
		}
		int i = nums.size() - 2;
		// 1、从后往前遍历，先找到一个下降的数字
		while (i >= 0 && nums[i] >= nums[i + 1]) {
			i--;
		}
		// 找到一个 比目标值刚大的元素
		if (i >= 0) {
			int j = nums.size() - 1;
			while (j > 0 && nums[j] <= nums[i]) {
				j--;
			}
			swap(nums[i], nums[j]);
		}
		reverse(nums, i + 1); // 将i+1到末尾的元素排城递增，由于这一部分是递减排的，只需要反转即可
	}
	void reverse(vector<int>& nums, int start) {
		int i = start, j = nums.size() - 1;
		while (i < j) {
			swap(nums[i], nums[j]);
			i++;
			j--;
		}
	}
};
